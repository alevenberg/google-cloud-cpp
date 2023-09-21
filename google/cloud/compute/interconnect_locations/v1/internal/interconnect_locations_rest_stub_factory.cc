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
// source:
// google/cloud/compute/interconnect_locations/v1/interconnect_locations.proto

#include "google/cloud/compute/interconnect_locations/v1/internal/interconnect_locations_rest_stub_factory.h"
#include "google/cloud/compute/interconnect_locations/v1/internal/interconnect_locations_rest_logging_decorator.h"
#include "google/cloud/compute/interconnect_locations/v1/internal/interconnect_locations_rest_metadata_decorator.h"
#include "google/cloud/compute/interconnect_locations/v1/internal/interconnect_locations_rest_stub.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/algorithm.h"
#include "google/cloud/internal/populate_common_options.h"
#include "google/cloud/internal/rest_options.h"
#include "google/cloud/log.h"
#include "google/cloud/options.h"
#include "google/cloud/rest_options.h"
#include "absl/strings/match.h"
#include <memory>

namespace google {
namespace cloud {
namespace compute_interconnect_locations_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<InterconnectLocationsRestStub>
CreateDefaultInterconnectLocationsRestStub(Options const& options) {
  Options opts = options;
  if (!opts.has<UnifiedCredentialsOption>()) {
    opts.set<UnifiedCredentialsOption>(
        MakeGoogleDefaultCredentials(internal::MakeAuthOptions(options)));
  }
  if (!opts.has<rest_internal::LongrunningEndpointOption>()) {
    opts.set<rest_internal::LongrunningEndpointOption>(
        "https://longrunning.googleapis.com");
  }
  if (opts.has<EndpointOption>()) {
    std::string endpoint = opts.get<EndpointOption>();
    if (!absl::StartsWithIgnoreCase(endpoint, "http")) {
      opts.set<EndpointOption>(absl::StrCat("https://", endpoint));
    }
  }
  std::shared_ptr<InterconnectLocationsRestStub> stub =
      std::make_shared<DefaultInterconnectLocationsRestStub>(std::move(opts));
  stub = std::make_shared<InterconnectLocationsRestMetadata>(std::move(stub));
  if (internal::Contains(options.get<TracingComponentsOption>(), "rpc")) {
    GCP_LOG(INFO) << "Enabled logging for REST rpc calls";
    stub = std::make_shared<InterconnectLocationsRestLogging>(
        std::move(stub), options.get<RestTracingOptionsOption>(),
        options.get<TracingComponentsOption>());
  }
  return stub;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace compute_interconnect_locations_v1_internal
}  // namespace cloud
}  // namespace google
