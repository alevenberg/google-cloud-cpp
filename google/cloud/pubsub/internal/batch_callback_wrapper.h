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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_WRAPPER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_WRAPPER_H

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/status_or.h"
#include <google/pubsub/v1/pubsub.pb.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Tracing implementation.
 * */
class BatchCallbackWrapper : public BatchCallback {
 public:
  using Callback = std::function<void(StreamingPullResponse)>;

  explicit BatchCallbackWrapper(std::shared_ptr<BatchCallback> child,
                                Callback wrapper)
      : child_(std::move(child)), wrapper_(std::move(wrapper)) {}
  ~BatchCallbackWrapper() override = default;

  void operator()(StreamingPullResponse response) override {
    child_->operator()(response);
    wrapper_(response);
  };
  void operator()(MessageCallback::MessageAndHandler m) override {
     child_->operator()(std::move(m));
  };
  void AckMessage(std::string const& ack_id) override {
    child_->AckMessage(ack_id);
  }
  void NackMessage(std::string const& ack_id) override {
    child_->NackMessage(ack_id);
  }
  void BulkNack(std::vector<std::string> ack_ids) override {
    child_->BulkNack(ack_ids);
  }
  void ExtendLeases(google::pubsub::v1::ModifyAckDeadlineRequest r) override {
    child_->ExtendLeases(r);
  }
  std::shared_ptr<SubscribeData> GetSubscribeDataFromAckId(
      std::string ack_id) override {
    return std::make_shared<NoopSubscribeData>();
  }

  void EndAckMessage(std::string const& ack_id) override {
    child_->EndAckMessage(ack_id);
  };
  void EndNackMessage(std::string const& ack_id) override {
    child_->EndNackMessage(ack_id);
  };
  void EndBulkNack(std::vector<std::string> ack_ids) override {
    child_->EndBulkNack(ack_ids);
  };
  void EndExtendLeases(google::pubsub::v1::ModifyAckDeadlineRequest r) override {
    child_->EndExtendLeases(r);
  };
  std::shared_ptr<MessageCallback> GetMessageCallback() override {
    return child_->GetMessageCallback();
  }
  void operator()(MessageCallback::ReceivedMessage m) override {
    child_->GetMessageCallback()->operator()(std::move(m));
  };
   void StartFlowControl(
      google::pubsub::v1::ReceivedMessage message)  override{
        child_->StartFlowControl(message);
      };
   void EndFlowControl(std::string message_id) override {
    child_->EndFlowControl(message_id);
   };

      void StartSpan(
      google::pubsub::v1::ReceivedMessage message)  override{
        child_->StartSpan(message);
      };
   void EndSpan(std::string message_id) override {
    child_->EndSpan(message_id);
   };
      void StartModack(std::string const& ack_id)override {
          child_->StartModack(ack_id);
      };
   void EndModack(std::string const& ack_id)override {
    child_->EndModack(ack_id);
   };
  std::shared_ptr<BatchCallback> child_;
  Callback wrapper_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_BATCH_CALLBACK_WRAPPER_H
