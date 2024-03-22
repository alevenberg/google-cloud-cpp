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

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/subscription.h"
#include "google/cloud/pubsub/version.h"
#ifndef  GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
#include "google/cloud/pubsub/internal/message_propagator.h"
#include "google/cloud/internal/opentelemetry.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span_startoptions.h"
#include <google/pubsub/v1/pubsub.pb.h>
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifndef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

namespace {

opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> StartSubscribeSpan(
    google::pubsub::v1::ReceivedMessage const& message,
    pubsub::Subscription const& subscription,
    std::shared_ptr<
        opentelemetry::context::propagation::TextMapPropagator> const&
        propagator) {
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
  auto span = internal::MakeSpan(subscription.subscription_id() + " subscribe",
                                 options);
  return span;
}

}  // namespace

/**
 * Tracing batch callback implementation.
 * */
class TracingBatchCallback : public BatchCallback {
 public:
  explicit TracingBatchCallback(std::shared_ptr<BatchCallback> child,
                                pubsub::Subscription const& subscription)
      : child_(std::move(child)),
        subscription_(std::move(subscription)),
        propagator_(std::make_shared<
                    opentelemetry::trace::propagation::HttpTraceContext>()) {}
  ~TracingBatchCallback() {
    std::lock_guard<std::mutex> lk(mu_);
    // End all outstanding subscribe spans;
    auto subscribe_span = ack_id_by_subscribe_span_.find(ack_id);
    if (subscribe_span != ack_id_by_subscribe_span_.end()) {
      subscribe_span->End();
      ack_id_by_subscribe_span_.erase(ack_id);
    }
  }

  void callback(BatchCallback::StreamingPullResponse response) override {
    if (response.response) {
      for (auto const& message : response.response->received_messages()) {
        auto subscribe_span = StartSubscribeSpan(message, propagator_);
        auto scope = internal::OTelScope(subscribe_span);
        {
          std::lock_guard<std::mutex> lk(mu_);
          ack_id_by_subscribe_span_[message.ack_id()] = subscribe_span;
        }
      }
    }
    child_->callback(std::move(response));
  };

  void EndMessage(std::string const& ack_id,
                  std::string const& event) override {
    std::lock_guard<std::mutex> lk(mu_);
    // Use the ack_id to find the subscribe span and end it.
    auto subscribe_span = ack_id_by_subscribe_span_.find(ack_id);
    if (subscribe_span != ack_id_by_subscribe_span_.end()) {
      subscribe_span->AddEvent(event);
      subscribe_span->End();
      ack_id_by_subscribe_span_.erase(ack_id);
    }
  }

  std::shared_ptr<BatchCallback> child_;
  std::shared_ptr<opentelemetry::context::propagation::TextMapPropagator>
      propagator_;
  std::mutex mu_;
  std::unordered_map<
      std::string,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>
      subscribe_span_by_ack_id;  // ABSL_GUARDED_BY(mu_)
}

std::shared_ptr<BatchCallback>
MakeTracingBatchCallback(std::shared_ptr<BatchCallback> batch_callback,
                         pubsub::Subscription const& subscription) {
  return std::make_shared<TracingBatchSink>(std::move(batch_callback),
                                            subscription);
}

#else  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<BatchCallback> MakeTracingBatchCallback(
    std::shared_ptr<BatchCallback> batch_callback,
    pubsub::Subscription const&) {
  return batch_callback;
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
