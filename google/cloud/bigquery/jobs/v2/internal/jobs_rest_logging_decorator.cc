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
// source: google/cloud/bigquery/jobs/v2/jobs.proto

#include "google/cloud/bigquery/jobs/v2/internal/jobs_rest_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_jobs_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

JobsRestLogging::JobsRestLogging(
    std::shared_ptr<JobsRestStub> child,
    TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)), tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::cpp::bigquery::v2::JobCancelResponse>
JobsRestLogging::Cancel(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::CancelRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::CancelRequest const& request) {
        return child_->Cancel(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

Status
JobsRestLogging::DeleteJob(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::DeleteJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::DeleteJobRequest const& request) {
        return child_->DeleteJob(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::Job>
JobsRestLogging::GetJob(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::GetJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::GetJobRequest const& request) {
        return child_->GetJob(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::GetQueryResultsResponse>
JobsRestLogging::GetQueryResults(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::GetQueryResultsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::GetQueryResultsRequest const& request) {
        return child_->GetQueryResults(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::Job>
JobsRestLogging::InsertJob(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::InsertJobRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::InsertJobRequest const& request) {
        return child_->InsertJob(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::JobList>
JobsRestLogging::ListJobs(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::ListJobsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::ListJobsRequest const& request) {
        return child_->ListJobs(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

StatusOr<google::cloud::cpp::bigquery::v2::QueryResponse>
JobsRestLogging::Query(
    rest_internal::RestContext& rest_context,
    Options const& options,
    google::cloud::cpp::bigquery::jobs::v2::QueryRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](rest_internal::RestContext& rest_context,
             Options const& options,
             google::cloud::cpp::bigquery::jobs::v2::QueryRequest const& request) {
        return child_->Query(rest_context, options, request);
      },
      rest_context, options, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_jobs_v2_internal
}  // namespace cloud
}  // namespace google
