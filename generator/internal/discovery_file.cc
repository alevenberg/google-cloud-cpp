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

#include "generator/internal/discovery_file.h"
#include "generator/internal/codegen_utils.h"
#include "google/cloud/internal/absl_str_join_quiet.h"
#include "absl/strings/str_format.h"
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <fstream>

namespace google {
namespace cloud {
namespace generator_internal {
namespace {

std::string GeneratedProtoPreamble() {
  auto constexpr kPreamble = R"""(
// Generated by the C++ microgenerator.
// If you make any local changes, they will be lost.
// $discovery_doc_url$
// revision: $revision$
)""";
  return kPreamble;
}

}  // namespace

DiscoveryFile::DiscoveryFile(DiscoveryResource const* resource,
                             std::string file_path,
                             std::string relative_proto_path,
                             std::string package_name,
                             std::vector<DiscoveryTypeVertex*> types)
    : resource_(resource),
      file_path_(std::move(file_path)),
      relative_proto_path_(std::move(relative_proto_path)),
      package_name_(std::move(package_name)),
      types_(std::move(types)) {}

Status DiscoveryFile::FormatFile(
    DiscoveryDocumentProperties const& document_properties,
    std::map<std::string, DiscoveryTypeVertex> const& types,
    std::ostream& output_stream) const {
  std::map<std::string, std::string> const vars = {
      {"copyright_year", document_properties.copyright_year},
      {"discovery_doc_url", document_properties.discovery_doc_url},
      {"package_name", package_name_},
      {"product_name", document_properties.product_name},
      {"resource_name", (resource_ ? resource_->name() : "")},
      {"revision", document_properties.revision},
      {"version", document_properties.version}};
  google::protobuf::io::OstreamOutputStream output(&output_stream);
  google::protobuf::io::Printer printer(&output, '$');
  printer.Print(vars, CopyrightLicenseFileHeader().c_str());
  printer.Print(vars, GeneratedProtoPreamble().c_str());
  printer.Print(vars, R"""(
syntax = "proto3";

package $package_name$;
)""");

  if (!import_paths_.empty()) {
    printer.Print("\n");
    for (auto const& path : import_paths_) {
      printer.Print(vars, absl::StrFormat("import \"%s\";\n", path).c_str());
    }
  }

  if (resource_) {
    printer.Print("\n");
    auto service_definition =
        resource_->JsonToProtobufService(document_properties);
    if (!service_definition) {
      return std::move(service_definition).status();
    }
    printer.Print(vars, std::move(service_definition)->c_str());
  }

  for (auto const& t : types_) {
    auto message = t->JsonToProtobufMessage(types, package_name_);
    if (!message) {
    std::cout << "[alevenb]" << t->name() << "\n";
      return std::move(message).status();
    }
    printer.Print("\n");
    printer.Print(vars, std::move(message)->c_str());
  }

  return {};
}

Status DiscoveryFile::WriteFile(
    DiscoveryDocumentProperties const& document_properties,
    std::map<std::string, DiscoveryTypeVertex> const& types) const {
  std::string version_dir_path = file_path_.substr(0, file_path_.rfind('/'));
  std::string service_dir_path =
      version_dir_path.substr(0, version_dir_path.rfind('/'));
  MakeDirectory(service_dir_path);
  MakeDirectory(version_dir_path);
  std::ofstream os(file_path_);
  return FormatFile(document_properties, types, os);
}

}  // namespace generator_internal
}  // namespace cloud
}  // namespace google
