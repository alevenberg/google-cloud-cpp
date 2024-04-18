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

#include "google/cloud/discoveryengine/v1/engine_client.h"
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace discoveryengine_v1 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EngineServiceClient::EngineServiceClient(
    std::shared_ptr<EngineServiceConnection> connection, Options opts)
    : connection_(std::move(connection)),
      options_(
          internal::MergeOptions(std::move(opts), connection_->options())) {}
EngineServiceClient::~EngineServiceClient() = default;

future<StatusOr<google::cloud::discoveryengine::v1::Engine>>
EngineServiceClient::CreateEngine(
    std::string const& parent,
    google::cloud::discoveryengine::v1::Engine const& engine,
    std::string const& engine_id, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::discoveryengine::v1::CreateEngineRequest request;
  request.set_parent(parent);
  *request.mutable_engine() = engine;
  request.set_engine_id(engine_id);
  return connection_->CreateEngine(request);
}

future<StatusOr<google::cloud::discoveryengine::v1::Engine>>
EngineServiceClient::CreateEngine(
    google::cloud::discoveryengine::v1::CreateEngineRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateEngine(request);
}

future<StatusOr<google::cloud::discoveryengine::v1::DeleteEngineMetadata>>
EngineServiceClient::DeleteEngine(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::discoveryengine::v1::DeleteEngineRequest request;
  request.set_name(name);
  return connection_->DeleteEngine(request);
}

future<StatusOr<google::cloud::discoveryengine::v1::DeleteEngineMetadata>>
EngineServiceClient::DeleteEngine(
    google::cloud::discoveryengine::v1::DeleteEngineRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteEngine(request);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::UpdateEngine(
    google::cloud::discoveryengine::v1::Engine const& engine,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::discoveryengine::v1::UpdateEngineRequest request;
  *request.mutable_engine() = engine;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateEngine(request);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::UpdateEngine(
    google::cloud::discoveryengine::v1::UpdateEngineRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateEngine(request);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::GetEngine(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::discoveryengine::v1::GetEngineRequest request;
  request.set_name(name);
  return connection_->GetEngine(request);
}

StatusOr<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::GetEngine(
    google::cloud::discoveryengine::v1::GetEngineRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetEngine(request);
}

StreamRange<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::ListEngines(std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::discoveryengine::v1::ListEnginesRequest request;
  request.set_parent(parent);
  return connection_->ListEngines(request);
}

StreamRange<google::cloud::discoveryengine::v1::Engine>
EngineServiceClient::ListEngines(
    google::cloud::discoveryengine::v1::ListEnginesRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListEngines(std::move(request));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace discoveryengine_v1
}  // namespace cloud
}  // namespace google
