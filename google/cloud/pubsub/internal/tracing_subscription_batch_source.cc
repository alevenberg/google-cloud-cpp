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

#include "google/cloud/pubsub/internal/tracing_subscription_batch_source.h"
#include "google/cloud/pubsub/internal/exactly_once_policies.h"
#include "google/cloud/pubsub/internal/extend_leases_with_retry.h"
#include "google/cloud/internal/async_retry_loop.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/log.h"
#include <iterator>
#include <ostream>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

// rename; SubscriptionTracingBatchSource
// Add them to a list of ack id -> subscribe span
void TracingSubscriptionBatchSource::Start(BatchCallback callback) {
  auto span = internal::MakeSpan("TracingSubscriptionBatchSource::Start");
  auto scope = internal::OTelScope(span);
  child_->Start([callback, span = std::move(span)](
                    StatusOr<google::pubsub::v1::StreamingPullResponse> r) {
    internal::EndSpan(*span);
    callback(std::move(r));
  });
}

void TracingSubscriptionBatchSource::Shutdown() {
  auto span = internal::MakeSpan("TracingSubscriptionBatchSource::Shutdown");
  child_->Shutdown();

  internal::EndSpan(*span);
}

future<Status> TracingSubscriptionBatchSource::AckMessage(
    std::string const& ack_id) {
  auto span = internal::MakeSpan("TracingSubscriptionBatchSource::AckMessage");
  auto scope = internal::OTelScope(span);
  return child_->AckMessage(ack_id).then([span = std::move(span)](auto f) {
    internal::EndSpan(*span);
    return f;
  });
}

future<Status> TracingSubscriptionBatchSource::NackMessage(
    std::string const& ack_id) {
  auto span = internal::MakeSpan("TracingSubscriptionBatchSource::NackMessage");
  auto scope = internal::OTelScope(span);
  return child_->NackMessage(ack_id).then([span = std::move(span)](auto f) {
    internal::EndSpan(*span);
    return f;
  });
}

future<Status> TracingSubscriptionBatchSource::BulkNack(
    std::vector<std::string> ack_ids) {
  auto span = internal::MakeSpan("TracingSubscriptionBatchSource::BulkNack");
  auto scope = internal::OTelScope(span);
  return child_->BulkNack(ack_ids).then([span = std::move(span)](auto f) {
    internal::EndSpan(*span);
    return f;
  });
}

void TracingSubscriptionBatchSource::ExtendLeases(
    std::vector<std::string> ack_ids, std::chrono::seconds extension) {
  opentelemetry::trace::StartSpanOptions options;
  opentelemetry::context::Context root_context;
  // TODO(#13287): Use the constant instead of the string.
  // Setting a span as a root span was added in OTel v1.13+. It is a no-op
  // for earlier versions.
  options.parent = root_context.SetValue(
      /*opentelemetry::trace::kIsRootSpanKey=*/"is_root_span", true);
  // Go through messages

  auto span = internal::MakeSpan("ExtendLeases::ExtendLeases", options);
  child_->ExtendLeases(ack_ids, extension);
  internal::EndSpan(*span);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
