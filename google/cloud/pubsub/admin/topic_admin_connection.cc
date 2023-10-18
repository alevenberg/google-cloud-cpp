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

#include "google/cloud/pubsub/admin/topic_admin_connection.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/pubsub/admin/internal/topic_admin_connection_impl.h"
#include "google/cloud/pubsub/admin/internal/topic_admin_option_defaults.h"
#include "google/cloud/pubsub/admin/internal/topic_admin_stub_factory.h"
#include "google/cloud/pubsub/admin/internal/topic_admin_tracing_connection.h"
#include "google/cloud/pubsub/admin/topic_admin_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_admin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TopicAdminConnection::~TopicAdminConnection() = default;

StatusOr<google::pubsub::v1::Topic>
TopicAdminConnection::CreateTopic(
    google::pubsub::v1::Topic const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::pubsub::v1::Topic>
TopicAdminConnection::UpdateTopic(
    google::pubsub::v1::UpdateTopicRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::pubsub::v1::Topic>
TopicAdminConnection::GetTopic(
    google::pubsub::v1::GetTopicRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::pubsub::v1::Topic> TopicAdminConnection::ListTopics(
    google::pubsub::v1::ListTopicsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::pubsub::v1::Topic>>();
}

StreamRange<std::string> TopicAdminConnection::ListTopicSubscriptions(
    google::pubsub::v1::ListTopicSubscriptionsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<std::string>>();
}

StreamRange<std::string> TopicAdminConnection::ListTopicSnapshots(
    google::pubsub::v1::ListTopicSnapshotsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<std::string>>();
}

Status
TopicAdminConnection::DeleteTopic(
    google::pubsub::v1::DeleteTopicRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::pubsub::v1::DetachSubscriptionResponse>
TopicAdminConnection::DetachSubscription(
    google::pubsub::v1::DetachSubscriptionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<TopicAdminConnection> MakeTopicAdminConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
      UnifiedCredentialsOptionList,
      TopicAdminPolicyOptionList>(options, __func__);
  options = pubsub_admin_internal::TopicAdminDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = pubsub_admin_internal::CreateDefaultTopicAdminStub(
    background->cq(), options);
  return pubsub_admin_internal::MakeTopicAdminTracingConnection(
      std::make_shared<pubsub_admin_internal::TopicAdminConnectionImpl>(
      std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_admin
}  // namespace cloud
}  // namespace google
