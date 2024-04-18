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
// source: google/cloud/networkconnectivity/v1/policy_based_routing.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_V1_INTERNAL_POLICY_BASED_ROUTING_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_V1_INTERNAL_POLICY_BASED_ROUTING_LOGGING_DECORATOR_H

#include "google/cloud/networkconnectivity/v1/internal/policy_based_routing_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace networkconnectivity_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class PolicyBasedRoutingServiceLogging : public PolicyBasedRoutingServiceStub {
 public:
  ~PolicyBasedRoutingServiceLogging() override = default;
  PolicyBasedRoutingServiceLogging(
      std::shared_ptr<PolicyBasedRoutingServiceStub> child,
      TracingOptions tracing_options, std::set<std::string> const& components);

  StatusOr<
      google::cloud::networkconnectivity::v1::ListPolicyBasedRoutesResponse>
  ListPolicyBasedRoutes(
      grpc::ClientContext& context, Options const& options,
      google::cloud::networkconnectivity::v1::
          ListPolicyBasedRoutesRequest const& request) override;

  StatusOr<google::cloud::networkconnectivity::v1::PolicyBasedRoute>
  GetPolicyBasedRoute(
      grpc::ClientContext& context, Options const& options,
      google::cloud::networkconnectivity::v1::GetPolicyBasedRouteRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreatePolicyBasedRoute(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::networkconnectivity::v1::
          CreatePolicyBasedRouteRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeletePolicyBasedRoute(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::networkconnectivity::v1::
          DeletePolicyBasedRouteRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<PolicyBasedRoutingServiceStub> child_;
  TracingOptions tracing_options_;
};  // PolicyBasedRoutingServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace networkconnectivity_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_NETWORKCONNECTIVITY_V1_INTERNAL_POLICY_BASED_ROUTING_LOGGING_DECORATOR_H
