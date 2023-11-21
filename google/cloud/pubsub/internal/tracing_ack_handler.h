// Copyright 2020 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_ACK_HANDLER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_ACK_HANDLER_H

#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/status.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include <cstdint>
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingAckHandler : public pubsub::PullAckHandler::Impl {
 public:
  explicit TracingAckHandler(
      std::unique_ptr<pubsub::PullAckHandler::Impl> child,
      pubsub::Subscription subscription, std::string ack_id,
      std::int32_t delivery_attempt)
      : child_(std::move(child)),
        subscription_(std::move(subscription)),
        ack_id_(std::move(ack_id)),
        delivery_attempt_(delivery_attempt) {}
  ~TracingAckHandler() override = default;

  future<Status> ack() override {
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kConsumer;
    auto span = internal::MakeSpan(
        subscription_.subscription_id() + " settle",
        {{sc::kMessagingSystem, "gcp_pubsub"},
         {sc::kMessagingOperation, "settle"},
         {sc::kCodeFunction, "pubsub::PullAckHandler::ack"},
         {"messaging.gcp_pubsub.message.ack_id", ack_id_},
         {"messaging.gcp_pubsub.destination.subscription",
          subscription_.subscription_id()},
               {"messaging.gcp_pubsub.message.delivery_attempt",
        delivery_attempt_},
         {"messaging.gcp_pubsub.destination.subscription.template",
          subscription_.FullName()}},
        options);
    auto scope = opentelemetry::trace::Scope(span);

    return child_->ack().then([span = span](auto f) {
      auto result = f.get();
      return internal::EndSpan(*span, std::move(result));
    });
  }

  future<Status> nack() override {
    namespace sc = opentelemetry::trace::SemanticConventions;
    opentelemetry::trace::StartSpanOptions options;
    options.kind = opentelemetry::trace::SpanKind::kConsumer;
    auto span = internal::MakeSpan(
        subscription_.subscription_id() + " settle",
        {{sc::kMessagingSystem, "gcp_pubsub"},
         {sc::kMessagingOperation, "settle"},
         {sc::kCodeFunction, "pubsub::PullAckHandler::nack"},
         {"messaging.gcp_pubsub.destination.subscription",
          subscription_.subscription_id()},
         {"messaging.gcp_pubsub.destination.subscription.template",
          subscription_.FullName()}},
        options);
    auto scope = opentelemetry::trace::Scope(span);
    return child_->nack().then([span = span](auto f) {
      auto result = f.get();
      return internal::EndSpan(*span, std::move(result));
    });
  }

  std::int32_t delivery_attempt() const override {
    return child_->delivery_attempt();
  }

 private:
  std::unique_ptr<pubsub::PullAckHandler::Impl> child_;
  pubsub::Subscription subscription_;
  std::string ack_id_;
  std::int32_t delivery_attempt_;
};

std::unique_ptr<pubsub::PullAckHandler::Impl> MakeTracingAckHandler(
    std::unique_ptr<pubsub::PullAckHandler::Impl> handler,
    pubsub::Subscription subscription, std::string ack_id,
    std::int32_t delivery_attempt) {
  return std::make_unique<TracingAckHandler>(
      std::move(handler), std::move(subscription), std::move(ack_id),
      (delivery_attempt));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_ACK_HANDLER_H
