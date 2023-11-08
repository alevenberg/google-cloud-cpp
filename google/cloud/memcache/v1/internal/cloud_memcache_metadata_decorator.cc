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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/memcache/v1/cloud_memcache.proto

#include "google/cloud/memcache/v1/internal/cloud_memcache_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/memcache/v1/cloud_memcache.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace memcache_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudMemcacheMetadata::CloudMemcacheMetadata(
    std::shared_ptr<CloudMemcacheStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::memcache::v1::ListInstancesResponse>
CloudMemcacheMetadata::ListInstances(
    grpc::ClientContext& context,
    google::cloud::memcache::v1::ListInstancesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListInstances(context, request);
}

StatusOr<google::cloud::memcache::v1::Instance>
CloudMemcacheMetadata::GetInstance(
    grpc::ClientContext& context,
    google::cloud::memcache::v1::GetInstanceRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetInstance(context, request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::CreateInstanceRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::UpdateInstanceRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("instance.name=",
                           internal::UrlEncode(request.instance().name())));
  return child_->AsyncUpdateInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncUpdateParameters(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::UpdateParametersRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncUpdateParameters(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::DeleteInstanceRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncApplyParameters(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::ApplyParametersRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncApplyParameters(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncRescheduleMaintenance(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::memcache::v1::RescheduleMaintenanceRequest const& request) {
  SetMetadata(
      *context, internal::CurrentOptions(),
      absl::StrCat("instance=", internal::UrlEncode(request.instance())));
  return child_->AsyncRescheduleMaintenance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudMemcacheMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> CloudMemcacheMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void CloudMemcacheMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void CloudMemcacheMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace memcache_v1_internal
}  // namespace cloud
}  // namespace google
