// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_STREAMING_SUBSCRIPTION_BATCH_SOURCE_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_STREAMING_SUBSCRIPTION_BATCH_SOURCE_H

#include "google/cloud/pubsub/backoff_policy.h"
#include "google/cloud/pubsub/internal/session_shutdown_manager.h"
#include "google/cloud/pubsub/internal/subscriber_stub.h"
#include "google/cloud/pubsub/internal/subscription_batch_source.h"
#include "google/cloud/pubsub/retry_policy.h"
#include "google/cloud/pubsub/subscriber_options.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/future.h"
#include "google/cloud/status.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <chrono>
#include <cstdint>
#include <functional>
#include <iosfwd>
#include <string>
#include <vector>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingSubscriptionBatchSource
    : public SubscriptionBatchSource {
 public:
  explicit TracingSubscriptionBatchSource(
      CompletionQueue cq,
      std::shared_ptr<SessionShutdownManager> shutdown_manager,
      std::shared_ptr<SubscriberStub> stub, std::string subscription_full_name,
      std::string client_id, Options opts);

  ~TracingSubscriptionBatchSource() override = default;

  void Start(BatchCallback callback) override;

  void Shutdown() override;
  future<Status> AckMessage(std::string const& ack_id) override;
  future<Status> NackMessage(std::string const& ack_id) override;
  future<Status> BulkNack(std::vector<std::string> ack_ids) override;
  void ExtendLeases(std::vector<std::string> ack_ids,
                    std::chrono::seconds extension) override;

  using AsyncPullStream = google::cloud::AsyncStreamingReadWriteRpc<
      google::pubsub::v1::StreamingPullRequest,
      google::pubsub::v1::StreamingPullResponse>;

  enum class StreamState {
    kNull,
    kActive,
    kDisconnecting,
    kFinishing,
  };

  // The maximum size for `ModifyAckDeadlineRequest` is 512 KB:
  //    https://cloud.google.com/pubsub/quotas#resource_limits
  // Typical ack ids are less than 200 bytes. This value is safe, but there is
  // no need to over optimize it:
  // - Google does not charge for these messages
  // - The value is reached rarely
  // - The CPU costs saved between 2,048 ids per message vs. the theoretical
  //   maximum are minimal
  static int constexpr kMaxAckIdsPerMessage = 2048;
};

std::ostream& operator<<(std::ostream& os,
                         TracingSubscriptionBatchSource::StreamState s);

/// Split @p request such that each request has at most @p max_ack_ids.
std::vector<google::pubsub::v1::ModifyAckDeadlineRequest>
SplitModifyAckDeadline(google::pubsub::v1::ModifyAckDeadlineRequest request,
                       int max_ack_ids);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_STREAMING_SUBSCRIPTION_BATCH_SOURCE_H
