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
// source: google/cloud/servicedirectory/v1/lookup_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_MOCKS_MOCK_LOOKUP_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_MOCKS_MOCK_LOOKUP_CONNECTION_H

#include "google/cloud/servicedirectory/lookup_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace servicedirectory_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockLookupServiceConnection
    : public servicedirectory::LookupServiceConnection {
 public:
  MOCK_METHOD(
      StatusOr<google::cloud::servicedirectory::v1::ResolveServiceResponse>,
      ResolveService,
      (google::cloud::servicedirectory::v1::ResolveServiceRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace servicedirectory_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SERVICEDIRECTORY_MOCKS_MOCK_LOOKUP_CONNECTION_H
