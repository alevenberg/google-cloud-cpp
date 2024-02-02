// Copyright 2024 Google LLC
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
// source: google/cloud/bigquery/routines/v2/routines.proto

#include "google/cloud/bigquery/routines/v2/routines_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_routines_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

RoutinesConnectionIdempotencyPolicy::~RoutinesConnectionIdempotencyPolicy() = default;

std::unique_ptr<RoutinesConnectionIdempotencyPolicy>
RoutinesConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<RoutinesConnectionIdempotencyPolicy>(*this);
}

Idempotency RoutinesConnectionIdempotencyPolicy::DeleteRoutine(google::cloud::cpp::bigquery::routines::v2::DeleteRoutineRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency RoutinesConnectionIdempotencyPolicy::GetRoutine(google::cloud::cpp::bigquery::routines::v2::GetRoutineRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency RoutinesConnectionIdempotencyPolicy::InsertRoutine(google::cloud::cpp::bigquery::routines::v2::InsertRoutineRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency RoutinesConnectionIdempotencyPolicy::ListRoutines(google::cloud::cpp::bigquery::routines::v2::ListRoutinesRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency RoutinesConnectionIdempotencyPolicy::UpdateRoutine(google::cloud::cpp::bigquery::routines::v2::UpdateRoutineRequest const&) {
  return Idempotency::kIdempotent;
}

std::unique_ptr<RoutinesConnectionIdempotencyPolicy>
    MakeDefaultRoutinesConnectionIdempotencyPolicy() {
  return std::make_unique<RoutinesConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_routines_v2
}  // namespace cloud
}  // namespace google
