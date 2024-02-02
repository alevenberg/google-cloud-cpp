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

#include "google/cloud/bigquery/tabledata/v2/internal/tabledata_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tabledata_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

TabledataTracingConnection::TabledataTracingConnection(
    std::shared_ptr<bigquery_tabledata_v2::TabledataConnection> child)
    : child_(std::move(child)) {}

StatusOr<google::cloud::cpp::bigquery::v2::TableDataInsertAllResponse>
TabledataTracingConnection::InsertAll(google::cloud::cpp::bigquery::tabledata::v2::InsertAllRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tabledata_v2::TabledataConnection::InsertAll");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->InsertAll(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::TableDataList>
TabledataTracingConnection::ListTabledata(google::cloud::cpp::bigquery::tabledata::v2::ListTabledataRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tabledata_v2::TabledataConnection::ListTabledata");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ListTabledata(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<bigquery_tabledata_v2::TabledataConnection>
MakeTabledataTracingConnection(
    std::shared_ptr<bigquery_tabledata_v2::TabledataConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<TabledataTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tabledata_v2_internal
}  // namespace cloud
}  // namespace google
