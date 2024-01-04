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

#include "google/cloud/pubsub/internal/ack_handler_wrapper.h"
#include "google/cloud/pubsub/subscription.h"
#include "google/cloud/internal/opentelemetry.h"
#include "google/cloud/log.h"
#include <opentelemetry/trace/scope.h>

namespace google {
namespace cloud {
namespace pubsub_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

void AckHandlerWrapper::ack() {
  opentelemetry::trace::StartSpanOptions options;
  opentelemetry::context::Context root_context;
  // TODO(#13287): Use the constant instead of the string.
  // Setting a span as a root span was added in OTel v1.13+. It is a no-op for
  // earlier versions.
  // options.parent = root_context.SetValue(
      // /*opentelemetry::trace::kIsRootSpanKey=*/"is_root_span", true);
  options.kind = opentelemetry::trace::SpanKind::kClient;
  auto span =
      internal::MakeSpan(subscription_.subscription_id() + " settle", options);
  auto scope = internal::OTelScope(span);
  auto f = impl_->ack();
  if (message_id_.empty()) return;
  f.then([id = std::move(message_id_)](auto f) {
     auto status = f.get();
     if (status.ok()) return;
     GCP_LOG(WARNING) << "error while trying to ack(), status=" << status
                      << ", message_id=" << id;
   })
      .then([oc = opentelemetry::context::RuntimeContext::GetCurrent(),
             span = std::move(span)](auto) {
        internal::DetachOTelContext(oc);
        span->End();
      });
}

void AckHandlerWrapper::nack() {
  auto span = internal::MakeSpan("nack");
  auto f = impl_->nack();
  if (message_id_.empty()) return;
  f.then([id = std::move(message_id_)](auto f) {
     auto status = f.get();
     if (status.ok()) return;
     GCP_LOG(WARNING) << "error while trying to nack(), status=" << status
                      << ", message_id=" << id;
   }).then([span = span](auto) { span->End(); });
}

std::int32_t AckHandlerWrapper::delivery_attempt() const {
  return impl_->delivery_attempt();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsub_internal
}  // namespace cloud
}  // namespace google
