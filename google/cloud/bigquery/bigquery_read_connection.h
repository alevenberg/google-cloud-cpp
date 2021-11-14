// Copyright 2021 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGQUERY_READ_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGQUERY_READ_CONNECTION_H

#include "google/cloud/bigquery/bigquery_read_connection_idempotency_policy.h"
#include "google/cloud/bigquery/internal/bigquery_read_stub.h"
#include "google/cloud/bigquery/retry_traits.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using BigQueryReadRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        bigquery_internal::BigQueryReadRetryTraits>;

using BigQueryReadLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        bigquery_internal::BigQueryReadRetryTraits>;

using BigQueryReadLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        bigquery_internal::BigQueryReadRetryTraits>;

void BigQueryReadReadRowsStreamingUpdater(
    google::cloud::bigquery::storage::v1::ReadRowsResponse const& response,
    google::cloud::bigquery::storage::v1::ReadRowsRequest& request);

class BigQueryReadConnection {
 public:
  virtual ~BigQueryReadConnection() = 0;

  virtual StatusOr<google::cloud::bigquery::storage::v1::ReadSession>
  CreateReadSession(
      google::cloud::bigquery::storage::v1::CreateReadSessionRequest const&
          request);

  virtual StreamRange<google::cloud::bigquery::storage::v1::ReadRowsResponse>
  ReadRows(
      google::cloud::bigquery::storage::v1::ReadRowsRequest const& request);

  virtual StatusOr<
      google::cloud::bigquery::storage::v1::SplitReadStreamResponse>
  SplitReadStream(
      google::cloud::bigquery::storage::v1::SplitReadStreamRequest const&
          request);
};

std::shared_ptr<BigQueryReadConnection> MakeBigQueryReadConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace bigquery
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace bigquery_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<bigquery::BigQueryReadConnection> MakeBigQueryReadConnection(
    std::shared_ptr<BigQueryReadStub> stub, Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
namespace gcpcxxV1 = GOOGLE_CLOUD_CPP_NS;  // NOLINT(misc-unused-alias-decls)
}  // namespace bigquery_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_BIGQUERY_READ_CONNECTION_H
