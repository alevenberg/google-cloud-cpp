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

#include "google/cloud/bigquery/tables/v2/internal/tables_rest_connection_impl.h"
#include "google/cloud/bigquery/tables/v2/internal/tables_rest_stub_factory.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/internal/rest_retry_loop.h"
#include "google/cloud/rest_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tables_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TablesRestConnectionImpl::TablesRestConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<bigquery_tables_v2_internal::TablesRestStub> stub,
    Options options)
  : background_(std::move(background)), stub_(std::move(stub)),
    options_(internal::MergeOptions(
        std::move(options),
        TablesConnection::options())) {}

Status
TablesRestConnectionImpl::DeleteTable(google::cloud::cpp::bigquery::tables::v2::DeleteTableRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->DeleteTable(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::DeleteTableRequest const& request) {
        return stub_->DeleteTable(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesRestConnectionImpl::GetTable(google::cloud::cpp::bigquery::tables::v2::GetTableRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetTable(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::GetTableRequest const& request) {
        return stub_->GetTable(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
TablesRestConnectionImpl::GetIamPolicy(google::cloud::cpp::bigquery::tables::v2::GetIamPolicyRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetIamPolicy(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::GetIamPolicyRequest const& request) {
        return stub_->GetIamPolicy(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesRestConnectionImpl::InsertTable(google::cloud::cpp::bigquery::tables::v2::InsertTableRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->InsertTable(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::InsertTableRequest const& request) {
        return stub_->InsertTable(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::TableList>
TablesRestConnectionImpl::ListTables(google::cloud::cpp::bigquery::tables::v2::ListTablesRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->ListTables(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::ListTablesRequest const& request) {
        return stub_->ListTables(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesRestConnectionImpl::PatchTable(google::cloud::cpp::bigquery::tables::v2::PatchTableRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->PatchTable(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::PatchTableRequest const& request) {
        return stub_->PatchTable(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
TablesRestConnectionImpl::SetIamPolicy(google::cloud::cpp::bigquery::tables::v2::SetIamPolicyRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->SetIamPolicy(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::SetIamPolicyRequest const& request) {
        return stub_->SetIamPolicy(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
TablesRestConnectionImpl::TestIamPermissions(google::cloud::cpp::bigquery::tables::v2::TestIamPermissionsRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->TestIamPermissions(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::TestIamPermissionsRequest const& request) {
        return stub_->TestIamPermissions(rest_context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesRestConnectionImpl::UpdateTable(google::cloud::cpp::bigquery::tables::v2::UpdateTableRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::rest_internal::RestRetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->UpdateTable(request),
      [this](rest_internal::RestContext& rest_context,
             Options const& options, google::cloud::cpp::bigquery::tables::v2::UpdateTableRequest const& request) {
        return stub_->UpdateTable(rest_context, options, request);
      },
      *current, request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tables_v2_internal
}  // namespace cloud
}  // namespace google
