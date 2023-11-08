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
// source: google/iam/v2/policy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_V2_INTERNAL_POLICIES_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_V2_INTERNAL_POLICIES_METADATA_DECORATOR_H

#include "google/cloud/iam/v2/internal/policies_stub.h"
#include "google/cloud/options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace iam_v2_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class PoliciesMetadata : public PoliciesStub {
 public:
  ~PoliciesMetadata() override = default;
  PoliciesMetadata(std::shared_ptr<PoliciesStub> child,
                   std::multimap<std::string, std::string> fixed_metadata,
                   std::string api_client_header = "");

  StatusOr<google::iam::v2::ListPoliciesResponse> ListPolicies(
      grpc::ClientContext& context,
      google::iam::v2::ListPoliciesRequest const& request) override;

  StatusOr<google::iam::v2::Policy> GetPolicy(
      grpc::ClientContext& context,
      google::iam::v2::GetPolicyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreatePolicy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::iam::v2::CreatePolicyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdatePolicy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::iam::v2::UpdatePolicyRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeletePolicy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::iam::v2::DeletePolicyRequest const& request) override;

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

  std::shared_ptr<PoliciesStub> child_;
  std::multimap<std::string, std::string> fixed_metadata_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iam_v2_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_IAM_V2_INTERNAL_POLICIES_METADATA_DECORATOR_H
