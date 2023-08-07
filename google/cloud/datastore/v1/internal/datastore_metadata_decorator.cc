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
// source: google/datastore/v1/datastore.proto

#include "google/cloud/datastore/v1/internal/datastore_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/routing_matcher.h"
#include "google/cloud/status_or.h"
#include <google/datastore/v1/datastore.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace datastore_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DatastoreMetadata::DatastoreMetadata(
    std::shared_ptr<DatastoreStub> child,
    std::multimap<std::string, std::string> fixed_metadata)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::datastore::v1::LookupResponse> DatastoreMetadata::Lookup(
    grpc::ClientContext& context,
    google::datastore::v1::LookupRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->Lookup(context, request);
}

StatusOr<google::datastore::v1::RunQueryResponse> DatastoreMetadata::RunQuery(
    grpc::ClientContext& context,
    google::datastore::v1::RunQueryRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->RunQuery(context, request);
}

StatusOr<google::datastore::v1::RunAggregationQueryResponse>
DatastoreMetadata::RunAggregationQuery(
    grpc::ClientContext& context,
    google::datastore::v1::RunAggregationQueryRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->RunAggregationQuery(context, request);
}

StatusOr<google::datastore::v1::BeginTransactionResponse>
DatastoreMetadata::BeginTransaction(
    grpc::ClientContext& context,
    google::datastore::v1::BeginTransactionRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->BeginTransaction(context, request);
}

StatusOr<google::datastore::v1::CommitResponse> DatastoreMetadata::Commit(
    grpc::ClientContext& context,
    google::datastore::v1::CommitRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->Commit(context, request);
}

StatusOr<google::datastore::v1::RollbackResponse> DatastoreMetadata::Rollback(
    grpc::ClientContext& context,
    google::datastore::v1::RollbackRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->Rollback(context, request);
}

StatusOr<google::datastore::v1::AllocateIdsResponse>
DatastoreMetadata::AllocateIds(
    grpc::ClientContext& context,
    google::datastore::v1::AllocateIdsRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->AllocateIds(context, request);
}

StatusOr<google::datastore::v1::ReserveIdsResponse>
DatastoreMetadata::ReserveIds(
    grpc::ClientContext& context,
    google::datastore::v1::ReserveIdsRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.project_id().empty()) {
    params.push_back("project_id=" + request.project_id());
  }

  if (!request.database_id().empty()) {
    params.push_back("database_id=" + request.database_id());
  }

  if (params.empty()) {
    SetMetadata(context);
  } else {
    SetMetadata(context, absl::StrJoin(params, "&"));
  }
  return child_->ReserveIds(context, request);
}

void DatastoreMetadata::SetMetadata(grpc::ClientContext& context,
                                    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void DatastoreMetadata::SetMetadata(grpc::ClientContext& context) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastore_v1_internal
}  // namespace cloud
}  // namespace google
