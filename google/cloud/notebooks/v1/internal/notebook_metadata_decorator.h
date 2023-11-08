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
// source: google/cloud/notebooks/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_INTERNAL_NOTEBOOK_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_INTERNAL_NOTEBOOK_METADATA_DECORATOR_H

#include "google/cloud/notebooks/v1/internal/notebook_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace notebooks_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class NotebookServiceMetadata : public NotebookServiceStub {
 public:
  ~NotebookServiceMetadata() override = default;
  NotebookServiceMetadata(
      std::shared_ptr<NotebookServiceStub> child,
      std::multimap<std::string, std::string> fixed_metadata,
      std::string api_client_header = "");

  StatusOr<google::cloud::notebooks::v1::ListInstancesResponse> ListInstances(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::ListInstancesRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::Instance> GetInstance(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::GetInstanceRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::CreateInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncRegisterInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::RegisterInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncSetInstanceAccelerator(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::SetInstanceAcceleratorRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncSetInstanceMachineType(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::SetInstanceMachineTypeRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateInstanceConfig(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::UpdateInstanceConfigRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateShieldedInstanceConfig(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::UpdateShieldedInstanceConfigRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncSetInstanceLabels(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::SetInstanceLabelsRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::UpdateInstanceMetadataItemsResponse>
  UpdateInstanceMetadataItems(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::UpdateInstanceMetadataItemsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::DeleteInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncStartInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::StartInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncStopInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::StopInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncResetInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::ResetInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncReportInstanceInfo(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::ReportInstanceInfoRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::IsInstanceUpgradeableResponse>
  IsInstanceUpgradeable(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::IsInstanceUpgradeableRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::GetInstanceHealthResponse>
  GetInstanceHealth(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::GetInstanceHealthRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpgradeInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::UpgradeInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncRollbackInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::RollbackInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDiagnoseInstance(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::DiagnoseInstanceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpgradeInstanceInternal(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::UpgradeInstanceInternalRequest const&
          request) override;

  StatusOr<google::cloud::notebooks::v1::ListEnvironmentsResponse>
  ListEnvironments(grpc::ClientContext& context,
                   google::cloud::notebooks::v1::ListEnvironmentsRequest const&
                       request) override;

  StatusOr<google::cloud::notebooks::v1::Environment> GetEnvironment(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::GetEnvironmentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateEnvironment(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::CreateEnvironmentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteEnvironment(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::DeleteEnvironmentRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::ListSchedulesResponse> ListSchedules(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::ListSchedulesRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::Schedule> GetSchedule(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::GetScheduleRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteSchedule(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::DeleteScheduleRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateSchedule(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::CreateScheduleRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncTriggerSchedule(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::TriggerScheduleRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::ListExecutionsResponse> ListExecutions(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::ListExecutionsRequest const& request)
      override;

  StatusOr<google::cloud::notebooks::v1::Execution> GetExecution(
      grpc::ClientContext& context,
      google::cloud::notebooks::v1::GetExecutionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteExecution(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::DeleteExecutionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateExecution(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::notebooks::v1::CreateExecutionRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context, Options const& options,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context, Options const& options);

  std::shared_ptr<NotebookServiceStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace notebooks_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NOTEBOOKS_V1_INTERNAL_NOTEBOOK_METADATA_DECORATOR_H
