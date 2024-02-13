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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_DEFAULT_BATCH_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_DEFAULT_BATCH_CALLBACK_H

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/pubsub.pb.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Default implementation.
 */
class DefaultBatchCallback : public BatchCallback {
 public:
  using Callback = std::function<void(StreamingPullResponse)>;

  explicit DefaultBatchCallback(Callback callback)
      : callback_(std::move(callback)) {}
  ~DefaultBatchCallback() override = default;
  DefaultBatchCallback(Callback callback,
                       std::shared_ptr<MessageCallback> message_callback)
      : callback_(std::move(callback)),
        message_callback_(std::move(message_callback)) {}


  void operator()(StreamingPullResponse response) override {
    callback_(std::move(response));
  };
  void operator()(
      pubsub::Message m,
      std::unique_ptr<pubsub::ExactlyOnceAckHandler::Impl> ack) override {
     message_callback_->operator()(std::move(m), std::move(ack));
  };
  void operator()(MessageCallback::ReceivedMessage m) override {
    message_callback_->operator()(std::move(m));
  };
  void AckMessage(std::string const& ack_id) override{};
  void NackMessage(std::string const& ack_id) override{};
  void BulkNack(std::vector<std::string> ack_ids) override{};
  void ExtendLeases(std::vector<std::string> ack_ids,
                    std::chrono::seconds extension) override {}

  void EndAckMessage(std::string const& ack_id) override{};
  void EndNackMessage(std::string const& ack_id) override{};
  void EndBulkNack(std::vector<std::string> ack_ids) override{};
  void EndExtendLeases(std::vector<std::string> ack_ids,
                       std::chrono::seconds extension) override{};

  std::shared_ptr<SubscribeData> GetSubscribeDataFromAckId(
      std::string ack_id) override {
    return std::make_shared<NoopSubscribeData>();
  }
  std::shared_ptr<MessageCallback> GetMessageCallback(
  ) override {
    return message_callback_;
  }

 private:
  Callback callback_;
  std::shared_ptr<MessageCallback> message_callback_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_DEFAULT_BATCH_CALLBACK_H
