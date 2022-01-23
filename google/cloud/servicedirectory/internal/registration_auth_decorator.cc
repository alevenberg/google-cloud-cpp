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
// source: google/cloud/servicedirectory/v1/registration_service.proto

#include "google/cloud/servicedirectory/internal/registration_auth_decorator.h"
#include <google/cloud/servicedirectory/v1/registration_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace servicedirectory_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RegistrationServiceAuth::RegistrationServiceAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<RegistrationServiceStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::servicedirectory::v1::Namespace>
RegistrationServiceAuth::CreateNamespace(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::CreateNamespaceRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateNamespace(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::ListNamespacesResponse>
RegistrationServiceAuth::ListNamespaces(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::ListNamespacesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListNamespaces(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Namespace>
RegistrationServiceAuth::GetNamespace(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::GetNamespaceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetNamespace(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Namespace>
RegistrationServiceAuth::UpdateNamespace(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::UpdateNamespaceRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateNamespace(context, request);
}

Status RegistrationServiceAuth::DeleteNamespace(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::DeleteNamespaceRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteNamespace(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Service>
RegistrationServiceAuth::CreateService(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::CreateServiceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateService(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::ListServicesResponse>
RegistrationServiceAuth::ListServices(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::ListServicesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListServices(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Service>
RegistrationServiceAuth::GetService(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::GetServiceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetService(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Service>
RegistrationServiceAuth::UpdateService(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::UpdateServiceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateService(context, request);
}

Status RegistrationServiceAuth::DeleteService(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::DeleteServiceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteService(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Endpoint>
RegistrationServiceAuth::CreateEndpoint(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::CreateEndpointRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateEndpoint(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::ListEndpointsResponse>
RegistrationServiceAuth::ListEndpoints(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::ListEndpointsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListEndpoints(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Endpoint>
RegistrationServiceAuth::GetEndpoint(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::GetEndpointRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetEndpoint(context, request);
}

StatusOr<google::cloud::servicedirectory::v1::Endpoint>
RegistrationServiceAuth::UpdateEndpoint(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::UpdateEndpointRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateEndpoint(context, request);
}

Status RegistrationServiceAuth::DeleteEndpoint(
    grpc::ClientContext& context,
    google::cloud::servicedirectory::v1::DeleteEndpointRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteEndpoint(context, request);
}

StatusOr<google::iam::v1::Policy> RegistrationServiceAuth::GetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::GetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetIamPolicy(context, request);
}

StatusOr<google::iam::v1::Policy> RegistrationServiceAuth::SetIamPolicy(
    grpc::ClientContext& context,
    google::iam::v1::SetIamPolicyRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->SetIamPolicy(context, request);
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
RegistrationServiceAuth::TestIamPermissions(
    grpc::ClientContext& context,
    google::iam::v1::TestIamPermissionsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->TestIamPermissions(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicedirectory_internal
}  // namespace cloud
}  // namespace google
