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
// source: google/cloud/contentwarehouse/v1/document_schema_service.proto

#include "google/cloud/contentwarehouse/v1/internal/document_schema_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/contentwarehouse/v1/document_schema_service.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace contentwarehouse_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DocumentSchemaServiceMetadata::DocumentSchemaServiceMetadata(
    std::shared_ptr<DocumentSchemaServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceMetadata::CreateDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::CreateDocumentSchemaRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateDocumentSchema(context, request);
}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceMetadata::UpdateDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::UpdateDocumentSchemaRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateDocumentSchema(context, request);
}

StatusOr<google::cloud::contentwarehouse::v1::DocumentSchema>
DocumentSchemaServiceMetadata::GetDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::GetDocumentSchemaRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetDocumentSchema(context, request);
}

Status DocumentSchemaServiceMetadata::DeleteDocumentSchema(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::DeleteDocumentSchemaRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteDocumentSchema(context, request);
}

StatusOr<google::cloud::contentwarehouse::v1::ListDocumentSchemasResponse>
DocumentSchemaServiceMetadata::ListDocumentSchemas(
    grpc::ClientContext& context,
    google::cloud::contentwarehouse::v1::ListDocumentSchemasRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListDocumentSchemas(context, request);
}

void DocumentSchemaServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void DocumentSchemaServiceMetadata::SetMetadata(grpc::ClientContext& context,
                                                Options const& options) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace contentwarehouse_v1_internal
}  // namespace cloud
}  // namespace google
