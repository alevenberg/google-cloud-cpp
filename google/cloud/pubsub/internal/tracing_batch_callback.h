// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_BATCH_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_BATCH_CALLBACK_H

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/internal/message_propagator.h"
#include "google/cloud/pubsub/internal/subscribe_data.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/status_or.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span_startoptions.h"
#include <google/pubsub/v1/pubsub.pb.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> StartSubscribeSpan(
    google::pubsub::v1::ReceivedMessage const& message,
    std::shared_ptr<
        opentelemetry::context::propagation::TextMapPropagator> const&
        propagator) {
  auto const& current = internal::CurrentOptions();
  auto const& subscription = current.get<pubsub::SubscriptionOption>();
  namespace sc = opentelemetry::trace::SemanticConventions;
  opentelemetry::trace::StartSpanOptions options;
  options.kind = opentelemetry::trace::SpanKind::kConsumer;
  auto m = pubsub_internal::FromProto(std::move(message.message()));
  auto context = ExtractTraceContext(m, *propagator);
  auto producer_span_context =
      opentelemetry::trace::GetSpan(context)->GetContext();
  if (producer_span_context.IsSampled() && producer_span_context.IsValid()) {
    options.parent = producer_span_context;
  }
  auto span = internal::MakeSpan(
      subscription.subscription_id() + " subscribe",
      {
          {sc::kMessagingSystem, "gcp_pubsub"},
          {sc::kCodeFunction, "pubsub::SubscriberConnection::Subscribe"},
          {sc::kMessagingDestinationTemplate, subscription.FullName()},
          {sc::kMessagingMessageId, m.message_id()},
          {/*sc::kMessagingMessageEnvelopeSize=*/"messaging.message.envelope."
                                                 "size",
           static_cast<std::int64_t>(MessageSize(m))},
          {"messaging.gcp_pubsub.message.ack_id", message.ack_id()},
      },
      options);

  if (!message.message().ordering_key().empty()) {
    span->SetAttribute("messaging.gcp_pubsub.message.ordering_key",
                       message.message().ordering_key());
  }
  return span;
}
}  // namespace

/**
 * Tracing implementation.
 * */
class TracingBatchCallback : public BatchCallback {
 public:
  explicit TracingBatchCallback(std::shared_ptr<BatchCallback> child)
      : child_(std::move(child)),
        propagator_(std::make_shared<
                    opentelemetry::trace::propagation::HttpTraceContext>()) {}
  ~TracingBatchCallback() override = default;

  void operator()(StreamingPullResponse response) override {
    std::vector<opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
        spans;
    if (response.response) {
      for (auto const& message : response.response->received_messages()) {
        auto subscribe_span = StartSubscribeSpan(message, propagator_);
        auto scope = internal::OTelScope(subscribe_span);
        std::lock_guard<std::mutex> lk(mu_);
        {
          spans.push_back(subscribe_span);
          message_id_by_subscribe_span_[message.message().message_id()] =
              subscribe_span;
          ack_id_by_subscribe_span_[message.ack_id()] = subscribe_span;
        }
      }
    }

    child_->operator()(std::move(response));
  };

  void AckMessage(std::string const& ack_id) override {
    {
      std::lock_guard<std::mutex> lk(mu_);
      if (ack_id_by_subscribe_span_.find(ack_id) !=
          ack_id_by_subscribe_span_.end()) {
        auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
        subscribe_span->AddEvent("gl-cpp.ack_start");
      }
    }
  }

  void NackMessage(std::string const& ack_id) override {
    {
      std::lock_guard<std::mutex> lk(mu_);
      if (ack_id_by_subscribe_span_.find(ack_id) !=
          ack_id_by_subscribe_span_.end()) {
        auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
        subscribe_span->AddEvent("gl-cpp.nack_start");
      }
    }
  }
  void BulkNack(std::vector<std::string> ack_ids) override {
    for (auto const& ack_id : ack_ids) {
      std::lock_guard<std::mutex> lk(mu_);
      {
        if (ack_id_by_subscribe_span_.find(ack_id) !=
            ack_id_by_subscribe_span_.end()) {
          auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
          subscribe_span->AddEvent("gl-cpp.bulk_nack_start");
        }
      }
    }
  }
  void ExtendLeases(std::vector<std::string> ack_ids,
                    std::chrono::seconds extension) override {
    for (auto const& ack_id : ack_ids) {
      {
        std::lock_guard<std::mutex> lk(mu_);
        if (ack_id_by_subscribe_span_.find(ack_id) !=
            ack_id_by_subscribe_span_.end()) {
          auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
          subscribe_span->AddEvent("extend lease");
        }
      }
    }
  }

  std::shared_ptr<SubscribeData> GetSubscribeDataFromAckId(
      std::string ack_id) override {
    {
      std::lock_guard<std::mutex> lk(mu_);
      if (ack_id_by_subscribe_span_.find(ack_id) !=
          ack_id_by_subscribe_span_.end()) {
        auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
        return std::make_shared<TracingSubscribeData>(subscribe_span);
      }
    }
    return std::make_shared<NoopSubscribeData>();
  }

  void EndAckMessage(std::string const& ack_id) override {
    {
      std::lock_guard<std::mutex> lk(mu_);
      if (ack_id_by_subscribe_span_.find(ack_id) !=
          ack_id_by_subscribe_span_.end()) {
        auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
        subscribe_span->AddEvent("gl-cpp.ack_end");
        subscribe_span->End();
        ack_id_by_subscribe_span_.erase(ack_id);
      }
    }
  }

  void EndNackMessage(std::string const& ack_id) override {
    std::lock_guard<std::mutex> lk(mu_);
    {
      if (ack_id_by_subscribe_span_.find(ack_id) !=
          ack_id_by_subscribe_span_.end()) {
        auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
        subscribe_span->AddEvent("gl-cpp.nack_end");
        subscribe_span->End();
        ack_id_by_subscribe_span_.erase(ack_id);
      }
    }
  };
  void EndBulkNack(std::vector<std::string> ack_ids) override{};
  void EndExtendLeases(std::vector<std::string> ack_ids,
                       std::chrono::seconds extension) override{};
  std::shared_ptr<MessageCallback> GetMessageCallback(
  ) override {
    return child_->GetMessageCallback();
  }


  void operator()(MessageCallback::ReceivedMessage m) override {
   child_->GetMessageCallback()->operator()(std::move(m));
  };

  std::shared_ptr<BatchCallback> child_;
  std::shared_ptr<opentelemetry::context::propagation::TextMapPropagator>
      propagator_;
  std::mutex mu_;
  std::unordered_map<
      std::string, opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      message_id_by_subscribe_span_;  // ABSL_GUARDED_BY(mu_)
  std::unordered_map<
      std::string, opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      ack_id_by_subscribe_span_;  // ABSL_GUARDED_BY(mu_)
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_BATCH_CALLBACK_H
