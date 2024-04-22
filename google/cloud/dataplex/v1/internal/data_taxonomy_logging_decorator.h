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
// source: google/cloud/dataplex/v1/data_taxonomy.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_TAXONOMY_LOGGING_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_TAXONOMY_LOGGING_DECORATOR_H

#include "google/cloud/dataplex/v1/internal/data_taxonomy_stub.h"
#include "google/cloud/tracing_options.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace dataplex_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class DataTaxonomyServiceLogging : public DataTaxonomyServiceStub {
 public:
  ~DataTaxonomyServiceLogging() override = default;
  DataTaxonomyServiceLogging(std::shared_ptr<DataTaxonomyServiceStub> child,
                             TracingOptions tracing_options,
                             std::set<std::string> const& components);

  future<StatusOr<google::longrunning::Operation>> AsyncCreateDataTaxonomy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::CreateDataTaxonomyRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateDataTaxonomy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::UpdateDataTaxonomyRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteDataTaxonomy(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::DeleteDataTaxonomyRequest const& request)
      override;

  StatusOr<google::cloud::dataplex::v1::ListDataTaxonomiesResponse>
  ListDataTaxonomies(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::ListDataTaxonomiesRequest const& request)
      override;

  StatusOr<google::cloud::dataplex::v1::DataTaxonomy> GetDataTaxonomy(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::GetDataTaxonomyRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateDataAttributeBinding(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::CreateDataAttributeBindingRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateDataAttributeBinding(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::UpdateDataAttributeBindingRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteDataAttributeBinding(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::DeleteDataAttributeBindingRequest const&
          request) override;

  StatusOr<google::cloud::dataplex::v1::ListDataAttributeBindingsResponse>
  ListDataAttributeBindings(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::ListDataAttributeBindingsRequest const&
          request) override;

  StatusOr<google::cloud::dataplex::v1::DataAttributeBinding>
  GetDataAttributeBinding(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::GetDataAttributeBindingRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateDataAttribute(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::CreateDataAttributeRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncUpdateDataAttribute(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::UpdateDataAttributeRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncDeleteDataAttribute(
      google::cloud::CompletionQueue& cq,
      std::shared_ptr<grpc::ClientContext> context,
      google::cloud::internal::ImmutableOptions options,
      google::cloud::dataplex::v1::DeleteDataAttributeRequest const& request)
      override;

  StatusOr<google::cloud::dataplex::v1::ListDataAttributesResponse>
  ListDataAttributes(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::ListDataAttributesRequest const& request)
      override;

  StatusOr<google::cloud::dataplex::v1::DataAttribute> GetDataAttribute(
      grpc::ClientContext& context, Options const& options,
      google::cloud::dataplex::v1::GetDataAttributeRequest const& request)
      override;

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
  std::shared_ptr<DataTaxonomyServiceStub> child_;
  TracingOptions tracing_options_;
};  // DataTaxonomyServiceLogging

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_v1_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPLEX_V1_INTERNAL_DATA_TAXONOMY_LOGGING_DECORATOR_H
