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
// source: google/cloud/bigquery/tables/v2/tables.proto

#include "google/cloud/bigquery/tables/v2/internal/tables_tracing_connection.h"
#include "google/cloud/internal/opentelemetry.h"
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_tables_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

TablesTracingConnection::TablesTracingConnection(
    std::shared_ptr<bigquery_tables_v2::TablesConnection> child)
    : child_(std::move(child)) {}

Status
TablesTracingConnection::DeleteTable(google::cloud::cpp::bigquery::tables::v2::DeleteTableRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::DeleteTable");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->DeleteTable(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesTracingConnection::GetTable(google::cloud::cpp::bigquery::tables::v2::GetTableRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::GetTable");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetTable(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
TablesTracingConnection::GetIamPolicy(google::cloud::cpp::bigquery::tables::v2::GetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::GetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->GetIamPolicy(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesTracingConnection::InsertTable(google::cloud::cpp::bigquery::tables::v2::InsertTableRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::InsertTable");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->InsertTable(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::TableList>
TablesTracingConnection::ListTables(google::cloud::cpp::bigquery::tables::v2::ListTablesRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::ListTables");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->ListTables(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesTracingConnection::PatchTable(google::cloud::cpp::bigquery::tables::v2::PatchTableRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::PatchTable");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->PatchTable(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Policy>
TablesTracingConnection::SetIamPolicy(google::cloud::cpp::bigquery::tables::v2::SetIamPolicyRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::SetIamPolicy");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->SetIamPolicy(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::TestIamPermissionsResponse>
TablesTracingConnection::TestIamPermissions(google::cloud::cpp::bigquery::tables::v2::TestIamPermissionsRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::TestIamPermissions");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->TestIamPermissions(request));
}

StatusOr<google::cloud::cpp::bigquery::v2::Table>
TablesTracingConnection::UpdateTable(google::cloud::cpp::bigquery::tables::v2::UpdateTableRequest const& request) {
  auto span = internal::MakeSpan("bigquery_tables_v2::TablesConnection::UpdateTable");
  auto scope = opentelemetry::trace::Scope(span);
  return internal::EndSpan(*span, child_->UpdateTable(request));
}

#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY

std::shared_ptr<bigquery_tables_v2::TablesConnection>
MakeTablesTracingConnection(
    std::shared_ptr<bigquery_tables_v2::TablesConnection> conn) {
#ifdef GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  if (internal::TracingEnabled(conn->options())) {
    conn = std::make_shared<TablesTracingConnection>(std::move(conn));
  }
#endif  // GOOGLE_CLOUD_CPP_HAVE_OPENTELEMETRY
  return conn;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_tables_v2_internal
}  // namespace cloud
}  // namespace google
