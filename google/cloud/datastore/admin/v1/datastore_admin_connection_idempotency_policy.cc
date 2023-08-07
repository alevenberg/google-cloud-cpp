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

#include "google/cloud/datastore/admin/v1/datastore_admin_connection_idempotency_policy.h"
#include <memory>

namespace google {
namespace cloud {
namespace datastore_admin_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

DatastoreAdminConnectionIdempotencyPolicy::
    ~DatastoreAdminConnectionIdempotencyPolicy() = default;

std::unique_ptr<DatastoreAdminConnectionIdempotencyPolicy>
DatastoreAdminConnectionIdempotencyPolicy::clone() const {
  return std::make_unique<DatastoreAdminConnectionIdempotencyPolicy>(*this);
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::ExportEntities(
    google::datastore::admin::v1::ExportEntitiesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::ImportEntities(
    google::datastore::admin::v1::ImportEntitiesRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::CreateIndex(
    google::datastore::admin::v1::CreateIndexRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::DeleteIndex(
    google::datastore::admin::v1::DeleteIndexRequest const&) {
  return Idempotency::kNonIdempotent;
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::GetIndex(
    google::datastore::admin::v1::GetIndexRequest const&) {
  return Idempotency::kIdempotent;
}

Idempotency DatastoreAdminConnectionIdempotencyPolicy::ListIndexes(
    google::datastore::admin::v1::ListIndexesRequest) {  // NOLINT
  return Idempotency::kIdempotent;
}

std::unique_ptr<DatastoreAdminConnectionIdempotencyPolicy>
MakeDefaultDatastoreAdminConnectionIdempotencyPolicy() {
  return std::make_unique<DatastoreAdminConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datastore_admin_v1
}  // namespace cloud
}  // namespace google
