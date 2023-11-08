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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_STORAGE_V1_INTERNAL_BIGQUERY_WRITE_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_STORAGE_V1_INTERNAL_BIGQUERY_WRITE_METADATA_DECORATOR_H

#include "google/cloud/bigquery/storage/v1/internal/bigquery_write_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace bigquery_storage_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class BigQueryWriteMetadata : public BigQueryWriteStub {
 public:
  ~BigQueryWriteMetadata() override = default;
  BigQueryWriteMetadata(std::shared_ptr<BigQueryWriteStub> child,
                        std::multimap<std::string, std::string> fixed_metadata,
                        std::string api_client_header = "");

  StatusOr<google::cloud::bigquery::storage::v1::WriteStream> CreateWriteStream(
      grpc::ClientContext& context,
      google::cloud::bigquery::storage::v1::CreateWriteStreamRequest const&
          request) override;

  std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::cloud::bigquery::storage::v1::AppendRowsRequest,
      google::cloud::bigquery::storage::v1::AppendRowsResponse>>
  AsyncAppendRows(google::cloud::CompletionQueue const& cq,
                  std::shared_ptr<grpc::ClientContext> context) override;

  StatusOr<google::cloud::bigquery::storage::v1::WriteStream> GetWriteStream(
      grpc::ClientContext& context,
      google::cloud::bigquery::storage::v1::GetWriteStreamRequest const&
          request) override;

  StatusOr<google::cloud::bigquery::storage::v1::FinalizeWriteStreamResponse>
  FinalizeWriteStream(
      grpc::ClientContext& context,
      google::cloud::bigquery::storage::v1::FinalizeWriteStreamRequest const&
          request) override;

  StatusOr<
      google::cloud::bigquery::storage::v1::BatchCommitWriteStreamsResponse>
  BatchCommitWriteStreams(
      grpc::ClientContext& context,
      google::cloud::bigquery::storage::v1::
          BatchCommitWriteStreamsRequest const& request) override;

  StatusOr<google::cloud::bigquery::storage::v1::FlushRowsResponse> FlushRows(
      grpc::ClientContext& context,
      google::cloud::bigquery::storage::v1::FlushRowsRequest const& request)
      override;

 private:
  void SetMetadata(grpc::ClientContext& context, Options const& options,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context, Options const& options);

  std::shared_ptr<BigQueryWriteStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_storage_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_STORAGE_V1_INTERNAL_BIGQUERY_WRITE_METADATA_DECORATOR_H
