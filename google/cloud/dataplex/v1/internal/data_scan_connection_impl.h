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
// source: google/cloud/dataplex/v1/datascans.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_SCAN_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_SCAN_CONNECTION_IMPL_H

#include "google/cloud/dataplex/v1/data_scan_connection.h"
#include "google/cloud/dataplex/v1/data_scan_connection_idempotency_policy.h"
#include "google/cloud/dataplex/v1/data_scan_options.h"
#include "google/cloud/dataplex/v1/internal/data_scan_retry_traits.h"
#include "google/cloud/dataplex/v1/internal/data_scan_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dataplex_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DataScanServiceConnectionImpl
    : public dataplex_v1::DataScanServiceConnection {
 public:
  ~DataScanServiceConnectionImpl() override = default;

  DataScanServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<dataplex_v1_internal::DataScanServiceStub> stub,
      Options options);

  Options options() override { return options_; }

  future<StatusOr<google::cloud::dataplex::v1::DataScan>> CreateDataScan(
      google::cloud::dataplex::v1::CreateDataScanRequest const& request)
      override;

  future<StatusOr<google::cloud::dataplex::v1::DataScan>> UpdateDataScan(
      google::cloud::dataplex::v1::UpdateDataScanRequest const& request)
      override;

  future<StatusOr<google::cloud::dataplex::v1::OperationMetadata>>
  DeleteDataScan(google::cloud::dataplex::v1::DeleteDataScanRequest const&
                     request) override;

  StatusOr<google::cloud::dataplex::v1::DataScan> GetDataScan(
      google::cloud::dataplex::v1::GetDataScanRequest const& request) override;

  StreamRange<google::cloud::dataplex::v1::DataScan> ListDataScans(
      google::cloud::dataplex::v1::ListDataScansRequest request) override;

  StatusOr<google::cloud::dataplex::v1::RunDataScanResponse> RunDataScan(
      google::cloud::dataplex::v1::RunDataScanRequest const& request) override;

  StatusOr<google::cloud::dataplex::v1::DataScanJob> GetDataScanJob(
      google::cloud::dataplex::v1::GetDataScanJobRequest const& request)
      override;

  StreamRange<google::cloud::dataplex::v1::DataScanJob> ListDataScanJobs(
      google::cloud::dataplex::v1::ListDataScanJobsRequest request) override;

  StatusOr<google::cloud::dataplex::v1::GenerateDataQualityRulesResponse>
  GenerateDataQualityRules(
      google::cloud::dataplex::v1::GenerateDataQualityRulesRequest const&
          request) override;

 private:
  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<dataplex_v1_internal::DataScanServiceStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_SCAN_CONNECTION_IMPL_H
