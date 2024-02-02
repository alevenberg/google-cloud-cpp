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

#include "google/cloud/bigquery/models/v2/internal/models_rest_stub.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/rest_stub_helpers.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/models/v2/models.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_models_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DefaultModelsRestStub::DefaultModelsRestStub(Options options)
    : service_(rest_internal::MakePooledRestClient(
          options.get<EndpointOption>(), options)),
      options_(std::move(options)) {}

DefaultModelsRestStub::DefaultModelsRestStub(
    std::shared_ptr<rest_internal::RestClient> service,
    Options options)
    : service_(std::move(service)),
      options_(std::move(options)) {}

Status DefaultModelsRestStub::DeleteModel(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::models::v2::DeleteModelRequest const& request) {
  return rest_internal::Delete(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "models", "/", request.model_id()));
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
DefaultModelsRestStub::GetModel(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::models::v2::GetModelRequest const& request) {
  return rest_internal::Get<google::cloud::cpp::bigquery::v2::Model>(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "models", "/", request.model_id()));
}

StatusOr<google::cloud::cpp::bigquery::v2::ListModelsResponse>
DefaultModelsRestStub::ListModels(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::models::v2::ListModelsRequest const& request) {
  return rest_internal::Get<google::cloud::cpp::bigquery::v2::ListModelsResponse>(
      *service_, rest_context, request, false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "models"),
      rest_internal::TrimEmptyQueryParameters({std::make_pair("max_results", std::to_string(request.max_results())),
        std::make_pair("page_token", request.page_token())}));
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
DefaultModelsRestStub::PatchModel(
      google::cloud::rest_internal::RestContext& rest_context,
      Options const& options,
      google::cloud::cpp::bigquery::models::v2::PatchModelRequest const& request) {
  return rest_internal::Patch<google::cloud::cpp::bigquery::v2::Model>(
      *service_, rest_context, request.model_resource(), false,
      absl::StrCat("/", "bigquery", "/", rest_internal::DetermineApiVersion("v2", options), "/", "projects", "/", request.project_id(), "/", "datasets", "/", request.dataset_id(), "/", "models", "/", request.model_id()));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_models_v2_internal
}  // namespace cloud
}  // namespace google
