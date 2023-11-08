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
// source: google/cloud/aiplatform/v1/job_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_JOB_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_JOB_METADATA_DECORATOR_H

#include "google/cloud/aiplatform/v1/internal/job_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class JobServiceMetadata : public JobServiceStub {
 public:
  ~JobServiceMetadata() override = default;
  JobServiceMetadata(std::shared_ptr<JobServiceStub> child,
                     std::multimap<std::string, std::string> fixed_metadata,
                     std::string api_client_header = "");

  StatusOr<google::cloud::aiplatform::v1::CustomJob> CreateCustomJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CreateCustomJobRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::CustomJob> GetCustomJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetCustomJobRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListCustomJobsResponse>
  ListCustomJobs(grpc::ClientContext& context,
                 google::cloud::aiplatform::v1::ListCustomJobsRequest const&
                     request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteCustomJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::DeleteCustomJobRequest const& request)
      override;

  Status CancelCustomJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CancelCustomJobRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::DataLabelingJob>
  CreateDataLabelingJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CreateDataLabelingJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::DataLabelingJob> GetDataLabelingJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetDataLabelingJobRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListDataLabelingJobsResponse>
  ListDataLabelingJobs(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::ListDataLabelingJobsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteDataLabelingJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::DeleteDataLabelingJobRequest const&
          request) override;

  Status CancelDataLabelingJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CancelDataLabelingJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::HyperparameterTuningJob>
  CreateHyperparameterTuningJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CreateHyperparameterTuningJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::HyperparameterTuningJob>
  GetHyperparameterTuningJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetHyperparameterTuningJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::ListHyperparameterTuningJobsResponse>
  ListHyperparameterTuningJobs(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::ListHyperparameterTuningJobsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteHyperparameterTuningJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::DeleteHyperparameterTuningJobRequest const&
          request) override;

  Status CancelHyperparameterTuningJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CancelHyperparameterTuningJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::NasJob> CreateNasJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CreateNasJobRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::NasJob> GetNasJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetNasJobRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::ListNasJobsResponse> ListNasJobs(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::ListNasJobsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteNasJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::DeleteNasJobRequest const& request)
      override;

  Status CancelNasJob(grpc::ClientContext& context,
                      google::cloud::aiplatform::v1::CancelNasJobRequest const&
                          request) override;

  StatusOr<google::cloud::aiplatform::v1::NasTrialDetail> GetNasTrialDetail(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetNasTrialDetailRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ListNasTrialDetailsResponse>
  ListNasTrialDetails(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::ListNasTrialDetailsRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::BatchPredictionJob>
  CreateBatchPredictionJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CreateBatchPredictionJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::BatchPredictionJob>
  GetBatchPredictionJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::GetBatchPredictionJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::ListBatchPredictionJobsResponse>
  ListBatchPredictionJobs(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::ListBatchPredictionJobsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteBatchPredictionJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::DeleteBatchPredictionJobRequest const&
          request) override;

  Status CancelBatchPredictionJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::CancelBatchPredictionJobRequest const&
          request) override;

  StatusOr<google::cloud::aiplatform::v1::ModelDeploymentMonitoringJob>
  CreateModelDeploymentMonitoringJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          CreateModelDeploymentMonitoringJobRequest const& request) override;

  StatusOr<google::cloud::aiplatform::v1::
               SearchModelDeploymentMonitoringStatsAnomaliesResponse>
  SearchModelDeploymentMonitoringStatsAnomalies(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          SearchModelDeploymentMonitoringStatsAnomaliesRequest const& request)
      override;

  StatusOr<google::cloud::aiplatform::v1::ModelDeploymentMonitoringJob>
  GetModelDeploymentMonitoringJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          GetModelDeploymentMonitoringJobRequest const& request) override;

  StatusOr<
      google::cloud::aiplatform::v1::ListModelDeploymentMonitoringJobsResponse>
  ListModelDeploymentMonitoringJobs(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          ListModelDeploymentMonitoringJobsRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateModelDeploymentMonitoringJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::
          UpdateModelDeploymentMonitoringJobRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteModelDeploymentMonitoringJob(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::aiplatform::v1::
          DeleteModelDeploymentMonitoringJobRequest const& request) override;

  Status PauseModelDeploymentMonitoringJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          PauseModelDeploymentMonitoringJobRequest const& request) override;

  Status ResumeModelDeploymentMonitoringJob(
      grpc::ClientContext& context,
      google::cloud::aiplatform::v1::
          ResumeModelDeploymentMonitoringJobRequest const& request) override;

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

  std::shared_ptr<JobServiceStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_AIPLATFORM_V1_INTERNAL_JOB_METADATA_DECORATOR_H
