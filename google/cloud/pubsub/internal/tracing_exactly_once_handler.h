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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_PULL_ACK_HANDLER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_PULL_ACK_HANDLER_H

#include "google/cloud/pubsub/exactly_once_ack_handler.h"
#include "google/cloud/pubsub/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingPullAckHandler : public pubsub::PullAckHandler::Impl {
 public:
  explicit TracingPullAckHandler(
      std::unique_ptr<pubsub::PullAckHandler::Impl> child)
      : child_(std::move(child)) {
    consumer_span_context_ =
        opentelemetry::trace::GetSpan(
            opentelemetry::context::RuntimeContext::GetCurrent())
            ->GetContext();
  }
  ~TracingPullAckHandler() override = default;

  TracingAttributes MakeSharedAttributes(std::string const& ack_id,
                                         std::string const& subscription) {
    namespace sc = opentelemetry::trace::SemanticConventions;
    return TracingAttributes{
        {sc::kMessagingSystem, "gcp_pubsub"},
        {sc::kMessagingOperation, "settle"},
        {"messaging.gcp_pubsub.message.ack_id", ack_id},
        {"messaging.gcp_pubsub.message.delivery_attempt",
         child_->delivery_attempt()},
        {"messaging.gcp_pubsub.subscription.template", subscription}};
  }

  future<Status> ack() override {
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kClient;
    auto const ack_id = child_->ack_id();
    auto const subscription = child_->subscription();
    auto const subscription_name = subscription.FullName();
    TracingAttributes attributes =
        MakeSharedAttributes(ack_id, subscription_name);
    attributes.emplace_back(
        std::make_pair(sc::kCodeFunction, "pubsub::PullAckHandler::ack"));
    auto span = internal::MakeSpan(
        subscription.subscription_id() + " settle", attributes,
        CreateLinks(consumer_span_context_), options);
    MaybeAddLinkAttributes(*span, consumer_span_context_, "receive");
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
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kClient;
    auto const ack_id = child_->ack_id();
    auto const subscription = child_->subscription();
    auto const subscription_name = subscription.FullName();
    TracingAttributes attributes =
        MakeSharedAttributes(ack_id, subscription_name);
    attributes.emplace_back(
        std::make_pair(sc::kCodeFunction, "pubsub::PullAckHandler::nack"));
    auto span = internal::MakeSpan(
        subscription.subscription_id() + " settle", attributes,
        CreateLinks(consumer_span_context_), options);
    MaybeAddLinkAttributes(*span, consumer_span_context_, "receive");
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
  std::unique_ptr<pubsub::PullAckHandler::Impl> child_;
  opentelemetry::trace::SpanContext consumer_span_context_ =
      opentelemetry::trace::SpanContext::GetInvalid();
};


GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_PULL_ACK_HANDLER_H
