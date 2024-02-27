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

// opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> StartLeaseSpan(
//     std::string const& ack_id) {
//   auto const& current = internal::CurrentOptions();
//   auto const& subscription = current.get<pubsub::SubscriptionOption>();
//   namespace sc = opentelemetry::trace::SemanticConventions;
//   opentelemetry::trace::StartSpanOptions options;
//   options.kind = opentelemetry::trace::SpanKind::kConsumer;
//   auto span =
//       internal::MakeSpan(subscription.subscription_id() + " lease",
//                          {
//                              {sc::kMessagingSystem, "gcp_pubsub"},
//                              {"messaging.gcp_pubsub.message.ack_id", ack_id},
//                          },
//                          options);

//   return span;
// }

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(std::pair<T1, T2> const& p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);

    // Mainly for demonstration purposes, i.e. works but is overly simple
    // In the real world, use sth. like boost.hash_combine
    return h1 ^ h2;
  }
};

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
  // Add an event
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
  void ExtendLeases(
      google::pubsub::v1::ModifyAckDeadlineRequest request) override {
    if (request.ack_ids().empty()) {
      return;
    }
    auto span = internal::MakeSpan(request.subscription() + "modack");
    auto scope = internal::OTelScope(span);
    // use the first id and the ack deadline as the key
    //  ;

    for (auto const& ack_id : request.ack_ids()) {
      {
        std::lock_guard<std::mutex> lk(mu_);
        if (ack_id_by_subscribe_span_.find(ack_id) !=
            ack_id_by_subscribe_span_.end()) {
          auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
          subscribe_span->AddEvent("gl-cpp.modack_start");
        }
      }
    }

    auto key = std::pair<std::string, uint64_t>(request.ack_ids().at(0),
                                                request.ack_deadline_seconds());
    // If it exists, end the span and start a new one?
    // If there is the rare case of sending multiple requests with the same
    // lease management value, what hsould happen?
    if (lease_span_by_ack_id.find(key) != lease_span_by_ack_id.end()) {
      auto lease_span = lease_span_by_ack_id[key];
      lease_span->End();
    }
    // Start spans
    lease_span_by_ack_id[key] = span;
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
  void EndExtendLeases(
      google::pubsub::v1::ModifyAckDeadlineRequest request) override {
    if (request.ack_ids().empty()) {
      return;
    }
    for (auto const& ack_id : request.ack_ids()) {
      {
        std::lock_guard<std::mutex> lk(mu_);
        if (ack_id_by_subscribe_span_.find(ack_id) !=
            ack_id_by_subscribe_span_.end()) {
          auto subscribe_span = ack_id_by_subscribe_span_[ack_id];
          subscribe_span->AddEvent("gl-cpp.modack_end");
        }
      }
    }

    auto key = std::pair<std::string, uint64_t>(request.ack_ids().at(0),
                                                request.ack_deadline_seconds());
    // lease management value, what hsould happen?
    if (lease_span_by_ack_id.find(key) != lease_span_by_ack_id.end()) {
      auto lease_span = lease_span_by_ack_id[key];
      lease_span->End();
    }
  };
  std::shared_ptr<MessageCallback> GetMessageCallback() override {
    return child_->GetMessageCallback();
  }

  // Call the MessageCallback.
  void operator()(MessageCallback::ReceivedMessage m) override {
    // std::cout << "has_ack_id" <<
    // ack_id_by_subscribe_span_.count(m.message.ack_id()) << "\n";
    if (ack_id_by_subscribe_span_.count(m.message.ack_id())) {
      m.subscribe_span = ack_id_by_subscribe_span_[m.message.ack_id()];
    }
    child_->GetMessageCallback()->operator()(m);
  };
  // only add one ack handler, add extend spans, refactor around that
  // Call the MessageCallback.
  void operator()(MessageCallback::MessageAndHandler m) override {
    if (message_id_by_subscribe_span_.count(m.message.message_id())) {
      m.subscribe_span = message_id_by_subscribe_span_[m.message.message_id()];
    }
    child_->GetMessageCallback()->operator()(std::move(m));
  };
  void StartFlowControl(google::pubsub::v1::ReceivedMessage message) override {
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kClient;
    opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> subscribe_span;
    auto message_id = message.message().message_id();
    auto ack_id = message.ack_id();
    // std::cout << "start fc\t" << message_id << "\n";
    if (message_id_by_subscribe_span_.count(message_id)) {
      subscribe_span = message_id_by_subscribe_span_[message_id];
      options.parent = subscribe_span->GetContext();
      auto flow_control_span_ = internal::MakeSpan(
          "subscriber scheduler",
          {{sc::kMessagingSystem, "gcp_pubsub"},
           {sc::kCodeFunction, "pubsub::SubscriptionMessageQueue::Read"}},
          options);
      auto scope = internal::OTelScope(flow_control_span_);
      flow_control[ack_id] = flow_control_span_;
    }
    child_->StartFlowControl(message);
  };

  void EndFlowControl(std::string ack_id) override {
    // std::cout << "end fc\t" << ack_id << "\n";
    if (flow_control.count(ack_id)) {
      auto fc = flow_control[ack_id];
      fc->End();
    }
    child_->EndFlowControl(ack_id);
  };
  std::shared_ptr<BatchCallback> child_;
  std::shared_ptr<opentelemetry::context::propagation::TextMapPropagator>
      propagator_;
  std::mutex mu_;
  std::unordered_map<
      std::string,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      message_id_by_subscribe_span_;  // ABSL_GUARDED_BY(mu_)
  std::unordered_map<
      std::string,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      ack_id_by_subscribe_span_;  // ABSL_GUARDED_BY(mu_)
  std::unordered_map<
      std::pair<std::string, uint64_t>,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>, pair_hash>
      lease_span_by_ack_id;  // ABSL_GUARDED_BY(mu_)
  std::unordered_map<
      std::string,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      flow_control;  // ABSL_GUARDED_BY(mu_)
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_BATCH_CALLBACK_H
