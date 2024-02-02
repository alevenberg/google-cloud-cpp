// Copyright 2024 Google LLC
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
// source: google/cloud/bigquery/tables/v2/tables.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLES_V2_INTERNAL_TABLES_REST_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLES_V2_INTERNAL_TABLES_REST_CONNECTION_IMPL_H

#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/bigquery/tables/v2/internal/tables_rest_stub.h"
#include "google/cloud/bigquery/tables/v2/internal/tables_retry_traits.h"
#include "google/cloud/bigquery/tables/v2/tables_connection.h"
#include "google/cloud/bigquery/tables/v2/tables_connection_idempotency_policy.h"
#include "google/cloud/bigquery/tables/v2/tables_options.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tables_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TablesRestConnectionImpl
    : public bigquery_tables_v2::TablesConnection {
 public:
  ~TablesRestConnectionImpl() override = default;

  TablesRestConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<bigquery_tables_v2_internal::TablesRestStub> stub,
    Options options);

  Options options() override { return options_; }

  Status
  DeleteTable(google::cloud::cpp::bigquery::tables::v2::DeleteTableRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Table>
  GetTable(google::cloud::cpp::bigquery::tables::v2::GetTableRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Policy>
  GetIamPolicy(google::cloud::cpp::bigquery::tables::v2::GetIamPolicyRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Table>
  InsertTable(google::cloud::cpp::bigquery::tables::v2::InsertTableRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::TableList>
  ListTables(google::cloud::cpp::bigquery::tables::v2::ListTablesRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Table>
  PatchTable(google::cloud::cpp::bigquery::tables::v2::PatchTableRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Policy>
  SetIamPolicy(google::cloud::cpp::bigquery::tables::v2::SetIamPolicyRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
  TestIamPermissions(google::cloud::cpp::bigquery::tables::v2::TestIamPermissionsRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Table>
  UpdateTable(google::cloud::cpp::bigquery::tables::v2::UpdateTableRequest const& request) override;

 private:
  static std::unique_ptr<bigquery_tables_v2::TablesRetryPolicy>
  retry_policy(Options const& options) {
    return options.get<bigquery_tables_v2::TablesRetryPolicyOption>()->clone();
  }

  static std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
    return options.get<bigquery_tables_v2::TablesBackoffPolicyOption>()->clone();
  }

  static std::unique_ptr<bigquery_tables_v2::TablesConnectionIdempotencyPolicy>
  idempotency_policy(Options const& options) {
    return options.get<bigquery_tables_v2::TablesConnectionIdempotencyPolicyOption>()->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<bigquery_tables_v2_internal::TablesRestStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tables_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLES_V2_INTERNAL_TABLES_REST_CONNECTION_IMPL_H
