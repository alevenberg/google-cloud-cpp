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
// source: google/cloud/vmwareengine/v1/vmwareengine.proto

#include "google/cloud/vmwareengine/v1/internal/vmware_engine_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/vmwareengine/v1/vmwareengine.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace vmwareengine_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

VmwareEngineMetadata::VmwareEngineMetadata(
    std::shared_ptr<VmwareEngineStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::vmwareengine::v1::ListPrivateCloudsResponse>
VmwareEngineMetadata::ListPrivateClouds(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListPrivateCloudsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListPrivateClouds(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::PrivateCloud>
VmwareEngineMetadata::GetPrivateCloud(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetPrivateCloudRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetPrivateCloud(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreatePrivateCloud(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreatePrivateCloudRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreatePrivateCloud(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdatePrivateCloud(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdatePrivateCloudRequest const& request) {
  SetMetadata(
      *context, internal::CurrentOptions(),
      absl::StrCat("private_cloud.name=",
                   internal::UrlEncode(request.private_cloud().name())));
  return child_->AsyncUpdatePrivateCloud(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncDeletePrivateCloud(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::DeletePrivateCloudRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeletePrivateCloud(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUndeletePrivateCloud(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UndeletePrivateCloudRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncUndeletePrivateCloud(cq, std::move(context), request);
}

StatusOr<google::cloud::vmwareengine::v1::ListClustersResponse>
VmwareEngineMetadata::ListClusters(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListClustersRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListClusters(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::Cluster>
VmwareEngineMetadata::GetCluster(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetClusterRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetCluster(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreateCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreateClusterRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateCluster(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdateCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdateClusterRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("cluster.name=",
                           internal::UrlEncode(request.cluster().name())));
  return child_->AsyncUpdateCluster(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncDeleteCluster(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::DeleteClusterRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteCluster(cq, std::move(context), request);
}

StatusOr<google::cloud::vmwareengine::v1::ListSubnetsResponse>
VmwareEngineMetadata::ListSubnets(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListSubnetsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListSubnets(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::Subnet>
VmwareEngineMetadata::GetSubnet(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetSubnetRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetSubnet(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdateSubnet(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdateSubnetRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("subnet.name=",
                           internal::UrlEncode(request.subnet().name())));
  return child_->AsyncUpdateSubnet(cq, std::move(context), request);
}

StatusOr<google::cloud::vmwareengine::v1::ListNodeTypesResponse>
VmwareEngineMetadata::ListNodeTypes(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListNodeTypesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListNodeTypes(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::NodeType>
VmwareEngineMetadata::GetNodeType(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetNodeTypeRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetNodeType(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::Credentials>
VmwareEngineMetadata::ShowNsxCredentials(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ShowNsxCredentialsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("private_cloud=",
                           internal::UrlEncode(request.private_cloud())));
  return child_->ShowNsxCredentials(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::Credentials>
VmwareEngineMetadata::ShowVcenterCredentials(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ShowVcenterCredentialsRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("private_cloud=",
                           internal::UrlEncode(request.private_cloud())));
  return child_->ShowVcenterCredentials(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncResetNsxCredentials(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::ResetNsxCredentialsRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("private_cloud=",
                           internal::UrlEncode(request.private_cloud())));
  return child_->AsyncResetNsxCredentials(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncResetVcenterCredentials(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::ResetVcenterCredentialsRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("private_cloud=",
                           internal::UrlEncode(request.private_cloud())));
  return child_->AsyncResetVcenterCredentials(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreateHcxActivationKey(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreateHcxActivationKeyRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateHcxActivationKey(cq, std::move(context), request);
}

StatusOr<google::cloud::vmwareengine::v1::ListHcxActivationKeysResponse>
VmwareEngineMetadata::ListHcxActivationKeys(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListHcxActivationKeysRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListHcxActivationKeys(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::HcxActivationKey>
VmwareEngineMetadata::GetHcxActivationKey(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetHcxActivationKeyRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetHcxActivationKey(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::NetworkPolicy>
VmwareEngineMetadata::GetNetworkPolicy(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetNetworkPolicyRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetNetworkPolicy(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::ListNetworkPoliciesResponse>
VmwareEngineMetadata::ListNetworkPolicies(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListNetworkPoliciesRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListNetworkPolicies(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreateNetworkPolicy(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreateNetworkPolicyRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateNetworkPolicy(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdateNetworkPolicy(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdateNetworkPolicyRequest const&
        request) {
  SetMetadata(
      *context, internal::CurrentOptions(),
      absl::StrCat("network_policy.name=",
                   internal::UrlEncode(request.network_policy().name())));
  return child_->AsyncUpdateNetworkPolicy(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncDeleteNetworkPolicy(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::DeleteNetworkPolicyRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteNetworkPolicy(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreateVmwareEngineNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreateVmwareEngineNetworkRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateVmwareEngineNetwork(cq, std::move(context),
                                                request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdateVmwareEngineNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdateVmwareEngineNetworkRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat(
                  "vmware_engine_network.name=",
                  internal::UrlEncode(request.vmware_engine_network().name())));
  return child_->AsyncUpdateVmwareEngineNetwork(cq, std::move(context),
                                                request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncDeleteVmwareEngineNetwork(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::DeleteVmwareEngineNetworkRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteVmwareEngineNetwork(cq, std::move(context),
                                                request);
}

StatusOr<google::cloud::vmwareengine::v1::VmwareEngineNetwork>
VmwareEngineMetadata::GetVmwareEngineNetwork(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetVmwareEngineNetworkRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetVmwareEngineNetwork(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::ListVmwareEngineNetworksResponse>
VmwareEngineMetadata::ListVmwareEngineNetworks(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListVmwareEngineNetworksRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListVmwareEngineNetworks(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncCreatePrivateConnection(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::CreatePrivateConnectionRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreatePrivateConnection(cq, std::move(context), request);
}

StatusOr<google::cloud::vmwareengine::v1::PrivateConnection>
VmwareEngineMetadata::GetPrivateConnection(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::GetPrivateConnectionRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetPrivateConnection(context, request);
}

StatusOr<google::cloud::vmwareengine::v1::ListPrivateConnectionsResponse>
VmwareEngineMetadata::ListPrivateConnections(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::ListPrivateConnectionsRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListPrivateConnections(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncUpdatePrivateConnection(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::UpdatePrivateConnectionRequest const&
        request) {
  SetMetadata(
      *context, internal::CurrentOptions(),
      absl::StrCat("private_connection.name=",
                   internal::UrlEncode(request.private_connection().name())));
  return child_->AsyncUpdatePrivateConnection(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncDeletePrivateConnection(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::vmwareengine::v1::DeletePrivateConnectionRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeletePrivateConnection(cq, std::move(context), request);
}

StatusOr<
    google::cloud::vmwareengine::v1::ListPrivateConnectionPeeringRoutesResponse>
VmwareEngineMetadata::ListPrivateConnectionPeeringRoutes(
    grpc::ClientContext& context,
    google::cloud::vmwareengine::v1::
        ListPrivateConnectionPeeringRoutesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListPrivateConnectionPeeringRoutes(context, request);
}

future<StatusOr<google::longrunning::Operation>>
VmwareEngineMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> VmwareEngineMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void VmwareEngineMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void VmwareEngineMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace vmwareengine_v1_internal
}  // namespace cloud
}  // namespace google
