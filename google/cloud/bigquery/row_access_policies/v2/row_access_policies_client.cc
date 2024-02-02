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
// source: google/cloud/bigquery/row_access_policies/v2/row_access_policies.proto

#include "google/cloud/bigquery/row_access_policies/v2/row_access_policies_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_row_access_policies_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RowAccessPoliciesClient::RowAccessPoliciesClient(
    std::shared_ptr<RowAccessPoliciesConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(std::move(opts),
      connection_->options())) {}
RowAccessPoliciesClient::~RowAccessPoliciesClient() = default;

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
RowAccessPoliciesClient::GetIamPolicy(std::string const& resource, google::cloud::cpp::bigquery::v2::GetIamPolicyRequest const& get_iam_policy_request_resource, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::row_access_policies::v2::GetIamPolicyRequest request;
  request.set_resource(resource);
  *request.mutable_get_iam_policy_request_resource() = get_iam_policy_request_resource;
  return connection_->GetIamPolicy(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
RowAccessPoliciesClient::GetIamPolicy(google::cloud::cpp::bigquery::row_access_policies::v2::GetIamPolicyRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetIamPolicy(request);
}

StreamRange<google::cloud::cpp::bigquery::v2::RowAccessPolicy>
RowAccessPoliciesClient::ListRowAccessPolicies(std::string const& project_id, std::string const& dataset_id, std::string const& table_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::row_access_policies::v2::ListRowAccessPoliciesRequest request;
  request.set_project_id(project_id);
  request.set_dataset_id(dataset_id);
  request.set_table_id(table_id);
  return connection_->ListRowAccessPolicies(request);
}

StreamRange<google::cloud::cpp::bigquery::v2::RowAccessPolicy>
RowAccessPoliciesClient::ListRowAccessPolicies(google::cloud::cpp::bigquery::row_access_policies::v2::ListRowAccessPoliciesRequest request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListRowAccessPolicies(std::move(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
RowAccessPoliciesClient::TestIamPermissions(std::string const& resource, google::cloud::cpp::bigquery::v2::TestIamPermissionsRequest const& test_iam_permissions_request_resource, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::row_access_policies::v2::TestIamPermissionsRequest request;
  request.set_resource(resource);
  *request.mutable_test_iam_permissions_request_resource() = test_iam_permissions_request_resource;
  return connection_->TestIamPermissions(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
RowAccessPoliciesClient::TestIamPermissions(google::cloud::cpp::bigquery::row_access_policies::v2::TestIamPermissionsRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->TestIamPermissions(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_row_access_policies_v2
}  // namespace cloud
}  // namespace google
