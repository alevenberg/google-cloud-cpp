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
// source: google/cloud/discoveryengine/v1/engine_service.proto

#include "google/cloud/discoveryengine/v1/internal/engine_connection_impl.h"
#include "google/cloud/discoveryengine/v1/internal/engine_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace discoveryengine_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

std::unique_ptr<discoveryengine_v1::EngineServiceRetryPolicy> retry_policy(
    Options const& options) {
  return options.get<discoveryengine_v1::EngineServiceRetryPolicyOption>()
      ->clone();
}

std::unique_ptr<BackoffPolicy> backoff_policy(Options const& options) {
  return options.get<discoveryengine_v1::EngineServiceBackoffPolicyOption>()
      ->clone();
}

std::unique_ptr<discoveryengine_v1::EngineServiceConnectionIdempotencyPolicy>
idempotency_policy(Options const& options) {
  return options
      .get<discoveryengine_v1::EngineServiceConnectionIdempotencyPolicyOption>()
      ->clone();
}

std::unique_ptr<PollingPolicy> polling_policy(Options const& options) {
  return options.get<discoveryengine_v1::EngineServicePollingPolicyOption>()
      ->clone();
}

}  // namespace

EngineServiceConnectionImpl::EngineServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<discoveryengine_v1_internal::EngineServiceStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      EngineServiceConnection::options())) {}

future<StatusOr<google::cloud::discoveryengine::v1::Engine>>
EngineServiceConnectionImpl::CreateEngine(
    google::cloud::discoveryengine::v1::CreateEngineRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto request_copy = request;
  auto const idempotent =
      idempotency_policy(*current)->CreateEngine(request_copy);
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::discoveryengine::v1::Engine>(
      background_->cq(), current, std::move(request_copy),
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::discoveryengine::v1::CreateEngineRequest const&
              request) {
        return stub->AsyncCreateEngine(cq, std::move(context),
                                       std::move(options), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::cloud::internal::ImmutableOptions options,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context),
                                       std::move(options), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context),
                                          std::move(options), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::discoveryengine::v1::Engine>,
      retry_policy(*current), backoff_policy(*current), idempotent,
      polling_policy(*current), __func__);
}

future<StatusOr<google::cloud::discoveryengine::v1::DeleteEngineMetadata>>
EngineServiceConnectionImpl::DeleteEngine(
    google::cloud::discoveryengine::v1::DeleteEngineRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto request_copy = request;
  auto const idempotent =
      idempotency_policy(*current)->DeleteEngine(request_copy);
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::discoveryengine::v1::DeleteEngineMetadata>(
      background_->cq(), current, std::move(request_copy),
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::cloud::discoveryengine::v1::DeleteEngineRequest const&
              request) {
        return stub->AsyncDeleteEngine(cq, std::move(context),
                                       std::move(options), request);
      },
      [stub = stub_](google::cloud::CompletionQueue& cq,
                     std::shared_ptr<grpc::ClientContext> context,
                     google::cloud::internal::ImmutableOptions options,
                     google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context),
                                       std::move(options), request);
      },
      [stub = stub_](
          google::cloud::CompletionQueue& cq,
          std::shared_ptr<grpc::ClientContext> context,
          google::cloud::internal::ImmutableOptions options,
          google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context),
                                          std::move(options), request);
      },
      &google::cloud::internal::ExtractLongRunningResultMetadata<
          google::cloud::discoveryengine::v1::DeleteEngineMetadata>,
      retry_policy(*current), backoff_policy(*current), idempotent,
      polling_policy(*current), __func__);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceConnectionImpl::UpdateEngine(
    google::cloud::discoveryengine::v1::UpdateEngineRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->UpdateEngine(request),
      [this](grpc::ClientContext& context, Options const& options,
             google::cloud::discoveryengine::v1::UpdateEngineRequest const&
                 request) {
        return stub_->UpdateEngine(context, options, request);
      },
      *current, request, __func__);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceConnectionImpl::GetEngine(
    google::cloud::discoveryengine::v1::GetEngineRequest const& request) {
  auto current = google::cloud::internal::SaveCurrentOptions();
  return google::cloud::internal::RetryLoop(
      retry_policy(*current), backoff_policy(*current),
      idempotency_policy(*current)->GetEngine(request),
      [this](
          grpc::ClientContext& context, Options const& options,
          google::cloud::discoveryengine::v1::GetEngineRequest const& request) {
        return stub_->GetEngine(context, options, request);
      },
      *current, request, __func__);
}

StreamRange<google::cloud::discoveryengine::v1::Engine>
EngineServiceConnectionImpl::ListEngines(
    google::cloud::discoveryengine::v1::ListEnginesRequest request) {
  request.clear_page_token();
  auto current = google::cloud::internal::SaveCurrentOptions();
  auto idempotency = idempotency_policy(*current)->ListEngines(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::discoveryengine::v1::Engine>>(
      current, std::move(request),
      [idempotency, function_name, stub = stub_,
       retry = std::shared_ptr<discoveryengine_v1::EngineServiceRetryPolicy>(
           retry_policy(*current)),
       backoff = std::shared_ptr<BackoffPolicy>(backoff_policy(*current))](
          Options const& options,
          google::cloud::discoveryengine::v1::ListEnginesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context, Options const& options,
                   google::cloud::discoveryengine::v1::ListEnginesRequest const&
                       request) {
              return stub->ListEngines(context, options, request);
            },
            options, r, function_name);
      },
      [](google::cloud::discoveryengine::v1::ListEnginesResponse r) {
        std::vector<google::cloud::discoveryengine::v1::Engine> result(
            r.engines().size());
        auto& messages = *r.mutable_engines();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace discoveryengine_v1_internal
}  // namespace cloud
}  // namespace google
