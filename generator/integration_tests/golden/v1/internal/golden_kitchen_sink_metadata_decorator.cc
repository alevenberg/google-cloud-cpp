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
// source: generator/integration_tests/test.proto

#include "generator/integration_tests/golden/v1/internal/golden_kitchen_sink_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/routing_matcher.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <generator/integration_tests/test.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace golden_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

GoldenKitchenSinkMetadata::GoldenKitchenSinkMetadata(
    std::shared_ptr<GoldenKitchenSinkStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

StatusOr<google::test::admin::database::v1::GenerateAccessTokenResponse>
GoldenKitchenSinkMetadata::GenerateAccessToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(), absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GenerateAccessToken(context, request);
}

StatusOr<google::test::admin::database::v1::GenerateIdTokenResponse>
GoldenKitchenSinkMetadata::GenerateIdToken(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateIdTokenRequest const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->GenerateIdToken(context, request);
}

StatusOr<google::test::admin::database::v1::WriteLogEntriesResponse>
GoldenKitchenSinkMetadata::WriteLogEntries(
    grpc::ClientContext& context,
    google::test::admin::database::v1::WriteLogEntriesRequest const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->WriteLogEntries(context, request);
}

StatusOr<google::test::admin::database::v1::ListLogsResponse>
GoldenKitchenSinkMetadata::ListLogs(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListLogsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(), absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListLogs(context, request);
}

StatusOr<google::test::admin::database::v1::ListServiceAccountKeysResponse>
GoldenKitchenSinkMetadata::ListServiceAccountKeys(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ListServiceAccountKeysRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(), absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->ListServiceAccountKeys(context, request);
}

Status
GoldenKitchenSinkMetadata::DoNothing(
    grpc::ClientContext& context,
    google::protobuf::Empty const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->DoNothing(context, request);
}

Status
GoldenKitchenSinkMetadata::Deprecated2(
    grpc::ClientContext& context,
    google::test::admin::database::v1::GenerateAccessTokenRequest const& request) {
  SetMetadata(context, internal::CurrentOptions());
  return child_->Deprecated2(context, request);
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<google::test::admin::database::v1::Response>>
GoldenKitchenSinkMetadata::StreamingRead(
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::Request const& request) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->StreamingRead(std::move(context), request);
}

std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    google::test::admin::database::v1::Request,
    google::test::admin::database::v1::Response>>
GoldenKitchenSinkMetadata::StreamingWrite(
    std::shared_ptr<grpc::ClientContext> context) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->StreamingWrite(std::move(context));
}

std::unique_ptr<::google::cloud::AsyncStreamingReadWriteRpc<
      google::test::admin::database::v1::Request,
      google::test::admin::database::v1::Response>>
GoldenKitchenSinkMetadata::AsyncStreamingReadWrite(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->AsyncStreamingReadWrite(cq, std::move(context));
}

Status
GoldenKitchenSinkMetadata::ExplicitRouting1(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ExplicitRoutingRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  static auto* table_location_matcher = []{
    return new google::cloud::internal::RoutingMatcher<google::test::admin::database::v1::ExplicitRoutingRequest>{
      "table_location=", {
      {[](google::test::admin::database::v1::ExplicitRoutingRequest const& request) -> std::string const& {
        return request.table_name();
      },
      std::regex{"(regions/[^/]+/zones/[^/]+)/tables/[^/]+", std::regex::optimize}},
      {[](google::test::admin::database::v1::ExplicitRoutingRequest const& request) -> std::string const& {
        return request.table_name();
      },
      std::regex{"projects/[^/]+/(instances/[^/]+)/tables/[^/]+", std::regex::optimize}},
      }};
  }();
  table_location_matcher->AppendParam(request, params);

  static auto* routing_id_matcher = []{
    return new google::cloud::internal::RoutingMatcher<google::test::admin::database::v1::ExplicitRoutingRequest>{
      "routing_id=", {
      {[](google::test::admin::database::v1::ExplicitRoutingRequest const& request) -> std::string const& {
        return request.app_profile_id();
      },
      std::regex{"profiles/([^/]+)", std::regex::optimize}},
      {[](google::test::admin::database::v1::ExplicitRoutingRequest const& request) -> std::string const& {
        return request.app_profile_id();
      },
      absl::nullopt},
      {[](google::test::admin::database::v1::ExplicitRoutingRequest const& request) -> std::string const& {
        return request.table_name();
      },
      std::regex{"(projects/[^/]+)/.*", std::regex::optimize}},
      }};
  }();
  routing_id_matcher->AppendParam(request, params);

  if (params.empty()) {
    SetMetadata(context, internal::CurrentOptions());
  } else {
    SetMetadata(context, internal::CurrentOptions(), absl::StrJoin(params, "&"));
  }
  return child_->ExplicitRouting1(context, request);
}

Status
GoldenKitchenSinkMetadata::ExplicitRouting2(
    grpc::ClientContext& context,
    google::test::admin::database::v1::ExplicitRoutingRequest const& request) {
  std::vector<std::string> params;
  params.reserve(2);

  if (!request.app_profile_id().empty()) {
    params.push_back(absl::StrCat("no_regex_needed=", internal::UrlEncode(request.app_profile_id())));
  } else if (!request.table_name().empty()) {
    params.push_back(absl::StrCat("no_regex_needed=", internal::UrlEncode(request.table_name())));
  } else if (!request.no_regex_needed().empty()) {
    params.push_back(absl::StrCat("no_regex_needed=", internal::UrlEncode(request.no_regex_needed())));
  }

  if (!request.nested1().nested2().value().empty()) {
    params.push_back(absl::StrCat("routing_id=", internal::UrlEncode(request.nested1().nested2().value())));
  }

  if (params.empty()) {
    SetMetadata(context, internal::CurrentOptions());
  } else {
    SetMetadata(context, internal::CurrentOptions(), absl::StrJoin(params, "&"));
  }
  return child_->ExplicitRouting2(context, request);
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingReadRpc<
      google::test::admin::database::v1::Response>>
GoldenKitchenSinkMetadata::AsyncStreamingRead(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::test::admin::database::v1::Request const& request) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->AsyncStreamingRead(cq, std::move(context), request);
}

std::unique_ptr<::google::cloud::internal::AsyncStreamingWriteRpc<
    google::test::admin::database::v1::Request, google::test::admin::database::v1::Response>>
GoldenKitchenSinkMetadata::AsyncStreamingWrite(
    google::cloud::CompletionQueue const& cq,
    std::shared_ptr<grpc::ClientContext> context) {
  SetMetadata(*context, internal::CurrentOptions());
  return child_->AsyncStreamingWrite(cq, std::move(context));
}

void GoldenKitchenSinkMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options,
                                        std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void GoldenKitchenSinkMetadata::SetMetadata(grpc::ClientContext& context,
                                        Options const& options) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  if (options.has<UserProjectOption>()) {
    context.AddMetadata(
        "x-goog-user-project", options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace golden_v1_internal
}  // namespace cloud
}  // namespace google
