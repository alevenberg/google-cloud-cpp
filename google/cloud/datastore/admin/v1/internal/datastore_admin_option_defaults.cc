// Copyright 2023 Google LLC
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
// source: google/datastore/admin/v1/datastore_admin.proto

#include "google/cloud/datastore/admin/v1/internal/datastore_admin_option_defaults.h"
#include "google/cloud/datastore/admin/v1/datastore_admin_connection.h"
#include "google/cloud/datastore/admin/v1/datastore_admin_options.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/populate_grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace datastore_admin_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

namespace {
auto constexpr kBackoffScaling = 2.0;
}  // namespace

Options DatastoreAdminDefaultOptions(Options options) {
  options = google::cloud::internal::PopulateCommonOptions(
      std::move(options), "GOOGLE_CLOUD_CPP_DATASTORE_ADMIN_ENDPOINT", "",
      "GOOGLE_CLOUD_CPP_DATASTORE_ADMIN_AUTHORITY", "datastore.googleapis.com");
  options =
      google::cloud::internal::PopulateGrpcOptions(std::move(options), "");
  if (!options.has<datastore_admin_v1::DatastoreAdminRetryPolicyOption>()) {
    options.set<datastore_admin_v1::DatastoreAdminRetryPolicyOption>(
        datastore_admin_v1::DatastoreAdminLimitedTimeRetryPolicy(
            std::chrono::minutes(30))
            .clone());
  }
  if (!options.has<datastore_admin_v1::DatastoreAdminBackoffPolicyOption>()) {
    options.set<datastore_admin_v1::DatastoreAdminBackoffPolicyOption>(
        ExponentialBackoffPolicy(
            std::chrono::seconds(0), std::chrono::seconds(1),
            std::chrono::minutes(5), kBackoffScaling, kBackoffScaling)
            .clone());
  }
  if (!options.has<datastore_admin_v1::DatastoreAdminPollingPolicyOption>()) {
    options.set<datastore_admin_v1::DatastoreAdminPollingPolicyOption>(
        GenericPollingPolicy<
            datastore_admin_v1::DatastoreAdminRetryPolicyOption::Type,
            datastore_admin_v1::DatastoreAdminBackoffPolicyOption::Type>(
            options.get<datastore_admin_v1::DatastoreAdminRetryPolicyOption>()
                ->clone(),
            ExponentialBackoffPolicy(std::chrono::seconds(1),
                                     std::chrono::minutes(5), kBackoffScaling)
                .clone())
            .clone());
  }
  if (!options.has<datastore_admin_v1::
                       DatastoreAdminConnectionIdempotencyPolicyOption>()) {
    options.set<
        datastore_admin_v1::DatastoreAdminConnectionIdempotencyPolicyOption>(
        datastore_admin_v1::
            MakeDefaultDatastoreAdminConnectionIdempotencyPolicy());
  }

  return options;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastore_admin_v1_internal
}  // namespace cloud
}  // namespace google
