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
// source: google/cloud/essentialcontacts/v1/service.proto

#include "google/cloud/essentialcontacts/v1/internal/essential_contacts_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/essentialcontacts/v1/service.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace essentialcontacts_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EssentialContactsServiceMetadata::EssentialContactsServiceMetadata(
    std::shared_ptr<EssentialContactsServiceStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::essentialcontacts::v1::Contact>
EssentialContactsServiceMetadata::CreateContact(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::CreateContactRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateContact(context, request);
}

StatusOr<google::cloud::essentialcontacts::v1::Contact>
EssentialContactsServiceMetadata::UpdateContact(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::UpdateContactRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("contact.name=",
                           internal::UrlEncode(request.contact().name())));
  return child_->UpdateContact(context, request);
}

StatusOr<google::cloud::essentialcontacts::v1::ListContactsResponse>
EssentialContactsServiceMetadata::ListContacts(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::ListContactsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListContacts(context, request);
}

StatusOr<google::cloud::essentialcontacts::v1::Contact>
EssentialContactsServiceMetadata::GetContact(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::GetContactRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetContact(context, request);
}

Status EssentialContactsServiceMetadata::DeleteContact(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::DeleteContactRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->DeleteContact(context, request);
}

StatusOr<google::cloud::essentialcontacts::v1::ComputeContactsResponse>
EssentialContactsServiceMetadata::ComputeContacts(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::ComputeContactsRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ComputeContacts(context, request);
}

Status EssentialContactsServiceMetadata::SendTestMessage(
    grpc::ClientContext& context,
    google::cloud::essentialcontacts::v1::SendTestMessageRequest const&
        request) {
  SetMetadata(
      context, internal::CurrentOptions(),
      absl::StrCat("resource=", internal::UrlEncode(request.resource())));
  return child_->SendTestMessage(context, request);
}

void EssentialContactsServiceMetadata::SetMetadata(
    grpc::ClientContext& context, Options const& options,
    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void EssentialContactsServiceMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace essentialcontacts_v1_internal
}  // namespace cloud
}  // namespace google
