// Copyright 2022 Google LLC
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
// source: google/cloud/kms/v1/ekm_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_EKM_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_EKM_CONNECTION_H

#include "google/cloud/kms/v1/ekm_connection_idempotency_policy.h"
#include "google/cloud/kms/v1/internal/ekm_retry_traits.h"
#include "google/cloud/kms/v1/internal/ekm_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace kms_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using EkmServiceRetryPolicy = ::google::cloud::internal::TraitBasedRetryPolicy<
    kms_v1_internal::EkmServiceRetryTraits>;

using EkmServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        kms_v1_internal::EkmServiceRetryTraits>;

using EkmServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        kms_v1_internal::EkmServiceRetryTraits>;

/**
 * The `EkmServiceConnection` object for `EkmServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `EkmServiceClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `EkmServiceClient`.
 *
 * To create a concrete instance, see `MakeEkmServiceConnection()`.
 *
 * For mocking, see `kms_v1_mocks::MockEkmServiceConnection`.
 */
class EkmServiceConnection {
 public:
  virtual ~EkmServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StreamRange<google::cloud::kms::v1::EkmConnection> ListEkmConnections(
      google::cloud::kms::v1::ListEkmConnectionsRequest request);

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> GetEkmConnection(
      google::cloud::kms::v1::GetEkmConnectionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> CreateEkmConnection(
      google::cloud::kms::v1::CreateEkmConnectionRequest const& request);

  virtual StatusOr<google::cloud::kms::v1::EkmConnection> UpdateEkmConnection(
      google::cloud::kms::v1::UpdateEkmConnectionRequest const& request);
};

/**
 * A factory function to construct an object of type `EkmServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of EkmServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `EkmServiceConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::kms_v1::EkmServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `EkmServiceConnection` created by
 * this function.
 */
std::shared_ptr<EkmServiceConnection> MakeEkmServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace kms_v1
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_KMS_V1_EKM_CONNECTION_H
