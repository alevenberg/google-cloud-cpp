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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_SUBSCRIPTION_MESSAGE_QUEUE_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_SUBSCRIPTION_MESSAGE_QUEUE_H

#include "google/cloud/pubsub/internal/session_shutdown_manager.h"
#include "google/cloud/pubsub/internal/subscription_batch_source.h"
#include "google/cloud/pubsub/internal/subscription_message_source.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/future.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/internal/random.h"
#include "google/cloud/status.h"
#include <google/pubsub/v1/pubsub.pb.h>
#include <deque>
#include <functional>
#include <mutex>
#include <string>
#include <unordered_map>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingSubscriptionMessageQueue : public SubscriptionMessageSource {
 public:
  explicit TracingSubscriptionMessageQueue(
      std::shared_ptr<SubscriptionMessageSource> child)
      : child_(std::move(child)) {}

  void Start(std::unique_ptr<MessageCallback> cb) override {
    // auto s = internal::MakeSpan("TracingSubscriptionMessageQueue::Start");
    // auto scope = internal::OTelScope(s);
    child_->Start(std::move(cb));
  };
  void Shutdown() override { child_->Shutdown(); };
  void Read(std::size_t max_callbacks) override {
    auto s = internal::MakeSpan("TracingSubscriptionMessageQueue::Read");
    auto scope = internal::OTelScope(s);
    child_->Read(max_callbacks);
    s->End();
  };
  future<Status> AckMessage(std::string const& ack_id) override {
    return child_->AckMessage(ack_id);
  };
  future<Status> NackMessage(std::string const& ack_id) override {
    return child_->NackMessage(ack_id);
  };

 private:
  std::shared_ptr<SubscriptionMessageSource> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_TRACING_SUBSCRIPTION_MESSAGE_QUEUE_H
