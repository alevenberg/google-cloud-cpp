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
// source: google/logging/v2/logging_config.proto

#include "google/cloud/logging/v2/internal/config_service_v2_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/logging/v2/logging_config.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace logging_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConfigServiceV2Metadata::ConfigServiceV2Metadata(
    std::shared_ptr<ConfigServiceV2Stub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::logging::v2::ListBucketsResponse>
ConfigServiceV2Metadata::ListBuckets(
    grpc::ClientContext& context,
    google::logging::v2::ListBucketsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListBuckets(context, request);
}

StatusOr<google::logging::v2::LogBucket> ConfigServiceV2Metadata::GetBucket(
    grpc::ClientContext& context,
    google::logging::v2::GetBucketRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetBucket(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncCreateBucketAsync(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::CreateBucketRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateBucketAsync(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncUpdateBucketAsync(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::UpdateBucketRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncUpdateBucketAsync(cq, std::move(context), request);
}

StatusOr<google::logging::v2::LogBucket> ConfigServiceV2Metadata::CreateBucket(
    grpc::ClientContext& context,
    google::logging::v2::CreateBucketRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateBucket(context, request);
}

StatusOr<google::logging::v2::LogBucket> ConfigServiceV2Metadata::UpdateBucket(
    grpc::ClientContext& context,
    google::logging::v2::UpdateBucketRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateBucket(context, request);
}

Status ConfigServiceV2Metadata::DeleteBucket(
    grpc::ClientContext& context,
    google::logging::v2::DeleteBucketRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteBucket(context, request);
}

Status ConfigServiceV2Metadata::UndeleteBucket(
    grpc::ClientContext& context,
    google::logging::v2::UndeleteBucketRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UndeleteBucket(context, request);
}

StatusOr<google::logging::v2::ListViewsResponse>
ConfigServiceV2Metadata::ListViews(
    grpc::ClientContext& context,
    google::logging::v2::ListViewsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListViews(context, request);
}

StatusOr<google::logging::v2::LogView> ConfigServiceV2Metadata::GetView(
    grpc::ClientContext& context,
    google::logging::v2::GetViewRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetView(context, request);
}

StatusOr<google::logging::v2::LogView> ConfigServiceV2Metadata::CreateView(
    grpc::ClientContext& context,
    google::logging::v2::CreateViewRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateView(context, request);
}

StatusOr<google::logging::v2::LogView> ConfigServiceV2Metadata::UpdateView(
    grpc::ClientContext& context,
    google::logging::v2::UpdateViewRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateView(context, request);
}

Status ConfigServiceV2Metadata::DeleteView(
    grpc::ClientContext& context,
    google::logging::v2::DeleteViewRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteView(context, request);
}

StatusOr<google::logging::v2::ListSinksResponse>
ConfigServiceV2Metadata::ListSinks(
    grpc::ClientContext& context,
    google::logging::v2::ListSinksRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListSinks(context, request);
}

StatusOr<google::logging::v2::LogSink> ConfigServiceV2Metadata::GetSink(
    grpc::ClientContext& context,
    google::logging::v2::GetSinkRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("sink_name=", internal::UrlEncode(request.sink_name())));
  return child_->GetSink(context, request);
}

StatusOr<google::logging::v2::LogSink> ConfigServiceV2Metadata::CreateSink(
    grpc::ClientContext& context,
    google::logging::v2::CreateSinkRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateSink(context, request);
}

StatusOr<google::logging::v2::LogSink> ConfigServiceV2Metadata::UpdateSink(
    grpc::ClientContext& context,
    google::logging::v2::UpdateSinkRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("sink_name=", internal::UrlEncode(request.sink_name())));
  return child_->UpdateSink(context, request);
}

Status ConfigServiceV2Metadata::DeleteSink(
    grpc::ClientContext& context,
    google::logging::v2::DeleteSinkRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("sink_name=", internal::UrlEncode(request.sink_name())));
  return child_->DeleteSink(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncCreateLink(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::CreateLinkRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateLink(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncDeleteLink(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::DeleteLinkRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteLink(cq, std::move(context), request);
}

StatusOr<google::logging::v2::ListLinksResponse>
ConfigServiceV2Metadata::ListLinks(
    grpc::ClientContext& context,
    google::logging::v2::ListLinksRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListLinks(context, request);
}

StatusOr<google::logging::v2::Link> ConfigServiceV2Metadata::GetLink(
    grpc::ClientContext& context,
    google::logging::v2::GetLinkRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetLink(context, request);
}

StatusOr<google::logging::v2::ListExclusionsResponse>
ConfigServiceV2Metadata::ListExclusions(
    grpc::ClientContext& context,
    google::logging::v2::ListExclusionsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListExclusions(context, request);
}

StatusOr<google::logging::v2::LogExclusion>
ConfigServiceV2Metadata::GetExclusion(
    grpc::ClientContext& context,
    google::logging::v2::GetExclusionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetExclusion(context, request);
}

StatusOr<google::logging::v2::LogExclusion>
ConfigServiceV2Metadata::CreateExclusion(
    grpc::ClientContext& context,
    google::logging::v2::CreateExclusionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateExclusion(context, request);
}

StatusOr<google::logging::v2::LogExclusion>
ConfigServiceV2Metadata::UpdateExclusion(
    grpc::ClientContext& context,
    google::logging::v2::UpdateExclusionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateExclusion(context, request);
}

Status ConfigServiceV2Metadata::DeleteExclusion(
    grpc::ClientContext& context,
    google::logging::v2::DeleteExclusionRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteExclusion(context, request);
}

StatusOr<google::logging::v2::CmekSettings>
ConfigServiceV2Metadata::GetCmekSettings(
    grpc::ClientContext& context,
    google::logging::v2::GetCmekSettingsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetCmekSettings(context, request);
}

StatusOr<google::logging::v2::CmekSettings>
ConfigServiceV2Metadata::UpdateCmekSettings(
    grpc::ClientContext& context,
    google::logging::v2::UpdateCmekSettingsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateCmekSettings(context, request);
}

StatusOr<google::logging::v2::Settings> ConfigServiceV2Metadata::GetSettings(
    grpc::ClientContext& context,
    google::logging::v2::GetSettingsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetSettings(context, request);
}

StatusOr<google::logging::v2::Settings> ConfigServiceV2Metadata::UpdateSettings(
    grpc::ClientContext& context,
    google::logging::v2::UpdateSettingsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateSettings(context, request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncCopyLogEntries(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::logging::v2::CopyLogEntriesRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->AsyncCopyLogEntries(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
ConfigServiceV2Metadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> ConfigServiceV2Metadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void ConfigServiceV2Metadata::SetMetadata(grpc::ClientContext& context,
                                          Options const& options,
                                          std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void ConfigServiceV2Metadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace logging_v2_internal
}  // namespace cloud
}  // namespace google
