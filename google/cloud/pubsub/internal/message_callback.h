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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_CALLBACK_H

#include "google/cloud/pubsub/exactly_once_ack_handler.h"
#include "google/cloud/pubsub/message.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <absl/types/any.h>
#include <string>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class BatchCallback;
/**
 * Define the interface to receive a single message from Cloud Pub/Sub.
 */
class MessageCallback {
 public:
  virtual ~MessageCallback() = default;

  struct ReceivedMessage {
    // A received message.
    google::pubsub::v1::ReceivedMessage message;
    // A single subscribe span, if it exists.
    absl::optional<absl::any> subscribe_span = absl::nullopt;
  };
  struct MessageAndHandler {
    pubsub::Message message;
    std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> ack_handler;
    // A single subscribe span, if it exists.
    absl::optional<absl::any> subscribe_span = absl::nullopt;
  };

  virtual void operator()(MessageAndHandler m) = 0;
  virtual void operator()(ReceivedMessage message) = 0;
  virtual void StartFlowControl(ReceivedMessage message) = 0;
  virtual void EndFlowControl() = 0;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_CALLBACK_H
