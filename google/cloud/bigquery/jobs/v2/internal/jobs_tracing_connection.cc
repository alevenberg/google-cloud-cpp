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

#include "google/cloud/bigquery/jobs/v2/internal/jobs_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_jobs_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

JobsTracingConnection::JobsTracingConnection(
    std::shared_ptr<bigquery_jobs_v2::JobsConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::cpp::bigquery::v2::JobCancelResponse>
JobsTracingConnection::Cancel(google::cloud::cpp::bigquery::jobs::v2::CancelRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::Cancel");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->Cancel(request));
}

Status
JobsTracingConnection::DeleteJob(google::cloud::cpp::bigquery::jobs::v2::DeleteJobRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::DeleteJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteJob(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Job>
JobsTracingConnection::GetJob(google::cloud::cpp::bigquery::jobs::v2::GetJobRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::GetJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetJob(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::GetQueryResultsResponse>
JobsTracingConnection::GetQueryResults(google::cloud::cpp::bigquery::jobs::v2::GetQueryResultsRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::GetQueryResults");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetQueryResults(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Job>
JobsTracingConnection::InsertJob(google::cloud::cpp::bigquery::jobs::v2::InsertJobRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::InsertJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->InsertJob(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::JobList>
JobsTracingConnection::ListJobs(google::cloud::cpp::bigquery::jobs::v2::ListJobsRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::ListJobs");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ListJobs(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::QueryResponse>
JobsTracingConnection::Query(google::cloud::cpp::bigquery::jobs::v2::QueryRequest const& request) {
  auto span = internal::MakeSpan("bigquery_jobs_v2::JobsConnection::Query");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->Query(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<bigquery_jobs_v2::JobsConnection>
MakeJobsTracingConnection(
    std::shared_ptr<bigquery_jobs_v2::JobsConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<JobsTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_jobs_v2_internal
}  // namespace cloud
}  // namespace google
