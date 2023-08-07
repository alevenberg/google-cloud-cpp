// Copyright 2023 Google LLC
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
// source: google/datastore/admin/v1/datastore_admin.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATASTORE_ADMIN_V1_MOCKS_MOCK_DATASTORE_ADMIN_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATASTORE_ADMIN_V1_MOCKS_MOCK_DATASTORE_ADMIN_CONNECTION_H

#include "google/cloud/datastore/admin/v1/datastore_admin_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace datastore_admin_v1_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `DatastoreAdminConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `DatastoreAdminClient`. To do so,
 * construct an object of type `DatastoreAdminClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with GoogleTest.
 * While the example showcases types from the BigQuery library, the underlying
 * principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @cloud_cpp_docs_link{bigquery,bigquery-read-mock}
 */
class MockDatastoreAdminConnection
    : public datastore_admin_v1::DatastoreAdminConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(
      future<StatusOr<google::datastore::admin::v1::ExportEntitiesResponse>>,
      ExportEntities,
      (google::datastore::admin::v1::ExportEntitiesRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::datastore::admin::v1::ImportEntitiesMetadata>>,
      ImportEntities,
      (google::datastore::admin::v1::ImportEntitiesRequest const& request),
      (override));

  MOCK_METHOD(future<StatusOr<google::datastore::admin::v1::Index>>,
              CreateIndex,
              (google::datastore::admin::v1::CreateIndexRequest const& request),
              (override));

  MOCK_METHOD(future<StatusOr<google::datastore::admin::v1::Index>>,
              DeleteIndex,
              (google::datastore::admin::v1::DeleteIndexRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<google::datastore::admin::v1::Index>, GetIndex,
              (google::datastore::admin::v1::GetIndexRequest const& request),
              (override));

  MOCK_METHOD(StreamRange<google::datastore::admin::v1::Index>, ListIndexes,
              (google::datastore::admin::v1::ListIndexesRequest request),
              (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastore_admin_v1_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATASTORE_ADMIN_V1_MOCKS_MOCK_DATASTORE_ADMIN_CONNECTION_H
