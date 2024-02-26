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
#include "google/cloud/pubsub/internal/tracing_exactly_once_ack_handler.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/opentelemetry_options.h"
#include "google/cloud/status_or.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span_startoptions.h"
#include <google/pubsub/v1/pubsub.pb.h>
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
  explicit TracingMessageCallback(std::shared_ptr<MessageCallback> child)
      : child_(std::move(child)) {}
  ~TracingMessageCallback() override = default;

  void operator()(MessageAndHandler m) override {
    // std::cout << "tracing message callback";
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    if (m.subscribe_span.has_value()) {
      try {
        auto casted_span = absl::any_cast<
            opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> >(
            m.subscribe_span.value());
        if (casted_span != nullptr) {
          options.parent = casted_span->GetContext();
        }
      } catch (absl::bad_any_cast const& e) {
        std::cout << "Bad any cast: " << e.what() << '\n';
      }
      auto span =
          internal::MakeSpan("user callback",
                             {{sc::kMessagingSystem, "gcp_pubsub"},
                              {sc::kCodeFunction, "pubsub::Concurrency::Read"}},
                             options);
      auto scope = internal::OTelScope(span);
      auto const& current = internal::CurrentOptions();
      auto otel = current.get<OpenTelemetryTracingOption>();
      std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> ack_handler =
          std::move(m.ack_handler);
      if (otel) {
        ack_handler = std::make_unique<TracingExactlyOnceAckHandler>(
            std::move(ack_handler), span);
      }
      m.ack_handler = std::move(ack_handler);
      child_->operator()(std::move(m));
      span->End();
    }
  };

  void operator()(ReceivedMessage m) override {
    // namespace sc = opentelemetry::trace::SemanticConventions;
    // opentelemetry::trace::StartSpanOptions options;
    // options.kind = opentelemetry::trace::SpanKind::kClient;
    // if (m.subscribe_span.has_value()) {
    //   try {
    //     auto casted_span = absl::any_cast<
    //         opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> >(
    //         m.subscribe_span.value());
    //     if (casted_span != nullptr) {
    //       subscribe_span_ =casted_span;
    //       options.parent = subscribe_span_->GetContext();
    //     }
    //   } catch (absl::bad_any_cast const& e) {
    //     std::cout << "Bad any cast: " << e.what() << '\n';
    //   }
    // }
    // auto span = internal::MakeSpan(
    //     "subscriber flow_control ",
    //     {{sc::kMessagingSystem, "gcp_pubsub"},
    //      {sc::kCodeFunction, "pubsub::SubscriptionMessageQueue::Read"}},
    //     options);
    // auto scope = internal::OTelScope(span);
    child_->operator()(std::move(m));
    // span->End();
  };

  void StartFlowControl(ReceivedMessage m) override {
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kClient;
    if (m.subscribe_span.has_value()) {
      try {
        auto casted_span = absl::any_cast<
            opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> >(
            m.subscribe_span.value());
        if (casted_span != nullptr) {
          subscribe_span_ = casted_span;
          options.parent = subscribe_span_->GetContext();
        }
      } catch (absl::bad_any_cast const& e) {
        std::cout << "Bad any cast: " << e.what() << '\n';
      }
    }
    auto flow_control_span_ = internal::MakeSpan(
        "subscriber flow_control ",
        {{sc::kMessagingSystem, "gcp_pubsub"},
         {sc::kCodeFunction, "pubsub::SubscriptionMessageQueue::Read"}},
        options);
    auto scope = internal::OTelScope(flow_control_span_);
    child_->StartFlowControl(std::move(m));
  }

  void EndFlowControl() override {
    if (flow_control_span_ != nullptr) {
      flow_control_span_->End();
    }
  }
  std::shared_ptr<MessageCallback> child_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> subscribe_span_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>
      flow_control_span_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> scheduler_span_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_MESSAGE_CALLBACK_H
