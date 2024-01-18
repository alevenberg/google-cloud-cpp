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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_QUEUE_MESSAGE_CALLBACK_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_QUEUE_MESSAGE_CALLBACK_H

#include "google/cloud/pubsub/internal/batch_callback.h"
#include "google/cloud/pubsub/internal/message_callback.h"
#include "google/cloud/pubsub/internal/message_propagator.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/pubsub/version.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/status_or.h"
#include "opentelemetry/context/propagation/text_map_propagator.h"
#include "opentelemetry/trace/propagation/http_trace_context.h"
#include "opentelemetry/trace/semantic_conventions.h"
#include "opentelemetry/trace/span_startoptions.h"
#include <google/pubsub/v1/pubsub.pb.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Tracing implementation.
 * */
class MessageQueueMessageCallback : public MessageCallback {
 public:
  explicit MessageQueueMessageCallback(std::unique_ptr<MessageCallback> child)
      : child_(std::move(child)) {}
  ~MessageQueueMessageCallback() override = default;
  using MessageCallback =
      std::function<void(google::pubsub::v1::ReceivedMessage)>;
  explicit DefaultMessageCallback(MessageCallback message_callback)
      : message_callback_(std::move(message_callback)) {}
  ~DefaultMessageCallback() override = default;

  void operator()(google::pubsub::v1::ReceivedMessage m) override {
    message_callback_(std::move(m));
  };

  void SaveBatchCallback(std::shared_ptr<BatchCallback> cb) override {
    batch_callback_ = cb;
  };

  std::shared_ptr<BatchCallback> batch_callback_;
  std::unique_ptr<MessageCallback> child_;
  MessageCallback message_callback_;
  opentelemetry::nostd::shared_ptr<opentelemetry::trace::Span> subscribe_span_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_INTERNAL_MESSAGE_QUEUE_MESSAGE_CALLBACK_H
