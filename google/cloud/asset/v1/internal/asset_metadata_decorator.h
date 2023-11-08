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
// source: google/cloud/asset/v1/asset_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_V1_INTERNAL_ASSET_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_V1_INTERNAL_ASSET_METADATA_DECORATOR_H

#include "google/cloud/asset/v1/internal/asset_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace asset_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class AssetServiceMetadata : public AssetServiceStub {
 public:
  ~AssetServiceMetadata() override = default;
  AssetServiceMetadata(std::shared_ptr<AssetServiceStub> child,
                       std::multimap<std::string, std::string> fixed_metadata,
                       std::string api_client_header = "");

  future<StatusOr<google::longrunning::Operation>> AsyncExportAssets(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::asset::v1::ExportAssetsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::ListAssetsResponse> ListAssets(
      grpc::ClientContext& context,
      google::cloud::asset::v1::ListAssetsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::BatchGetAssetsHistoryResponse>
  BatchGetAssetsHistory(
      grpc::ClientContext& context,
      google::cloud::asset::v1::BatchGetAssetsHistoryRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::Feed> CreateFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::CreateFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::Feed> GetFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::GetFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::ListFeedsResponse> ListFeeds(
      grpc::ClientContext& context,
      google::cloud::asset::v1::ListFeedsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::Feed> UpdateFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::UpdateFeedRequest const& request) override;

  Status DeleteFeed(
      grpc::ClientContext& context,
      google::cloud::asset::v1::DeleteFeedRequest const& request) override;

  StatusOr<google::cloud::asset::v1::SearchAllResourcesResponse>
  SearchAllResources(grpc::ClientContext& context,
                     google::cloud::asset::v1::SearchAllResourcesRequest const&
                         request) override;

  StatusOr<google::cloud::asset::v1::SearchAllIamPoliciesResponse>
  SearchAllIamPolicies(
      grpc::ClientContext& context,
      google::cloud::asset::v1::SearchAllIamPoliciesRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::AnalyzeIamPolicyResponse> AnalyzeIamPolicy(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeIamPolicyRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncAnalyzeIamPolicyLongrunning(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::asset::v1::AnalyzeIamPolicyLongrunningRequest const&
          request) override;

  StatusOr<google::cloud::asset::v1::AnalyzeMoveResponse> AnalyzeMove(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeMoveRequest const& request) override;

  StatusOr<google::cloud::asset::v1::QueryAssetsResponse> QueryAssets(
      grpc::ClientContext& context,
      google::cloud::asset::v1::QueryAssetsRequest const& request) override;

  StatusOr<google::cloud::asset::v1::SavedQuery> CreateSavedQuery(
      grpc::ClientContext& context,
      google::cloud::asset::v1::CreateSavedQueryRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::SavedQuery> GetSavedQuery(
      grpc::ClientContext& context,
      google::cloud::asset::v1::GetSavedQueryRequest const& request) override;

  StatusOr<google::cloud::asset::v1::ListSavedQueriesResponse> ListSavedQueries(
      grpc::ClientContext& context,
      google::cloud::asset::v1::ListSavedQueriesRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::SavedQuery> UpdateSavedQuery(
      grpc::ClientContext& context,
      google::cloud::asset::v1::UpdateSavedQueryRequest const& request)
      override;

  Status DeleteSavedQuery(
      grpc::ClientContext& context,
      google::cloud::asset::v1::DeleteSavedQueryRequest const& request)
      override;

  StatusOr<google::cloud::asset::v1::BatchGetEffectiveIamPoliciesResponse>
  BatchGetEffectiveIamPolicies(
      grpc::ClientContext& context,
      google::cloud::asset::v1::BatchGetEffectiveIamPoliciesRequest const&
          request) override;

  StatusOr<google::cloud::asset::v1::AnalyzeOrgPoliciesResponse>
  AnalyzeOrgPolicies(grpc::ClientContext& context,
                     google::cloud::asset::v1::AnalyzeOrgPoliciesRequest const&
                         request) override;

  StatusOr<google::cloud::asset::v1::AnalyzeOrgPolicyGovernedContainersResponse>
  AnalyzeOrgPolicyGovernedContainers(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeOrgPolicyGovernedContainersRequest const&
          request) override;

  StatusOr<google::cloud::asset::v1::AnalyzeOrgPolicyGovernedAssetsResponse>
  AnalyzeOrgPolicyGovernedAssets(
      grpc::ClientContext& context,
      google::cloud::asset::v1::AnalyzeOrgPolicyGovernedAssetsRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  void SetMetadata(grpc::ClientContext& context, Options const& options,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context, Options const& options);

  std::shared_ptr<AssetServiceStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace asset_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_ASSET_V1_INTERNAL_ASSET_METADATA_DECORATOR_H
