// Copyright 2021 Google LLC
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
// source: google/spanner/admin/instance/v1/spanner_instance_admin.proto

#include "google/cloud/spanner/admin/internal/instance_admin_option_defaults.h"
#include "google/cloud/spanner/admin/instance_admin_connection.h"
#include "google/cloud/spanner/admin/instance_admin_options.h"
#include "google/cloud/common_options.h"
#include "google/cloud/connection_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/user_agent_prefix.h"
#include "google/cloud/options.h"
#include <memory>

namespace google {
namespace cloud {
namespace spanner_admin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options InstanceAdminDefaultOptions(Options options) {
  if (!options.has<EndpointOption>()) {
    auto env = internal::GetEnv("GOOGLE_CLOUD_CPP_SPANNER_DEFAULT_ENDPOINT");
    options.set<EndpointOption>(
        env && !env->empty() ? *env : "spanner.googleapis.com");
  }
  if (auto emulator = internal::GetEnv("SPANNER_EMULATOR_HOST")) {
    options.set<EndpointOption>(*emulator).set<GrpcCredentialOption>(
        grpc::InsecureChannelCredentials());
  }
  if (!options.has<GrpcCredentialOption>()) {
    options.set<GrpcCredentialOption>(grpc::GoogleDefaultCredentials());
  }
  if (!options.has<TracingComponentsOption>()) {
    options.set<TracingComponentsOption>(internal::DefaultTracingComponents());
  }
  if (!options.has<GrpcTracingOptionsOption>()) {
    options.set<GrpcTracingOptionsOption>(internal::DefaultTracingOptions());
  }
  auto& products = options.lookup<UserAgentProductsOption>();
  products.insert(products.begin(), google::cloud::internal::UserAgentPrefix());

  if (!options.has<spanner_admin::InstanceAdminRetryPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminRetryPolicyOption>(
        spanner_admin::InstanceAdminLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<spanner_admin::InstanceAdminBackoffPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminBackoffPolicyOption>(
        ExponentialBackoffPolicy(std::chrono::seconds(1),
                                 std::chrono::minutes(5), kBackoffScaling)
            .clone());
  }
  if (!options.has<spanner_admin::InstanceAdminPollingPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminPollingPolicyOption>(
        GenericPollingPolicy<
            spanner_admin::InstanceAdminRetryPolicyOption::Type,
            spanner_admin::InstanceAdminBackoffPolicyOption::Type>(
            options.get<spanner_admin::InstanceAdminRetryPolicyOption>()
                ->clone(),
            options.get<spanner_admin::InstanceAdminBackoffPolicyOption>()
                ->clone())
            .clone());
  }
  if (!options.has<
          spanner_admin::InstanceAdminConnectionIdempotencyPolicyOption>()) {
    options.set<spanner_admin::InstanceAdminConnectionIdempotencyPolicyOption>(
        spanner_admin::MakeDefaultInstanceAdminConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace spanner_admin_internal
}  // namespace cloud
}  // namespace google
