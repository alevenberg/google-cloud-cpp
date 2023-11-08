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
// source: google/cloud/dialogflow/cx/v3/test_case.proto

#include "google/cloud/dialogflow_cx/internal/test_cases_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/dialogflow/cx/v3/test_case.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace dialogflow_cx_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TestCasesMetadata::TestCasesMetadata(
    std::shared_ptr<TestCasesStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::cloud::dialogflow::cx::v3::ListTestCasesResponse>
TestCasesMetadata::ListTestCases(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::ListTestCasesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListTestCases(context, request);
}

Status TestCasesMetadata::BatchDeleteTestCases(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->BatchDeleteTestCases(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesMetadata::GetTestCase(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::GetTestCaseRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetTestCase(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesMetadata::CreateTestCase(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->CreateTestCase(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCase>
TestCasesMetadata::UpdateTestCase(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("test_case.name=",
                           internal::UrlEncode(request.test_case().name())));
  return child_->UpdateTestCase(context, request);
}

future<StatusOr<google::longrunning::Operation>>
TestCasesMetadata::AsyncRunTestCase(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::RunTestCaseRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncRunTestCase(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
TestCasesMetadata::AsyncBatchRunTestCases(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&
        request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncBatchRunTestCases(cq, std::move(context), request);
}

StatusOr<google::cloud::dialogflow::cx::v3::CalculateCoverageResponse>
TestCasesMetadata::CalculateCoverage(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("agent=", internal::UrlEncode(request.agent())));
  return child_->CalculateCoverage(context, request);
}

future<StatusOr<google::longrunning::Operation>>
TestCasesMetadata::AsyncImportTestCases(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncImportTestCases(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
TestCasesMetadata::AsyncExportTestCases(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncExportTestCases(cq, std::move(context), request);
}

StatusOr<google::cloud::dialogflow::cx::v3::ListTestCaseResultsResponse>
TestCasesMetadata::ListTestCaseResults(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListTestCaseResults(context, request);
}

StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult>
TestCasesMetadata::GetTestCaseResult(
    grpc::ClientContext& context,
    google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&
        request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetTestCaseResult(context, request);
}

future<StatusOr<google::longrunning::Operation>>
TestCasesMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> TestCasesMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void TestCasesMetadata::SetMetadata(grpc::ClientContext& context,
                                    Options const& options,
                                    std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void TestCasesMetadata::SetMetadata(grpc::ClientContext& context,
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
}  // namespace dialogflow_cx_internal
}  // namespace cloud
}  // namespace google
