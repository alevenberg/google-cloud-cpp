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
// source: google/cloud/securitycenter/v2/securitycenter_service.proto

#include "google/cloud/securitycenter/v2/security_center_client.h"
#include "google/cloud/securitycenter/v2/security_center_options.h"
#include <memory>
#include <thread>
#include <utility>

namespace google {
namespace cloud {
namespace securitycenter_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SecurityCenterClient::SecurityCenterClient(
    std::shared_ptr<SecurityCenterConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
SecurityCenterClient::~SecurityCenterClient() = default;

StatusOr<
    google::cloud::securitycenter::v2::BatchCreateResourceValueConfigsResponse>
SecurityCenterClient::BatchCreateResourceValueConfigs(
    std::string const& parent,
    std::vector<google::cloud::securitycenter::v2::
                    CreateResourceValueConfigRequest> const& requests,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::BatchCreateResourceValueConfigsRequest
      request;
  request.set_parent(parent);
  *request.mutable_requests() = {requests.begin(), requests.end()};
  return connection_->BatchCreateResourceValueConfigs(request);
}

StatusOr<
    google::cloud::securitycenter::v2::BatchCreateResourceValueConfigsResponse>
SecurityCenterClient::BatchCreateResourceValueConfigs(
    google::cloud::securitycenter::v2::
        BatchCreateResourceValueConfigsRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->BatchCreateResourceValueConfigs(request);
}

future<StatusOr<google::cloud::securitycenter::v2::BulkMuteFindingsResponse>>
SecurityCenterClient::BulkMuteFindings(std::string const& parent,
                                       Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::BulkMuteFindingsRequest request;
  request.set_parent(parent);
  return connection_->BulkMuteFindings(request);
}

future<StatusOr<google::cloud::securitycenter::v2::BulkMuteFindingsResponse>>
SecurityCenterClient::BulkMuteFindings(
    google::cloud::securitycenter::v2::BulkMuteFindingsRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->BulkMuteFindings(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::CreateBigQueryExport(
    std::string const& parent,
    google::cloud::securitycenter::v2::BigQueryExport const& big_query_export,
    std::string const& big_query_export_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::CreateBigQueryExportRequest request;
  request.set_parent(parent);
  *request.mutable_big_query_export() = big_query_export;
  request.set_big_query_export_id(big_query_export_id);
  return connection_->CreateBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::CreateBigQueryExport(
    google::cloud::securitycenter::v2::CreateBigQueryExportRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::CreateFinding(
    std::string const& parent,
    google::cloud::securitycenter::v2::Finding const& finding,
    std::string const& finding_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::CreateFindingRequest request;
  request.set_parent(parent);
  *request.mutable_finding() = finding;
  request.set_finding_id(finding_id);
  return connection_->CreateFinding(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::CreateFinding(
    google::cloud::securitycenter::v2::CreateFindingRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateFinding(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::CreateMuteConfig(
    std::string const& parent,
    google::cloud::securitycenter::v2::MuteConfig const& mute_config,
    std::string const& mute_config_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::CreateMuteConfigRequest request;
  request.set_parent(parent);
  *request.mutable_mute_config() = mute_config;
  request.set_mute_config_id(mute_config_id);
  return connection_->CreateMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::CreateMuteConfig(
    google::cloud::securitycenter::v2::CreateMuteConfigRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::CreateNotificationConfig(
    std::string const& parent,
    google::cloud::securitycenter::v2::NotificationConfig const&
        notification_config,
    std::string const& config_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::CreateNotificationConfigRequest request;
  request.set_parent(parent);
  *request.mutable_notification_config() = notification_config;
  request.set_config_id(config_id);
  return connection_->CreateNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::CreateNotificationConfig(
    google::cloud::securitycenter::v2::CreateNotificationConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::CreateSource(
    std::string const& parent,
    google::cloud::securitycenter::v2::Source const& source, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::CreateSourceRequest request;
  request.set_parent(parent);
  *request.mutable_source() = source;
  return connection_->CreateSource(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::CreateSource(
    google::cloud::securitycenter::v2::CreateSourceRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateSource(request);
}

Status SecurityCenterClient::DeleteBigQueryExport(std::string const& name,
                                                  Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::DeleteBigQueryExportRequest request;
  request.set_name(name);
  return connection_->DeleteBigQueryExport(request);
}

Status SecurityCenterClient::DeleteBigQueryExport(
    google::cloud::securitycenter::v2::DeleteBigQueryExportRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteBigQueryExport(request);
}

Status SecurityCenterClient::DeleteMuteConfig(std::string const& name,
                                              Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::DeleteMuteConfigRequest request;
  request.set_name(name);
  return connection_->DeleteMuteConfig(request);
}

Status SecurityCenterClient::DeleteMuteConfig(
    google::cloud::securitycenter::v2::DeleteMuteConfigRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteMuteConfig(request);
}

Status SecurityCenterClient::DeleteNotificationConfig(std::string const& name,
                                                      Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::DeleteNotificationConfigRequest request;
  request.set_name(name);
  return connection_->DeleteNotificationConfig(request);
}

Status SecurityCenterClient::DeleteNotificationConfig(
    google::cloud::securitycenter::v2::DeleteNotificationConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteNotificationConfig(request);
}

Status SecurityCenterClient::DeleteResourceValueConfig(std::string const& name,
                                                       Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::DeleteResourceValueConfigRequest request;
  request.set_name(name);
  return connection_->DeleteResourceValueConfig(request);
}

Status SecurityCenterClient::DeleteResourceValueConfig(
    google::cloud::securitycenter::v2::DeleteResourceValueConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteResourceValueConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::GetBigQueryExport(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetBigQueryExportRequest request;
  request.set_name(name);
  return connection_->GetBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::GetBigQueryExport(
    google::cloud::securitycenter::v2::GetBigQueryExportRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::Simulation>
SecurityCenterClient::GetSimulation(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetSimulationRequest request;
  request.set_name(name);
  return connection_->GetSimulation(request);
}

StatusOr<google::cloud::securitycenter::v2::Simulation>
SecurityCenterClient::GetSimulation(
    google::cloud::securitycenter::v2::GetSimulationRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetSimulation(request);
}

StatusOr<google::cloud::securitycenter::v2::ValuedResource>
SecurityCenterClient::GetValuedResource(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetValuedResourceRequest request;
  request.set_name(name);
  return connection_->GetValuedResource(request);
}

StatusOr<google::cloud::securitycenter::v2::ValuedResource>
SecurityCenterClient::GetValuedResource(
    google::cloud::securitycenter::v2::GetValuedResourceRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetValuedResource(request);
}

StatusOr<google::iam::v1::Policy> SecurityCenterClient::GetIamPolicy(
    std::string const& resource, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::iam::v1::GetIamPolicyRequest request;
  request.set_resource(resource);
  return connection_->GetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> SecurityCenterClient::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetIamPolicy(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::GetMuteConfig(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetMuteConfigRequest request;
  request.set_name(name);
  return connection_->GetMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::GetMuteConfig(
    google::cloud::securitycenter::v2::GetMuteConfigRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::GetNotificationConfig(std::string const& name,
                                            Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetNotificationConfigRequest request;
  request.set_name(name);
  return connection_->GetNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::GetNotificationConfig(
    google::cloud::securitycenter::v2::GetNotificationConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::GetResourceValueConfig(std::string const& name,
                                             Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetResourceValueConfigRequest request;
  request.set_name(name);
  return connection_->GetResourceValueConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::GetResourceValueConfig(
    google::cloud::securitycenter::v2::GetResourceValueConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetResourceValueConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::GetSource(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GetSourceRequest request;
  request.set_name(name);
  return connection_->GetSource(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::GetSource(
    google::cloud::securitycenter::v2::GetSourceRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetSource(request);
}

StreamRange<google::cloud::securitycenter::v2::GroupResult>
SecurityCenterClient::GroupFindings(std::string const& parent,
                                    std::string const& group_by, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::GroupFindingsRequest request;
  request.set_parent(parent);
  request.set_group_by(group_by);
  return connection_->GroupFindings(request);
}

StreamRange<google::cloud::securitycenter::v2::GroupResult>
SecurityCenterClient::GroupFindings(
    google::cloud::securitycenter::v2::GroupFindingsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GroupFindings(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::AttackPath>
SecurityCenterClient::ListAttackPaths(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListAttackPathsRequest request;
  request.set_parent(parent);
  return connection_->ListAttackPaths(request);
}

StreamRange<google::cloud::securitycenter::v2::AttackPath>
SecurityCenterClient::ListAttackPaths(
    google::cloud::securitycenter::v2::ListAttackPathsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListAttackPaths(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::ListBigQueryExports(std::string const& parent,
                                          Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListBigQueryExportsRequest request;
  request.set_parent(parent);
  return connection_->ListBigQueryExports(request);
}

StreamRange<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::ListBigQueryExports(
    google::cloud::securitycenter::v2::ListBigQueryExportsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListBigQueryExports(std::move(request));
}

StreamRange<
    google::cloud::securitycenter::v2::ListFindingsResponse::ListFindingsResult>
SecurityCenterClient::ListFindings(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListFindingsRequest request;
  request.set_parent(parent);
  return connection_->ListFindings(request);
}

StreamRange<
    google::cloud::securitycenter::v2::ListFindingsResponse::ListFindingsResult>
SecurityCenterClient::ListFindings(
    google::cloud::securitycenter::v2::ListFindingsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListFindings(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::ListMuteConfigs(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListMuteConfigsRequest request;
  request.set_parent(parent);
  return connection_->ListMuteConfigs(request);
}

StreamRange<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::ListMuteConfigs(
    google::cloud::securitycenter::v2::ListMuteConfigsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListMuteConfigs(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::ListNotificationConfigs(std::string const& parent,
                                              Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListNotificationConfigsRequest request;
  request.set_parent(parent);
  return connection_->ListNotificationConfigs(request);
}

StreamRange<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::ListNotificationConfigs(
    google::cloud::securitycenter::v2::ListNotificationConfigsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListNotificationConfigs(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::ListResourceValueConfigs(std::string const& parent,
                                               Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListResourceValueConfigsRequest request;
  request.set_parent(parent);
  return connection_->ListResourceValueConfigs(request);
}

StreamRange<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::ListResourceValueConfigs(
    google::cloud::securitycenter::v2::ListResourceValueConfigsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListResourceValueConfigs(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::ListSources(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListSourcesRequest request;
  request.set_parent(parent);
  return connection_->ListSources(request);
}

StreamRange<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::ListSources(
    google::cloud::securitycenter::v2::ListSourcesRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListSources(std::move(request));
}

StreamRange<google::cloud::securitycenter::v2::ValuedResource>
SecurityCenterClient::ListValuedResources(std::string const& parent,
                                          Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::ListValuedResourcesRequest request;
  request.set_parent(parent);
  return connection_->ListValuedResources(request);
}

StreamRange<google::cloud::securitycenter::v2::ValuedResource>
SecurityCenterClient::ListValuedResources(
    google::cloud::securitycenter::v2::ListValuedResourcesRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListValuedResources(std::move(request));
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::SetFindingState(
    std::string const& name,
    google::cloud::securitycenter::v2::Finding::State state, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::SetFindingStateRequest request;
  request.set_name(name);
  request.set_state(state);
  return connection_->SetFindingState(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::SetFindingState(
    google::cloud::securitycenter::v2::SetFindingStateRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SetFindingState(request);
}

StatusOr<google::iam::v1::Policy> SecurityCenterClient::SetIamPolicy(
    std::string const& resource, google::iam::v1::Policy const& policy,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::iam::v1::SetIamPolicyRequest request;
  request.set_resource(resource);
  *request.mutable_policy() = policy;
  return connection_->SetIamPolicy(request);
}

StatusOr<google::iam::v1::Policy> SecurityCenterClient::SetIamPolicy(
    std::string const& resource, IamUpdater const& updater, Options opts) {
  internal::CheckExpectedOptions<SecurityCenterBackoffPolicyOption>(opts,
                                                                    __func__);
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::iam::v1::GetIamPolicyRequest get_request;
  get_request.set_resource(resource);
  google::iam::v1::SetIamPolicyRequest set_request;
  set_request.set_resource(resource);
  auto backoff_policy =
      internal::CurrentOptions().get<SecurityCenterBackoffPolicyOption>();
  if (backoff_policy != nullptr) {
    backoff_policy = backoff_policy->clone();
  }
  for (;;) {
    auto recent = connection_->GetIamPolicy(get_request);
    if (!recent) {
      return recent.status();
    }
    auto policy = updater(*std::move(recent));
    if (!policy) {
      return internal::CancelledError(
          "updater did not yield a policy",
          GCP_ERROR_INFO().WithMetadata("gl-cpp.error.origin", "client"));
    }
    *set_request.mutable_policy() = *std::move(policy);
    auto result = connection_->SetIamPolicy(set_request);
    if (result || result.status().code() != StatusCode::kAborted ||
        backoff_policy == nullptr) {
      return result;
    }
    std::this_thread::sleep_for(backoff_policy->OnCompletion());
  }
}

StatusOr<google::iam::v1::Policy> SecurityCenterClient::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SetIamPolicy(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::SetMute(
    std::string const& name,
    google::cloud::securitycenter::v2::Finding::Mute mute, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::SetMuteRequest request;
  request.set_name(name);
  request.set_mute(mute);
  return connection_->SetMute(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::SetMute(
    google::cloud::securitycenter::v2::SetMuteRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->SetMute(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
SecurityCenterClient::TestIamPermissions(
    std::string const& resource, std::vector<std::string> const& permissions,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::iam::v1::TestIamPermissionsRequest request;
  request.set_resource(resource);
  *request.mutable_permissions() = {permissions.begin(), permissions.end()};
  return connection_->TestIamPermissions(request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
SecurityCenterClient::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->TestIamPermissions(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::UpdateBigQueryExport(
    google::cloud::securitycenter::v2::BigQueryExport const& big_query_export,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateBigQueryExportRequest request;
  *request.mutable_big_query_export() = big_query_export;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::BigQueryExport>
SecurityCenterClient::UpdateBigQueryExport(
    google::cloud::securitycenter::v2::UpdateBigQueryExportRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateBigQueryExport(request);
}

StatusOr<google::cloud::securitycenter::v2::ExternalSystem>
SecurityCenterClient::UpdateExternalSystem(
    google::cloud::securitycenter::v2::ExternalSystem const& external_system,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateExternalSystemRequest request;
  *request.mutable_external_system() = external_system;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateExternalSystem(request);
}

StatusOr<google::cloud::securitycenter::v2::ExternalSystem>
SecurityCenterClient::UpdateExternalSystem(
    google::cloud::securitycenter::v2::UpdateExternalSystemRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateExternalSystem(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::UpdateFinding(
    google::cloud::securitycenter::v2::Finding const& finding,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateFindingRequest request;
  *request.mutable_finding() = finding;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateFinding(request);
}

StatusOr<google::cloud::securitycenter::v2::Finding>
SecurityCenterClient::UpdateFinding(
    google::cloud::securitycenter::v2::UpdateFindingRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateFinding(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::UpdateMuteConfig(
    google::cloud::securitycenter::v2::MuteConfig const& mute_config,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateMuteConfigRequest request;
  *request.mutable_mute_config() = mute_config;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::MuteConfig>
SecurityCenterClient::UpdateMuteConfig(
    google::cloud::securitycenter::v2::UpdateMuteConfigRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateMuteConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::UpdateNotificationConfig(
    google::cloud::securitycenter::v2::NotificationConfig const&
        notification_config,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateNotificationConfigRequest request;
  *request.mutable_notification_config() = notification_config;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::NotificationConfig>
SecurityCenterClient::UpdateNotificationConfig(
    google::cloud::securitycenter::v2::UpdateNotificationConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateNotificationConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::UpdateResourceValueConfig(
    google::cloud::securitycenter::v2::ResourceValueConfig const&
        resource_value_config,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateResourceValueConfigRequest request;
  *request.mutable_resource_value_config() = resource_value_config;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateResourceValueConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::ResourceValueConfig>
SecurityCenterClient::UpdateResourceValueConfig(
    google::cloud::securitycenter::v2::UpdateResourceValueConfigRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateResourceValueConfig(request);
}

StatusOr<google::cloud::securitycenter::v2::SecurityMarks>
SecurityCenterClient::UpdateSecurityMarks(
    google::cloud::securitycenter::v2::SecurityMarks const& security_marks,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateSecurityMarksRequest request;
  *request.mutable_security_marks() = security_marks;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateSecurityMarks(request);
}

StatusOr<google::cloud::securitycenter::v2::SecurityMarks>
SecurityCenterClient::UpdateSecurityMarks(
    google::cloud::securitycenter::v2::UpdateSecurityMarksRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateSecurityMarks(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::UpdateSource(
    google::cloud::securitycenter::v2::Source const& source,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::securitycenter::v2::UpdateSourceRequest request;
  *request.mutable_source() = source;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateSource(request);
}

StatusOr<google::cloud::securitycenter::v2::Source>
SecurityCenterClient::UpdateSource(
    google::cloud::securitycenter::v2::UpdateSourceRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateSource(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace securitycenter_v2
}  // namespace cloud
}  // namespace google
