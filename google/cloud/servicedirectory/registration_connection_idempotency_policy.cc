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
// source: google/cloud/servicedirectory/v1/registration_service.proto

#include "google/cloud/servicedirectory/registration_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace servicedirectory {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

RegistrationServiceConnectionIdempotencyPolicy::
    ~RegistrationServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultRegistrationServiceConnectionIdempotencyPolicy
    : public RegistrationServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultRegistrationServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<RegistrationServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultRegistrationServiceConnectionIdempotencyPolicy>(*this);
  }

  Idempotency CreateNamespace(
      google::cloud::servicedirectory::v1::CreateNamespaceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListNamespaces(
      google::cloud::servicedirectory::v1::ListNamespacesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetNamespace(
      google::cloud::servicedirectory::v1::GetNamespaceRequest const&)
      override {
    return Idempotency::kIdempotent;
  }

  Idempotency UpdateNamespace(
      google::cloud::servicedirectory::v1::UpdateNamespaceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteNamespace(
      google::cloud::servicedirectory::v1::DeleteNamespaceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency CreateService(
      google::cloud::servicedirectory::v1::CreateServiceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListServices(
      google::cloud::servicedirectory::v1::ListServicesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetService(
      google::cloud::servicedirectory::v1::GetServiceRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency UpdateService(
      google::cloud::servicedirectory::v1::UpdateServiceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteService(
      google::cloud::servicedirectory::v1::DeleteServiceRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency CreateEndpoint(
      google::cloud::servicedirectory::v1::CreateEndpointRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListEndpoints(
      google::cloud::servicedirectory::v1::ListEndpointsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetEndpoint(
      google::cloud::servicedirectory::v1::GetEndpointRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency UpdateEndpoint(
      google::cloud::servicedirectory::v1::UpdateEndpointRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteEndpoint(
      google::cloud::servicedirectory::v1::DeleteEndpointRequest const&)
      override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<RegistrationServiceConnectionIdempotencyPolicy>
MakeDefaultRegistrationServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultRegistrationServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicedirectory
}  // namespace cloud
}  // namespace google
