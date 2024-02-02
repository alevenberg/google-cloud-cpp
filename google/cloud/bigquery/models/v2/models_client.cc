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
// source: google/cloud/bigquery/models/v2/models.proto

#include "google/cloud/bigquery/models/v2/models_client.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_models_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ModelsClient::ModelsClient(
    std::shared_ptr<ModelsConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(std::move(opts),
      connection_->options())) {}
ModelsClient::~ModelsClient() = default;

Status
ModelsClient::DeleteModel(std::string const& project_id, std::string const& dataset_id, std::string const& model_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::models::v2::DeleteModelRequest request;
  request.set_project_id(project_id);
  request.set_dataset_id(dataset_id);
  request.set_model_id(model_id);
  return connection_->DeleteModel(request);
}

Status
ModelsClient::DeleteModel(google::cloud::cpp::bigquery::models::v2::DeleteModelRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteModel(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsClient::GetModel(std::string const& project_id, std::string const& dataset_id, std::string const& model_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::models::v2::GetModelRequest request;
  request.set_project_id(project_id);
  request.set_dataset_id(dataset_id);
  request.set_model_id(model_id);
  return connection_->GetModel(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsClient::GetModel(google::cloud::cpp::bigquery::models::v2::GetModelRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetModel(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::ListModelsResponse>
ModelsClient::ListModels(std::string const& project_id, std::string const& dataset_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::models::v2::ListModelsRequest request;
  request.set_project_id(project_id);
  request.set_dataset_id(dataset_id);
  return connection_->ListModels(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::ListModelsResponse>
ModelsClient::ListModels(google::cloud::cpp::bigquery::models::v2::ListModelsRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListModels(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsClient::PatchModel(std::string const& project_id, std::string const& dataset_id, std::string const& model_id, google::cloud::cpp::bigquery::v2::Model const& model_resource, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::cpp::bigquery::models::v2::PatchModelRequest request;
  request.set_project_id(project_id);
  request.set_dataset_id(dataset_id);
  request.set_model_id(model_id);
  *request.mutable_model_resource() = model_resource;
  return connection_->PatchModel(request);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsClient::PatchModel(google::cloud::cpp::bigquery::models::v2::PatchModelRequest const& request, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->PatchModel(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_models_v2
}  // namespace cloud
}  // namespace google
