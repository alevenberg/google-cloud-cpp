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
// source: google/cloud/bigquery/datasets/v2/datasets.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_INTERNAL_DATASETS_REST_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_INTERNAL_DATASETS_REST_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/internal/rest_client.h"
#include "google/cloud/internal/rest_context.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/bigquery/datasets/v2/datasets.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_datasets_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DatasetsRestStub {
 public:
  virtual ~DatasetsRestStub() = default;

  virtual Status DeleteDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::DeleteDatasetRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::Dataset> GetDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::GetDatasetRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::Dataset> InsertDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::InsertDatasetRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::DatasetList> ListDatasets(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::ListDatasetsRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::Dataset> PatchDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::PatchDatasetRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::Dataset> Undelete(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::UndeleteRequest const& request) = 0;

  virtual StatusOr<google::cloud::cpp::bigquery::v2::Dataset> UpdateDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::UpdateDatasetRequest const& request) = 0;
};

class DefaultDatasetsRestStub : public DatasetsRestStub {
 public:
  ~DefaultDatasetsRestStub() override = default;

  explicit DefaultDatasetsRestStub(Options options);
  DefaultDatasetsRestStub(
      std::shared_ptr<rest_internal::RestClient> service,
      Options options);

  Status DeleteDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::DeleteDatasetRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Dataset> GetDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::GetDatasetRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Dataset> InsertDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::InsertDatasetRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::DatasetList> ListDatasets(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::ListDatasetsRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Dataset> PatchDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::PatchDatasetRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Dataset> Undelete(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::UndeleteRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::Dataset> UpdateDataset(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options, google::cloud::cpp::bigquery::datasets::v2::UpdateDatasetRequest const& request) override;

 private:
  std::shared_ptr<rest_internal::RestClient> service_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_datasets_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_INTERNAL_DATASETS_REST_STUB_H
