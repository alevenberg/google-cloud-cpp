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
// source: google/cloud/aiplatform/v1/genai_tuning_service.proto

#include "google/cloud/aiplatform/v1/internal/gen_ai_tuning_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/traced_stream_range.h"
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace aiplatform_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

GenAiTuningServiceTracingConnection::GenAiTuningServiceTracingConnection(
    std::shared_ptr<aiplatform_v1::GenAiTuningServiceConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::aiplatform::v1::TuningJob>
GenAiTuningServiceTracingConnection::CreateTuningJob(
    google::cloud::aiplatform::v1::CreateTuningJobRequest const& request) {
  auto span = internal::MakeSpan(
      "aiplatform_v1::GenAiTuningServiceConnection::CreateTuningJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CreateTuningJob(request));
}

StatusOr<google::cloud::aiplatform::v1::TuningJob>
GenAiTuningServiceTracingConnection::GetTuningJob(
    google::cloud::aiplatform::v1::GetTuningJobRequest const& request) {
  auto span = internal::MakeSpan(
      "aiplatform_v1::GenAiTuningServiceConnection::GetTuningJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetTuningJob(request));
}

StreamRange<google::cloud::aiplatform::v1::TuningJob>
GenAiTuningServiceTracingConnection::ListTuningJobs(
    google::cloud::aiplatform::v1::ListTuningJobsRequest request) {
  auto span = internal::MakeSpan(
      "aiplatform_v1::GenAiTuningServiceConnection::ListTuningJobs");
  internal::OTelScope scope(span);
  auto sr = child_->ListTuningJobs(std::move(request));
  return internal::MakeTracedStreamRange<
      google::cloud::aiplatform::v1::TuningJob>(std::move(span), std::move(sr));
}

Status GenAiTuningServiceTracingConnection::CancelTuningJob(
    google::cloud::aiplatform::v1::CancelTuningJobRequest const& request) {
  auto span = internal::MakeSpan(
      "aiplatform_v1::GenAiTuningServiceConnection::CancelTuningJob");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->CancelTuningJob(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<aiplatform_v1::GenAiTuningServiceConnection>
MakeGenAiTuningServiceTracingConnection(
    std::shared_ptr<aiplatform_v1::GenAiTuningServiceConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn =
        std::make_shared<GenAiTuningServiceTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace aiplatform_v1_internal
}  // namespace cloud
}  // namespace google
