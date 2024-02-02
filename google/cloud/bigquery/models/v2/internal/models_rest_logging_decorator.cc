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

#include "google/cloud/bigquery/models/v2/internal/models_rest_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_models_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ModelsRestLogging::ModelsRestLogging(
    std::shared_ptr<ModelsRestStub> child,
    TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

Status
ModelsRestLogging::DeleteModel(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::models::v2::DeleteModelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::models::v2::DeleteModelRequest const& request) {
        return child_->DeleteModel(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsRestLogging::GetModel(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::models::v2::GetModelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::models::v2::GetModelRequest const& request) {
        return child_->GetModel(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::ListModelsResponse>
ModelsRestLogging::ListModels(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::models::v2::ListModelsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::models::v2::ListModelsRequest const& request) {
        return child_->ListModels(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::Model>
ModelsRestLogging::PatchModel(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::models::v2::PatchModelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::models::v2::PatchModelRequest const& request) {
        return child_->PatchModel(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_models_v2_internal
}  // namespace cloud
}  // namespace google
