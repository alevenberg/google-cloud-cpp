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
// source: google/cloud/bigquery/tabledata/v2/tabledata.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLEDATA_V2_TABLEDATA_REST_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLEDATA_V2_TABLEDATA_REST_CONNECTION_H

#include "google/cloud/bigquery/tabledata/v2/tabledata_connection.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tabledata_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A factory function to construct an object of type `TabledataConnection`
 * that uses REST over HTTP as transport in lieu of gRPC. REST transport should
 * only be used for services that do not support gRPC or if the existing network
 * configuration precludes using gRPC.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of TabledataClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `TabledataConnection`. Expected options are any of the types in
 * the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::RestOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::bigquery_tabledata_v2::TabledataPolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param options (optional) Configure the `TabledataConnection` created by
 * this function.
 */
std::shared_ptr<TabledataConnection> MakeTabledataConnectionRest(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tabledata_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_TABLEDATA_V2_TABLEDATA_REST_CONNECTION_H
