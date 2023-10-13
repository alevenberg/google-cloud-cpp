// Copyright 2023 Google LLC
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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/pubsub/v1/pubsub.proto

#include "google/cloud/pubsub/v1/internal/subscriber_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

SubscriberTracingConnection::SubscriberTracingConnection(
    std::shared_ptr<pubsub_v1::SubscriberConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::pubsub::v1::Subscription>
SubscriberTracingConnection::CreateSubscription(google::pubsub::v1::Subscription const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::CreateSubscription");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateSubscription(request));
}

StatusOr<google::pubsub::v1::Subscription>
SubscriberTracingConnection::GetSubscription(google::pubsub::v1::GetSubscriptionRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::GetSubscription");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetSubscription(request));
}

StatusOr<google::pubsub::v1::Subscription>
SubscriberTracingConnection::UpdateSubscription(google::pubsub::v1::UpdateSubscriptionRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::UpdateSubscription");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateSubscription(request));
}

StreamRange<google::pubsub::v1::Subscription>
SubscriberTracingConnection::ListSubscriptions(google::pubsub::v1::ListSubscriptionsRequest request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::ListSubscriptions");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListSubscriptions(std::move(request));
  return internal::MakeTracedStreamRange<google::pubsub::v1::Subscription>(
        std::move(span), std::move(sr));
}

Status
SubscriberTracingConnection::DeleteSubscription(google::pubsub::v1::DeleteSubscriptionRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::DeleteSubscription");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteSubscription(request));
}

StatusOr<google::pubsub::v1::PullResponse>
SubscriberTracingConnection::Pull(google::pubsub::v1::PullRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::Pull");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->Pull(request));
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
    google::pubsub::v1::StreamingPullRequest,
    google::pubsub::v1::StreamingPullResponse>>
SubscriberTracingConnection::AsyncStreamingPull() {
  return child_->AsyncStreamingPull();
}

Status
SubscriberTracingConnection::ModifyPushConfig(google::pubsub::v1::ModifyPushConfigRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::ModifyPushConfig");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ModifyPushConfig(request));
}

StatusOr<google::pubsub::v1::Snapshot>
SubscriberTracingConnection::GetSnapshot(google::pubsub::v1::GetSnapshotRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::GetSnapshot");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetSnapshot(request));
}

StreamRange<google::pubsub::v1::Snapshot>
SubscriberTracingConnection::ListSnapshots(google::pubsub::v1::ListSnapshotsRequest request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::ListSnapshots");
  auto scope = opentelemetry::trace::Scope(span);
  auto sr = child_->ListSnapshots(std::move(request));
  return internal::MakeTracedStreamRange<google::pubsub::v1::Snapshot>(
        std::move(span), std::move(sr));
}

StatusOr<google::pubsub::v1::Snapshot>
SubscriberTracingConnection::CreateSnapshot(google::pubsub::v1::CreateSnapshotRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::CreateSnapshot");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateSnapshot(request));
}

StatusOr<google::pubsub::v1::Snapshot>
SubscriberTracingConnection::UpdateSnapshot(google::pubsub::v1::UpdateSnapshotRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::UpdateSnapshot");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateSnapshot(request));
}

Status
SubscriberTracingConnection::DeleteSnapshot(google::pubsub::v1::DeleteSnapshotRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::DeleteSnapshot");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteSnapshot(request));
}

StatusOr<google::pubsub::v1::SeekResponse>
SubscriberTracingConnection::Seek(google::pubsub::v1::SeekRequest const& request) {
  auto span = internal::MakeSpan("pubsub_v1::SubscriberConnection::Seek");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->Seek(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<pubsub_v1::SubscriberConnection>
MakeSubscriberTracingConnection(
    std::shared_ptr<pubsub_v1::SubscriberConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<SubscriberTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_v1_internal
}  // namespace cloud
}  // namespace google
