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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_MESSAGE_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_MESSAGE_CALLBACK_H

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/internal/message_callback.h"
#include "google/cloud/pubsub/internal/message_propagator.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/status_or.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span_startoptions.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <absl/types/any.h>
#include <absl/types/bad_any_cast.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Tracing implementation.
 * */
class TracingMessageCallback : public MessageCallback {
 public:
  explicit TracingMessageCallback(std::unique_ptr<MessageCallback> child)
      : child_(std::move(child)) {}
  ~TracingMessageCallback() override = default;

  void operator()(
      pubsub::Message m,
      std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> ack) override {
    child_->operator()(std::move(m), std::move(ack));
  };

  void operator()(ReceivedMessage m) override {
    // auto span = StartSchedulerSpan();
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kClient;
    if (batch_callback_) {
      auto data =
          batch_callback_->GetSubscribeDataFromAckId(m.message.ack_id());
      if (data.has_value()) {
        try {
          subscribe_span_ = absl::any_cast<
              opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>>(
              data.value());
          options.parent = subscribe_span_->GetContext();
        } catch (absl::bad_any_cast const& e) {
          std::cerr << "Incorrect type in absl::any: " << e.what() << std::endl;
        }
      }
    }
    auto span = internal::MakeSpan(
        "subscriber flow_control ",
        {{sc::kMessagingSystem, "gcp_pubsub"},
         {sc::kCodeFunction, "pubsub::SubscriptionMessageQueue::Read"}},
        options);
    auto scope = internal::OTelScope(span);
    child_->operator()(std::move(m));
    span->End();
  };

  void SaveBatchCallback(std::shared_ptr<BatchCallback> cb) override {
    batch_callback_ = cb;
  };

  std::shared_ptr<BatchCallback> batch_callback_;
  std::unique_ptr<MessageCallback> child_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> subscribe_span_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_MESSAGE_CALLBACK_H
