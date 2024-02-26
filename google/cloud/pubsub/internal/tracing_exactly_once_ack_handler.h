// Copyright 2023 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_EXACTLY_ONCE_ACK_HANDLER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_EXACTLY_ONCE_ACK_HANDLER_H

#include "google/cloud/pubsub/exactly_once_ack_handler.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/status.h"
#include <memory>
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
#include "google/cloud/pubsub/internal/tracing_helpers.h"
#include "opentelemetry/context/runtime_context.h"
#include "opentelemetry/trace/context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span.h"
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
#include <cstdint>
#include <string>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingExactlyOnceAckHandler
    : public pubsub::ExactlyOnceAckHandler::Impl {
 public:
  explicit TracingExactlyOnceAckHandler(
      std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> child,
      opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span>
          subscribe_span)
      : child_(std::move(child)), subscribe_span_(subscribe_span) {}
    using TracingAttributes = std::vector<
        std::pair<opentelemetry::nostd::string_view,
                  opentelemetry::common::AttributeValue>>;  // std::cout <<
                                
  ~TracingExactlyOnceAckHandler() override = default;
  future<Status> ack() override {
                            // "tracing ack\n";
    if (subscribe_span_ != nullptr) {
      subscribe_span_->AddEvent("gl-cpp.message_ack");
    }
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options = RootStartSpanOptions();
    std::vector<std::pair<opentelemetry::trace::SpanContext, TracingAttributes>>
        links;
    if (subscribe_span_ != nullptr) {
      // Create Link
      links = {{subscribe_span_->GetContext(), TracingAttributes{}}};
    }
    options.kind = opentelemetry::trace::SpanKind::kClient;
    auto const ack_id = child_->ack_id();
    auto const subscription = child_->subscription();
    auto span =
        internal::MakeSpan(subscription.subscription_id() + " ack",
                           {{sc::kMessagingSystem, "gcp_pubsub"},
                            {"messaging.gcp_pubsub.message.ack_id", ack_id},
                            {"messaging.gcp_pubsub.subscription.template",
                             subscription.FullName()}},
                           links, options);
    if (subscribe_span_ != nullptr) {
      MaybeAddLinkAttributes(*span, subscribe_span_->GetContext(), "subscribe");
    }
    //   subscribe_span_ != nullptr? CreateLinks(subscribe_span_->GetContext())
    //   : {},
    // MaybeAddLinkAttributes(*span, consumer_span_context_, "receive");
    auto scope = internal::OTelScope(span);

    return child_->ack().then(
        [oc = opentelemetry::context::RuntimeContext::GetCurrent(),
         span = std::move(span)](auto f) {
          auto result = f.get();
          internal::DetachOTelContext(oc);
          return internal::EndSpan(*span, std::move(result));
        });
  }

  future<Status> nack() override {
    subscribe_span_->AddEvent("gl-cpp.message_nack");
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options = RootStartSpanOptions();
    std::vector<std::pair<opentelemetry::trace::SpanContext, TracingAttributes>>
        links;
    if (subscribe_span_ != nullptr) {
        links = {{subscribe_span_->GetContext(), TracingAttributes{}}};
    }
    options.kind = opentelemetry::trace::SpanKind::kClient;
    auto const subscription = child_->subscription();
    auto span = internal::MakeSpan(subscription.subscription_id() + " nack",
                                   {{}}, links, options);
    // MaybeAddLinkAttributes(*span, consumer_span_context_, "receive");
    auto scope = internal::OTelScope(span);

    return child_->nack().then(
        [oc = opentelemetry::context::RuntimeContext::GetCurrent(),
         span = std::move(span)](auto f) {
          auto result = f.get();
          internal::DetachOTelContext(oc);
          return internal::EndSpan(*span, std::move(result));
        });
  }

  std::int32_t delivery_attempt() const override {
    return child_->delivery_attempt();
  }

  std::string ack_id() const override { return child_->ack_id(); }

  pubsub::Subscription subscription() const override {
    return child_->subscription();
  }

 private:
  std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> child_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> subscribe_span_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_EXACTLY_ONCE_ACK_HANDLER_H
