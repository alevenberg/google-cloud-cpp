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
// source: google/cloud/datacatalog/v1/datacatalog.proto

#include "google/cloud/datacatalog/v1/internal/data_catalog_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/datacatalog/v1/datacatalog.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace datacatalog_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataCatalogMetadata::DataCatalogMetadata(
    std::shared_ptr<DataCatalogStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::datacatalog::v1::SearchCatalogResponse>
DataCatalogMetadata::SearchCatalog(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::SearchCatalogRequest const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->SearchCatalog(context, request);
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogMetadata::CreateEntryGroup(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::CreateEntryGroupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateEntryGroup(context, request);
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogMetadata::GetEntryGroup(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::GetEntryGroupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetEntryGroup(context, request);
}

StatusOr<google::cloud::datacatalog::v1::EntryGroup>
DataCatalogMetadata::UpdateEntryGroup(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UpdateEntryGroupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("entry_group.name=",
                           internal::UrlEncode(request.entry_group().name())));
  return child_->UpdateEntryGroup(context, request);
}

Status DataCatalogMetadata::DeleteEntryGroup(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::DeleteEntryGroupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteEntryGroup(context, request);
}

StatusOr<google::cloud::datacatalog::v1::ListEntryGroupsResponse>
DataCatalogMetadata::ListEntryGroups(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::ListEntryGroupsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListEntryGroups(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogMetadata::CreateEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::CreateEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateEntry(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogMetadata::UpdateEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UpdateEntryRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("entry.name=", internal::UrlEncode(request.entry().name())));
  return child_->UpdateEntry(context, request);
}

Status DataCatalogMetadata::DeleteEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::DeleteEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteEntry(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Entry> DataCatalogMetadata::GetEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::GetEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetEntry(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Entry>
DataCatalogMetadata::LookupEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::LookupEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->LookupEntry(context, request);
}

StatusOr<google::cloud::datacatalog::v1::ListEntriesResponse>
DataCatalogMetadata::ListEntries(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::ListEntriesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListEntries(context, request);
}

StatusOr<google::cloud::datacatalog::v1::EntryOverview>
DataCatalogMetadata::ModifyEntryOverview(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::ModifyEntryOverviewRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ModifyEntryOverview(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Contacts>
DataCatalogMetadata::ModifyEntryContacts(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::ModifyEntryContactsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ModifyEntryContacts(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogMetadata::CreateTagTemplate(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::CreateTagTemplateRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateTagTemplate(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogMetadata::GetTagTemplate(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::GetTagTemplateRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetTagTemplate(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplate>
DataCatalogMetadata::UpdateTagTemplate(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UpdateTagTemplateRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("tag_template.name=",
                           internal::UrlEncode(request.tag_template().name())));
  return child_->UpdateTagTemplate(context, request);
}

Status DataCatalogMetadata::DeleteTagTemplate(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::DeleteTagTemplateRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteTagTemplate(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogMetadata::CreateTagTemplateField(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::CreateTagTemplateFieldRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateTagTemplateField(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogMetadata::UpdateTagTemplateField(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UpdateTagTemplateFieldRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UpdateTagTemplateField(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogMetadata::RenameTagTemplateField(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::RenameTagTemplateFieldRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameTagTemplateField(context, request);
}

StatusOr<google::cloud::datacatalog::v1::TagTemplateField>
DataCatalogMetadata::RenameTagTemplateFieldEnumValue(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::
        RenameTagTemplateFieldEnumValueRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->RenameTagTemplateFieldEnumValue(context, request);
}

Status DataCatalogMetadata::DeleteTagTemplateField(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::DeleteTagTemplateFieldRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteTagTemplateField(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Tag> DataCatalogMetadata::CreateTag(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::CreateTagRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateTag(context, request);
}

StatusOr<google::cloud::datacatalog::v1::Tag> DataCatalogMetadata::UpdateTag(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UpdateTagRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("tag.name=", internal::UrlEncode(request.tag().name())));
  return child_->UpdateTag(context, request);
}

Status DataCatalogMetadata::DeleteTag(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::DeleteTagRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteTag(context, request);
}

StatusOr<google::cloud::datacatalog::v1::ListTagsResponse>
DataCatalogMetadata::ListTags(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::ListTagsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListTags(context, request);
}

future<StatusOr<google::longrunning::Operation>>
DataCatalogMetadata::AsyncReconcileTags(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datacatalog::v1::ReconcileTagsRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncReconcileTags(cq, std::move(context), request);
}

StatusOr<google::cloud::datacatalog::v1::StarEntryResponse>
DataCatalogMetadata::StarEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::StarEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->StarEntry(context, request);
}

StatusOr<google::cloud::datacatalog::v1::UnstarEntryResponse>
DataCatalogMetadata::UnstarEntry(
    grpc::ClientContext& context,
    google::cloud::datacatalog::v1::UnstarEntryRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->UnstarEntry(context, request);
}

StatusOr<google::iam::v1::Policy> DataCatalogMetadata::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> DataCatalogMetadata::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
DataCatalogMetadata::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->TestIamPermissions(context, request);
}

future<StatusOr<google::longrunning::Operation>>
DataCatalogMetadata::AsyncImportEntries(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::datacatalog::v1::ImportEntriesRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncImportEntries(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
DataCatalogMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> DataCatalogMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void DataCatalogMetadata::SetMetadata(grpc::ClientContext& context,
                                      Options const& options,
                                      std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void DataCatalogMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace datacatalog_v1_internal
}  // namespace cloud
}  // namespace google
