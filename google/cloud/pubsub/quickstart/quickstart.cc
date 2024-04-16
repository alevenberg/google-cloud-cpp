// Copyright 2020 Google LLC
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

//! [START pubsub_quickstart_publisher] [all]
#include "google/cloud/opentelemetry/configure_basic_tracing.h"
#include "google/cloud/pubsub/publisher.h"
#include "google/cloud/opentelemetry_options.h"
#include <iostream>

int main(int argc, char* argv[]) try {
  std::string const project_id = "alevenb-test";
  std::string const topic_id = "my-topic";

  // Create a namespace alias to make the code easier to read.
  namespace pubsub = ::google::cloud::pubsub;
  namespace gc = ::google::cloud;
  namespace otel = ::google::cloud::otel;

  auto project = gc::Project(project_id);
  auto configuration = otel::ConfigureBasicTracing(project);

  // Create a client with OpenTelemetry tracing enabled.
  auto options = gc::Options{}.set<gc::OpenTelemetryTracingOption>(false);
  // .set<pubsub::MaxBatchMessagesOption>(1000)
  // .set<pubsub::MaxHoldTimeOption>(std::chrono::seconds(1));

  auto publisher = pubsub::Publisher(pubsub::MakePublisherConnection(
      pubsub::Topic(project_id, topic_id), options));

  int n = 10;
  std::vector<gc::future<void>> ids;
  for (int i = 0; i < n; i++) {
    auto id = publisher.Publish(pubsub::MessageBuilder().SetData("Hi!").Build())
                  .then([](gc::future<gc::StatusOr<std::string>> f) {
                    auto status = f.get();
                    if (!status) {
                      std::cout << "Error in publish: " << status.status()
                                << "\n";
                      return;
                    }
                    std::cout << "Sent message with id: (" << *status << ")\n";
                  });
    ids.push_back(std::move(id));
  }
  // Block until they are actually sent.
  for (auto& id : ids) id.get();

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [END pubsub_quickstart_publisher] [all]
