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
// source: google/datastore/admin/v1/datastore_admin.proto

#include "google/cloud/datastore/admin/v1/datastore_admin_connection.h"
#include "google/cloud/datastore/admin/v1/datastore_admin_options.h"
#include "google/cloud/datastore/admin/v1/internal/datastore_admin_connection_impl.h"
#include "google/cloud/datastore/admin/v1/internal/datastore_admin_option_defaults.h"
#include "google/cloud/datastore/admin/v1/internal/datastore_admin_stub_factory.h"
#include "google/cloud/datastore/admin/v1/internal/datastore_admin_tracing_connection.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace datastore_admin_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DatastoreAdminConnection::~DatastoreAdminConnection() = default;

future<StatusOr<google::datastore::admin::v1::ExportEntitiesResponse>>
DatastoreAdminConnection::ExportEntities(
    google::datastore::admin::v1::ExportEntitiesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::datastore::admin::v1::ExportEntitiesResponse>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::datastore::admin::v1::ImportEntitiesMetadata>>
DatastoreAdminConnection::ImportEntities(
    google::datastore::admin::v1::ImportEntitiesRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::datastore::admin::v1::ImportEntitiesMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::datastore::admin::v1::Index>>
DatastoreAdminConnection::CreateIndex(
    google::datastore::admin::v1::CreateIndexRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::datastore::admin::v1::Index>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::datastore::admin::v1::Index>>
DatastoreAdminConnection::DeleteIndex(
    google::datastore::admin::v1::DeleteIndexRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::datastore::admin::v1::Index>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::datastore::admin::v1::Index>
DatastoreAdminConnection::GetIndex(
    google::datastore::admin::v1::GetIndexRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::datastore::admin::v1::Index>
DatastoreAdminConnection::ListIndexes(
    google::datastore::admin::v1::
        ListIndexesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::datastore::admin::v1::Index>>();
}

std::shared_ptr<DatastoreAdminConnection> MakeDatastoreAdminConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 DatastoreAdminPolicyOptionList>(options,
                                                                 __func__);
  options = datastore_admin_v1_internal::DatastoreAdminDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = datastore_admin_v1_internal::CreateDefaultDatastoreAdminStub(
      background->cq(), options);
  return datastore_admin_v1_internal::MakeDatastoreAdminTracingConnection(
      std::make_shared<
          datastore_admin_v1_internal::DatastoreAdminConnectionImpl>(
          std::move(background), std::move(stub), std::move(options)));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastore_admin_v1
}  // namespace cloud
}  // namespace google
