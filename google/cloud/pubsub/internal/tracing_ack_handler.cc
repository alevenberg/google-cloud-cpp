// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/internal/tracing_ack_handler.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/log.h"
#include <opentelemetry/trace/scope.h>
#include <opentelemetry/trace/semantic_conventions.h>
namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

void TracingAckHandler::ack() {
  // namespace sc = opentelemetry::trace::SemanticConventions;
  // opentelemetry::trace::StartSpanOptions options;
  // options.kind = opentelemetry::trace::SpanKind::kClient;
  // auto const& current = internal::CurrentOptions();
  // auto subscription = current.get<pubsub::SubscriptionOption>();
  // auto span = internal::MakeSpan(
  //     subscription.subscription_id() + " ack",
  //     {{sc::kMessagingSystem, "gcp_pubsub"},
  //      {sc::kMessagingOperation, "ack"},
  //      {"messaging.gcp_pubsub.subscription.template", subscription.FullName()}},
  //     options);
  // auto scope = internal::OTelScope(span);
  // auto f = child_->ack();
  // f.then([span = span](auto) { span->End(); });
child_->ack();
}

void TracingAckHandler::nack() {
  // auto span = internal::MakeSpan("nack");
  // auto scope = internal::OTelScope(span);
  // child_->nack().then([span = span](auto) { span->End(); });
child_->nack();
}

std::int32_t TracingAckHandler::delivery_attempt() const {
  return child_->delivery_attempt();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
