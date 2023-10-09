// Copyright 2023 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//! [all]
#include "google/cloud/gsuiteaddons/v1/g_suite_add_ons_client.h"
#include "google/cloud/project.h"
#include <iostream>

int main(int argc, char* argv[]) try {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " project-id\n";
    return 1;
  }

  namespace gsuiteaddons = ::google::cloud::gsuiteaddons_v1;
  auto client = gsuiteaddons::GSuiteAddOnsClient(
      gsuiteaddons::MakeGSuiteAddOnsConnection());

  auto const project = google::cloud::Project(argv[1]);

 // Test CreateDeployment call 
 google::cloud::gsuiteaddons::v1::Deployment deployment;
 deployment.set_name(project.FullName() +  "/deployment/alevenb-deploy");
 google::cloud::gsuiteaddons::v1::AddOns add_on;
 google::apps::script::type::gmail::GmailAddOnManifest gmail_add_on;
 *add_on.mutable_gmail() = gmail_add_on;
 *deployment.mutable_add_ons() = add_on;
  client.CreateDeployment(project.FullName(), deployment, project.FullName() +  "/deployment/alevenb-deploy");

  for (auto r : client.ListDeployments(project.FullName())) {
    if (!r) throw std::move(r).status();
    std::cout << r->DebugString() << "\n";
  }

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [all]
