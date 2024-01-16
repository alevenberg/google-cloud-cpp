// Copyright 2024 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_H

#include "google/cloud/pubsub/internal/subscribe_data.h"
#include "google/cloud/pubsub/message.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <string>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Define the interface to receive message batches from Cloud Pub/Sub.
 */
class BatchCallback {
 public:
  virtual ~BatchCallback() = default;

  virtual void operator()(
      StatusOr<google::pubsub::v1::StreamingPullResponse> response) = 0;
  // Add a function to add the ack event
  virtual void AckMessage(std::string const& ack_id) = 0;

  // Add a function to add the nack event
  virtual void NackMessage(std::string const& ack_id) = 0;

  // Add a function to add bulk nack event
  virtual void BulkNack(std::vector<std::string> ack_ids) = 0;

  // Add a function to add the extennd event
  virtual void ExtendLeases(std::vector<std::string> ack_ids,
                            std::chrono::seconds extension) = 0;

  virtual SubscribeData GetSubscribeDataFromAckId(std::string ack_id) = 0;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_H
