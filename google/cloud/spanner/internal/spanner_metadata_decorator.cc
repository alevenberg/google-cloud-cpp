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
// source: google/spanner/v1/spanner.proto

#include "google/cloud/spanner/internal/spanner_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/spanner/v1/spanner.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace spanner_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SpannerMetadata::SpannerMetadata(
    std::shared_ptr<SpannerStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::spanner::v1::Session> SpannerMetadata::CreateSession(
    grpc::ClientContext& context,
    google::spanner::v1::CreateSessionRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("database=", internal::UrlEncode(request.database())));
  return child_->CreateSession(context, request);
}

StatusOr<google::spanner::v1::BatchCreateSessionsResponse>
SpannerMetadata::BatchCreateSessions(
    grpc::ClientContext& context,
    google::spanner::v1::BatchCreateSessionsRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("database=", internal::UrlEncode(request.database())));
  return child_->BatchCreateSessions(context, request);
}

Status SpannerMetadata::DeleteSession(
    grpc::ClientContext& context,
    google::spanner::v1::DeleteSessionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteSession(context, request);
}

StatusOr<google::spanner::v1::ResultSet> SpannerMetadata::ExecuteSql(
    grpc::ClientContext& context,
    google::spanner::v1::ExecuteSqlRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->ExecuteSql(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::spanner::v1::PartialResultSet>>
SpannerMetadata::ExecuteStreamingSql(
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::ExecuteSqlRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->ExecuteStreamingSql(std::move(context), request);
}

StatusOr<google::spanner::v1::ExecuteBatchDmlResponse>
SpannerMetadata::ExecuteBatchDml(
    grpc::ClientContext& context,
    google::spanner::v1::ExecuteBatchDmlRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->ExecuteBatchDml(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::spanner::v1::PartialResultSet>>
SpannerMetadata::StreamingRead(
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::ReadRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->StreamingRead(std::move(context), request);
}

StatusOr<google::spanner::v1::Transaction> SpannerMetadata::BeginTransaction(
    grpc::ClientContext& context,
    google::spanner::v1::BeginTransactionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->BeginTransaction(context, request);
}

StatusOr<google::spanner::v1::CommitResponse> SpannerMetadata::Commit(
    grpc::ClientContext& context,
    google::spanner::v1::CommitRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->Commit(context, request);
}

Status SpannerMetadata::Rollback(
    grpc::ClientContext& context,
    google::spanner::v1::RollbackRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->Rollback(context, request);
}

StatusOr<google::spanner::v1::PartitionResponse>
SpannerMetadata::PartitionQuery(
    grpc::ClientContext& context,
    google::spanner::v1::PartitionQueryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->PartitionQuery(context, request);
}

StatusOr<google::spanner::v1::PartitionResponse> SpannerMetadata::PartitionRead(
    grpc::ClientContext& context,
    google::spanner::v1::PartitionReadRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->PartitionRead(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::spanner::v1::BatchWriteResponse>>
SpannerMetadata::BatchWrite(
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::BatchWriteRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->BatchWrite(std::move(context), request);
}

future<StatusOr<google::spanner::v1::BatchCreateSessionsResponse>>
SpannerMetadata::AsyncBatchCreateSessions(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::BatchCreateSessionsRequest const& request) {
  SetMetadata(
      *context, internal::CurrentOptions(),
      absl::StrCat("database=", internal::UrlEncode(request.database())));
  return child_->AsyncBatchCreateSessions(cq, std::move(context), request);
}

future<Status> SpannerMetadata::AsyncDeleteSession(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::DeleteSessionRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteSession(cq, std::move(context), request);
}

future<StatusOr<google::spanner::v1::ResultSet>>
SpannerMetadata::AsyncExecuteSql(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::spanner::v1::ExecuteSqlRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("session=", internal::UrlEncode(request.session())));
  return child_->AsyncExecuteSql(cq, std::move(context), request);
}

void SpannerMetadata::SetMetadata(grpc::ClientContext& context,
                                  Options const& options,
                                  std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void SpannerMetadata::SetMetadata(grpc::ClientContext& context,
                                  Options const& options) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner_internal
}  // namespace cloud
}  // namespace google
