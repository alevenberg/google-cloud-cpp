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
// source: google/cloud/bigquery/storage/v1/storage.proto

#include "google/cloud/bigquery/bigquery_write_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

BigQueryWriteConnectionIdempotencyPolicy::
    ~BigQueryWriteConnectionIdempotencyPolicy() = default;

namespace {
class DefaultBigQueryWriteConnectionIdempotencyPolicy
    : public BigQueryWriteConnectionIdempotencyPolicy {
 public:
  ~DefaultBigQueryWriteConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<BigQueryWriteConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<DefaultBigQueryWriteConnectionIdempotencyPolicy>(
        *this);
  }

  Idempotency CreateWriteStream(
      google::cloud::bigquery::storage::v1::CreateWriteStreamRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetWriteStream(
      google::cloud::bigquery::storage::v1::GetWriteStreamRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency FinalizeWriteStream(
      google::cloud::bigquery::storage::v1::FinalizeWriteStreamRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency BatchCommitWriteStreams(
      google::cloud::bigquery::storage::v1::
          BatchCommitWriteStreamsRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency FlushRows(
      google::cloud::bigquery::storage::v1::FlushRowsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<BigQueryWriteConnectionIdempotencyPolicy>
MakeDefaultBigQueryWriteConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultBigQueryWriteConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery
}  // namespace cloud
}  // namespace google
