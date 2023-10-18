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
// source: google/pubsub/v1/pubsub.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_ADMIN_SUBSCRIPTION_ADMIN_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_ADMIN_SUBSCRIPTION_ADMIN_CONNECTION_H

#include "google/cloud/backoff_policy.h"
#include "google/cloud/internal/retry_policy_impl.h"
#include "google/cloud/options.h"
#include "google/cloud/pubsub/admin/internal/subscription_admin_retry_traits.h"
#include "google/cloud/pubsub/admin/subscription_admin_connection_idempotency_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace pubsub_admin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN


/// The retry policy for `SubscriptionAdminConnection`.
class SubscriptionAdminRetryPolicy : public ::google::cloud::RetryPolicy {
 public:
  /// Creates a new instance of the policy, reset to the initial state.
  virtual std::unique_ptr<SubscriptionAdminRetryPolicy> clone() const = 0;
};

/**
 * A retry policy for `SubscriptionAdminConnection` based on counting errors.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - More than a prescribed number of transient failures is detected.
 *
 */
class SubscriptionAdminLimitedErrorCountRetryPolicy : public SubscriptionAdminRetryPolicy {
 public:
  /**
   * Create an instance that tolerates up to @p maximum_failures transient
   * errors.
   *
   * @note Disable the retry loop by providing an instance of this policy with
   *     @p maximum_failures == 0.
   */
  explicit SubscriptionAdminLimitedErrorCountRetryPolicy(int maximum_failures)
    : impl_(maximum_failures) {}

  SubscriptionAdminLimitedErrorCountRetryPolicy(
      SubscriptionAdminLimitedErrorCountRetryPolicy&& rhs) noexcept
    : SubscriptionAdminLimitedErrorCountRetryPolicy(rhs.maximum_failures()) {}
  SubscriptionAdminLimitedErrorCountRetryPolicy(
      SubscriptionAdminLimitedErrorCountRetryPolicy const& rhs) noexcept
    : SubscriptionAdminLimitedErrorCountRetryPolicy(rhs.maximum_failures()) {}

  int maximum_failures() const { return impl_.maximum_failures(); }

  bool OnFailure(Status const& status) override {
    return impl_.OnFailure(status);
  }
  bool IsExhausted() const override { return impl_.IsExhausted(); }
  bool IsPermanentFailure(Status const& status) const override {
    return impl_.IsPermanentFailure(status);
  }
  std::unique_ptr<SubscriptionAdminRetryPolicy> clone() const override {
    return std::make_unique<SubscriptionAdminLimitedErrorCountRetryPolicy>(
        maximum_failures());
  }

  // This is provided only for backwards compatibility.
  using BaseType = SubscriptionAdminRetryPolicy;

 private:
  google::cloud::internal::LimitedErrorCountRetryPolicy<pubsub_admin_internal::SubscriptionAdminRetryTraits> impl_;
};

/**
 * A retry policy for `SubscriptionAdminConnection` based on elapsed time.
 *
 * This policy stops retrying if:
 * - An RPC returns a non-transient error.
 * - The elapsed time in the retry loop exceeds a prescribed duration.
 *
 */
class SubscriptionAdminLimitedTimeRetryPolicy : public SubscriptionAdminRetryPolicy {
 public:
  /**
   * Constructor given a `std::chrono::duration<>` object.
   *
   * @tparam DurationRep a placeholder to match the `Rep` tparam for @p
   *     duration's type. The semantics of this template parameter are
   *     documented in `std::chrono::duration<>`. In brief, the underlying
   *     arithmetic type used to store the number of ticks. For our purposes it
   *     is simply a formal parameter.
   * @tparam DurationPeriod a placeholder to match the `Period` tparam for @p
   *     duration's type. The semantics of this template parameter are
   *     documented in `std::chrono::duration<>`. In brief, the length of the
   *     tick in seconds, expressed as a `std::ratio<>`. For our purposes it is
   *     simply a formal parameter.
   * @param maximum_duration the maximum time allowed before the policy expires.
   *     While the application can express this time in any units they desire,
   *     the class truncates to milliseconds.
   *
   * @see https://en.cppreference.com/w/cpp/chrono/duration for more information
   *     about `std::chrono::duration`.
   */
  template <typename DurationRep, typename DurationPeriod>
  explicit SubscriptionAdminLimitedTimeRetryPolicy(
      std::chrono::duration<DurationRep, DurationPeriod> maximum_duration)
    : impl_(maximum_duration) {}

  SubscriptionAdminLimitedTimeRetryPolicy(SubscriptionAdminLimitedTimeRetryPolicy&& rhs) noexcept
    : SubscriptionAdminLimitedTimeRetryPolicy(rhs.maximum_duration()) {}
  SubscriptionAdminLimitedTimeRetryPolicy(SubscriptionAdminLimitedTimeRetryPolicy const& rhs) noexcept
    : SubscriptionAdminLimitedTimeRetryPolicy(rhs.maximum_duration()) {}

  std::chrono::milliseconds maximum_duration() const {
    return impl_.maximum_duration();
  }

  bool OnFailure(Status const& status) override {
    return impl_.OnFailure(status);
  }
  bool IsExhausted() const override { return impl_.IsExhausted(); }
  bool IsPermanentFailure(Status const& status) const override {
    return impl_.IsPermanentFailure(status);
  }
  std::unique_ptr<SubscriptionAdminRetryPolicy> clone() const override {
    return std::make_unique<SubscriptionAdminLimitedTimeRetryPolicy>(
        maximum_duration());
  }

  // This is provided only for backwards compatibility.
  using BaseType = SubscriptionAdminRetryPolicy;

 private:
  google::cloud::internal::LimitedTimeRetryPolicy<pubsub_admin_internal::SubscriptionAdminRetryTraits> impl_;
};

/**
 * The `SubscriptionAdminConnection` object for `SubscriptionAdminClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `SubscriptionAdminClient`. This allows users to inject custom behavior
 * (e.g., with a Google Mock object) when writing tests that use objects of type
 * `SubscriptionAdminClient`.
 *
 * To create a concrete instance, see `MakeSubscriptionAdminConnection()`.
 *
 * For mocking, see `pubsub_admin_mocks::MockSubscriptionAdminConnection`.
 */
class SubscriptionAdminConnection {
 public:
  virtual ~SubscriptionAdminConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::pubsub::v1::Subscription>
  CreateSubscription(google::pubsub::v1::Subscription const& request);

  virtual StatusOr<google::pubsub::v1::Subscription>
  GetSubscription(google::pubsub::v1::GetSubscriptionRequest const& request);

  virtual StatusOr<google::pubsub::v1::Subscription>
  UpdateSubscription(google::pubsub::v1::UpdateSubscriptionRequest const& request);

  virtual StreamRange<google::pubsub::v1::Subscription>
  ListSubscriptions(google::pubsub::v1::ListSubscriptionsRequest request);

  virtual Status
  DeleteSubscription(google::pubsub::v1::DeleteSubscriptionRequest const& request);

  virtual Status
  ModifyPushConfig(google::pubsub::v1::ModifyPushConfigRequest const& request);

  virtual StatusOr<google::pubsub::v1::Snapshot>
  GetSnapshot(google::pubsub::v1::GetSnapshotRequest const& request);

  virtual StreamRange<google::pubsub::v1::Snapshot>
  ListSnapshots(google::pubsub::v1::ListSnapshotsRequest request);

  virtual StatusOr<google::pubsub::v1::Snapshot>
  CreateSnapshot(google::pubsub::v1::CreateSnapshotRequest const& request);

  virtual StatusOr<google::pubsub::v1::Snapshot>
  UpdateSnapshot(google::pubsub::v1::UpdateSnapshotRequest const& request);

  virtual Status
  DeleteSnapshot(google::pubsub::v1::DeleteSnapshotRequest const& request);

  virtual StatusOr<google::pubsub::v1::SeekResponse>
  Seek(google::pubsub::v1::SeekRequest const& request);
};

/**
 * A factory function to construct an object of type `SubscriptionAdminConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of SubscriptionAdminClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `SubscriptionAdminConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::pubsub_admin::SubscriptionAdminPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `SubscriptionAdminConnection` created by
 * this function.
 */
std::shared_ptr<SubscriptionAdminConnection> MakeSubscriptionAdminConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_admin
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_ADMIN_SUBSCRIPTION_ADMIN_CONNECTION_H
