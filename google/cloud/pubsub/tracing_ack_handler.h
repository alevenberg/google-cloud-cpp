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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_TRACING_ACK_HANDLER_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_TRACING_ACK_HANDLER_H

#include "google/cloud/pubsub/version.h"
#include "google/cloud/status.h"
#include <cstdint>
#include <memory>

namespace google {
namespace cloud {
namespace pubsub {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TracingAckHandler {
 public:
  ~TracingAckHandler();

  TracingAckHandler(TracingAckHandler&&) = default;
  TracingAckHandler& operator=(TracingAckHandler&&) = default;

  void ack() && {
    auto impl = std::move(impl_);
    impl->ack();
  }

  void nack() && {
    auto impl = std::move(impl_);
    impl->nack();
  }

  std::int32_t delivery_attempt() const { return impl_->delivery_attempt(); }

  /**
   * Applications may use this constructor in their mocks.
   */
  explicit TracingAckHandler(std::unique_ptr<Impl> impl) : impl_(std::move(impl)) {}

 private:
  std::unique_ptr<Impl> impl_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUB_TRACING_ACK_HANDLER_H
