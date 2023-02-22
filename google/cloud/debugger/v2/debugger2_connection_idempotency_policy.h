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

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/devtools/clouddebugger/v2/debugger.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/devtools/clouddebugger/v2/debugger.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace debugger_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class Debugger2ConnectionIdempotencyPolicy {
 public:
  virtual ~Debugger2ConnectionIdempotencyPolicy();

  /// Create a new copy of this object.
  virtual std::unique_ptr<Debugger2ConnectionIdempotencyPolicy> clone() const;

  virtual google::cloud::Idempotency SetBreakpoint(
      google::devtools::clouddebugger::v2::SetBreakpointRequest const& request);

  virtual google::cloud::Idempotency GetBreakpoint(
      google::devtools::clouddebugger::v2::GetBreakpointRequest const& request);

  virtual google::cloud::Idempotency DeleteBreakpoint(
      google::devtools::clouddebugger::v2::DeleteBreakpointRequest const&
          request);

  virtual google::cloud::Idempotency ListBreakpoints(
      google::devtools::clouddebugger::v2::ListBreakpointsRequest const&
          request);

  virtual google::cloud::Idempotency ListDebuggees(
      google::devtools::clouddebugger::v2::ListDebuggeesRequest const& request);
};

std::unique_ptr<Debugger2ConnectionIdempotencyPolicy>
MakeDefaultDebugger2ConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DEBUGGER_V2_DEBUGGER2_CONNECTION_IDEMPOTENCY_POLICY_H
