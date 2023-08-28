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
// source: google/cloud/gsuiteaddons/v1/gsuiteaddons.proto

#include "google/cloud/gsuiteaddons/v1/internal/g_suite_add_ons_connection_impl.h"
#include "google/cloud/gsuiteaddons/v1/internal/g_suite_add_ons_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace gsuiteaddons_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

std::unique_ptr<gsuiteaddons_v1::GSuiteAddOnsRetryPolicy> retry_policy(
    Options const& options) {
  return options.get<gsuiteaddons_v1::GSuiteAddOnsRetryPolicyOption>()->clone();
}

std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
  return options.get<gsuiteaddons_v1::GSuiteAddOnsBackoffPolicyOption>()
      ->clone();
}

std::unique_ptr<gsuiteaddons_v1::GSuiteAddOnsConnectionIdempotencyPolicy>
idempotency_policy(Options const& options) {
  return options
      .get<gsuiteaddons_v1::GSuiteAddOnsConnectionIdempotencyPolicyOption>()
      ->clone();
}

}  // namespace

GSuiteAddOnsConnectionImpl::GSuiteAddOnsConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<gsuiteaddons_v1_internal::GSuiteAddOnsStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      GSuiteAddOnsConnection::options())) {}

StatusOr<google::cloud::gsuiteaddons::v1::Authorization>
GSuiteAddOnsConnectionImpl::GetAuthorization(
    google::cloud::gsuiteaddons::v1::GetAuthorizationRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetAuthorization(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::GetAuthorizationRequest const&
                 request) { return stub_->GetAuthorization(context, request); },
      request, __func__);
}

StatusOr<google::cloud::gsuiteaddons::v1::Deployment>
GSuiteAddOnsConnectionImpl::CreateDeployment(
    google::cloud::gsuiteaddons::v1::CreateDeploymentRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->CreateDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::CreateDeploymentRequest const&
                 request) { return stub_->CreateDeployment(context, request); },
      request, __func__);
}

StatusOr<google::cloud::gsuiteaddons::v1::Deployment>
GSuiteAddOnsConnectionImpl::ReplaceDeployment(
    google::cloud::gsuiteaddons::v1::ReplaceDeploymentRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->ReplaceDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::ReplaceDeploymentRequest const&
                 request) {
        return stub_->ReplaceDeployment(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::gsuiteaddons::v1::Deployment>
GSuiteAddOnsConnectionImpl::GetDeployment(
    google::cloud::gsuiteaddons::v1::GetDeploymentRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::GetDeploymentRequest const&
                 request) { return stub_->GetDeployment(context, request); },
      request, __func__);
}

StreamRange<google::cloud::gsuiteaddons::v1::Deployment>
GSuiteAddOnsConnectionImpl::ListDeployments(
    google::cloud::gsuiteaddons::v1::ListDeploymentsRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency = idempotency_policy(*current)->ListDeployments(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::gsuiteaddons::v1::Deployment>>(
      std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<gsuiteaddons_v1::GSuiteAddOnsRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          google::cloud::gsuiteaddons::v1::ListDeploymentsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::gsuiteaddons::v1::ListDeploymentsRequest const&
                    request) {
              return stub->ListDeployments(context, request);
            },
            r, function_name);
      },
      [](google::cloud::gsuiteaddons::v1::ListDeploymentsResponse r) {
        std::vector<google::cloud::gsuiteaddons::v1::Deployment> result(
            r.deployments().size());
        auto& messages = *r.mutable_deployments();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

Status GSuiteAddOnsConnectionImpl::DeleteDeployment(
    google::cloud::gsuiteaddons::v1::DeleteDeploymentRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->DeleteDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::DeleteDeploymentRequest const&
                 request) { return stub_->DeleteDeployment(context, request); },
      request, __func__);
}

Status GSuiteAddOnsConnectionImpl::InstallDeployment(
    google::cloud::gsuiteaddons::v1::InstallDeploymentRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->InstallDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::InstallDeploymentRequest const&
                 request) {
        return stub_->InstallDeployment(context, request);
      },
      request, __func__);
}

Status GSuiteAddOnsConnectionImpl::UninstallDeployment(
    google::cloud::gsuiteaddons::v1::UninstallDeploymentRequest const&
        request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->UninstallDeployment(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::UninstallDeploymentRequest const&
                 request) {
        return stub_->UninstallDeployment(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::gsuiteaddons::v1::InstallStatus>
GSuiteAddOnsConnectionImpl::GetInstallStatus(
    google::cloud::gsuiteaddons::v1::GetInstallStatusRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetInstallStatus(request),
      [this](grpc::ClientContext& context,
             google::cloud::gsuiteaddons::v1::GetInstallStatusRequest const&
                 request) { return stub_->GetInstallStatus(context, request); },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gsuiteaddons_v1_internal
}  // namespace cloud
}  // namespace google
