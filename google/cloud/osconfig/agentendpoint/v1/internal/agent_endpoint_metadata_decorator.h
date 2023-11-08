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
// source: google/cloud/osconfig/agentendpoint/v1/agentendpoint.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_AGENTENDPOINT_V1_INTERNAL_AGENT_ENDPOINT_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_AGENTENDPOINT_V1_INTERNAL_AGENT_ENDPOINT_METADATA_DECORATOR_H

#include "google/cloud/osconfig/agentendpoint/v1/internal/agent_endpoint_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace osconfig_agentendpoint_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AgentEndpointServiceMetadata : public AgentEndpointServiceStub {
 public:
  ~AgentEndpointServiceMetadata() override = default;
  AgentEndpointServiceMetadata(
      std::shared_ptr<AgentEndpointServiceStub> child,
      std::multimap<std::string, std::string> fixed_metadata,
      std::string api_client_header = "");

  std::unique_ptr<google::cloud::internal::StreamingReadRpc<
      google::cloud::osconfig::agentendpoint::v1::
          ReceiveTaskNotificationResponse>>
  ReceiveTaskNotification(
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::osconfig::agentendpoint::v1::
          ReceiveTaskNotificationRequest const& request) override;

  StatusOr<google::cloud::osconfig::agentendpoint::v1::StartNextTaskResponse>
  StartNextTask(
      grpc::ClientContext& context,
      google::cloud::osconfig::agentendpoint::v1::StartNextTaskRequest const&
          request) override;

  StatusOr<
      google::cloud::osconfig::agentendpoint::v1::ReportTaskProgressResponse>
  ReportTaskProgress(grpc::ClientContext& context,
                     google::cloud::osconfig::agentendpoint::v1::
                         ReportTaskProgressRequest const& request) override;

  StatusOr<
      google::cloud::osconfig::agentendpoint::v1::ReportTaskCompleteResponse>
  ReportTaskComplete(grpc::ClientContext& context,
                     google::cloud::osconfig::agentendpoint::v1::
                         ReportTaskCompleteRequest const& request) override;

  StatusOr<google::cloud::osconfig::agentendpoint::v1::RegisterAgentResponse>
  RegisterAgent(
      grpc::ClientContext& context,
      google::cloud::osconfig::agentendpoint::v1::RegisterAgentRequest const&
          request) override;

  StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportInventoryResponse>
  ReportInventory(
      grpc::ClientContext& context,
      google::cloud::osconfig::agentendpoint::v1::ReportInventoryRequest const&
          request) override;

 private:
  void SetMetadata(grpc::ClientContext& context, Options const& options,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context, Options const& options);

  std::shared_ptr<AgentEndpointServiceStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace osconfig_agentendpoint_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_OSCONFIG_AGENTENDPOINT_V1_INTERNAL_AGENT_ENDPOINT_METADATA_DECORATOR_H
