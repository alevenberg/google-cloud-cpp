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
// source: google/cloud/bigquery/projects/v2/projects.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_PROJECTS_V2_INTERNAL_PROJECTS_REST_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_PROJECTS_V2_INTERNAL_PROJECTS_REST_CONNECTION_IMPL_H

#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/bigquery/projects/v2/internal/projects_rest_stub.h"
#include "google/cloud/bigquery/projects/v2/internal/projects_retry_traits.h"
#include "google/cloud/bigquery/projects/v2/projects_connection.h"
#include "google/cloud/bigquery/projects/v2/projects_connection_idempotency_policy.h"
#include "google/cloud/bigquery/projects/v2/projects_options.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_projects_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ProjectsRestConnectionImpl
    : public bigquery_projects_v2::ProjectsConnection {
 public:
  ~ProjectsRestConnectionImpl() override = default;

  ProjectsRestConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<bigquery_projects_v2_internal::ProjectsRestStub> stub,
    Options options);

  Options options() override { return options_; }

  StatusOr<google::cloud::cpp::bigquery::v2::GetServiceAccountResponse>
  GetServiceAccount(google::cloud::cpp::bigquery::projects::v2::GetServiceAccountRequest const& request) override;

  StatusOr<google::cloud::cpp::bigquery::v2::ProjectList>
  ListProjects(google::cloud::cpp::bigquery::projects::v2::ListProjectsRequest const& request) override;

 private:
  static std::unique_ptr<bigquery_projects_v2::ProjectsRetryPolicy>
  retry_policy(Options const& options) {
    return options.get<bigquery_projects_v2::ProjectsRetryPolicyOption>()->clone();
  }

  static std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
    return options.get<bigquery_projects_v2::ProjectsBackoffPolicyOption>()->clone();
  }

  static std::unique_ptr<bigquery_projects_v2::ProjectsConnectionIdempotencyPolicy>
  idempotency_policy(Options const& options) {
    return options.get<bigquery_projects_v2::ProjectsConnectionIdempotencyPolicyOption>()->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<bigquery_projects_v2_internal::ProjectsRestStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_projects_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_PROJECTS_V2_INTERNAL_PROJECTS_REST_CONNECTION_IMPL_H
