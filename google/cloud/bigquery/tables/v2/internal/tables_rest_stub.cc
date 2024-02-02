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

#include "google/cloud/bigquery/tables/v2/internal/tables_rest_stub.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/rest_stub_helpers.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/tables/v2/tables.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tables_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DefaultTablesRestStub::DefaultTablesRestStub(Options options)
    : service_(rest_internal::MakePooledRestClient(
          options.get<EndpointOption>(), options)),
      options_(std::move(options)) {}

DefaultTablesRestStub::DefaultTablesRestStub(
    std::shared_ptr<rest_internal::RestClient> service,
    Options options)
    : service_(std::move(service)),
      options_(std::move(options)) {}

Status DefaultTablesRestStub::DeleteTable(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::DeleteTableRequest const& request) {
  return rest_internal::Delete(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables", "/", request.table_id()));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
DefaultTablesRestStub::GetTable(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::GetTableRequest const& request) {
  return rest_internal::Get<google::cloud::cpp::bigquery::v2::Table>(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables", "/", request.table_id()),
      rest_internal::TrimEmptyQueryParameters({std::make_pair("selected_fields", request.selected_fields()),
        std::make_pair("view", request.view())}));
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
DefaultTablesRestStub::GetIamPolicy(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::GetIamPolicyRequest const& request) {
  return rest_internal::Post<google::cloud::cpp::bigquery::v2::Policy>(
      *service_, rest_context, request.get_iam_policy_request_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", request.resource(), ":getIamPolicy"));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
DefaultTablesRestStub::InsertTable(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::InsertTableRequest const& request) {
  return rest_internal::Post<google::cloud::cpp::bigquery::v2::Table, google::cloud::cpp::bigquery::v2::Table>(
      *service_, rest_context, request.table_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables"));
}

StatusOr<google::cloud::cpp::bigquery::v2::TableList>
DefaultTablesRestStub::ListTables(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::ListTablesRequest const& request) {
  return rest_internal::Get<google::cloud::cpp::bigquery::v2::TableList>(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables"),
      rest_internal::TrimEmptyQueryParameters({std::make_pair("max_results", std::to_string(request.max_results())),
        std::make_pair("page_token", request.page_token())}));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
DefaultTablesRestStub::PatchTable(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::PatchTableRequest const& request) {
  return rest_internal::Patch<google::cloud::cpp::bigquery::v2::Table>(
      *service_, rest_context, request.table_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables", "/", request.table_id()),
      rest_internal::TrimEmptyQueryParameters({std::make_pair("autodetect_schema", request.autodetect_schema() ? "1" : "0")}));
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
DefaultTablesRestStub::SetIamPolicy(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::SetIamPolicyRequest const& request) {
  return rest_internal::Post<google::cloud::cpp::bigquery::v2::Policy>(
      *service_, rest_context, request.set_iam_policy_request_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", request.resource(), ":setIamPolicy"));
}

StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
DefaultTablesRestStub::TestIamPermissions(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::TestIamPermissionsRequest const& request) {
  return rest_internal::Post<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>(
      *service_, rest_context, request.test_iam_permissions_request_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", request.resource(), ":testIamPermissions"));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
DefaultTablesRestStub::UpdateTable(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::tables::v2::UpdateTableRequest const& request) {
  return rest_internal::Put<google::cloud::cpp::bigquery::v2::Table>(
      *service_, rest_context, request.table_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "tables", "/", request.table_id()),
      rest_internal::TrimEmptyQueryParameters({std::make_pair("autodetect_schema", request.autodetect_schema() ? "1" : "0")}));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tables_v2_internal
}  // namespace cloud
}  // namespace google
