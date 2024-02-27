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

//! [START pubsub_quickstart_subscriber] [all]
#include "google/cloud/opentelemetry/configure_basic_tracing.h"
#include "google/cloud/pubsub/message.h"
#include "google/cloud/pubsub/options.h"
#include "google/cloud/pubsub/publisher.h"
#include "google/cloud/pubsub/subscriber.h"
#include "google/cloud/opentelemetry_options.h"
#include <iostream>

// bazel run //google/cloud/pubsub/quickstart:subscriber_quickstart
int main(int argc, char* argv[]) try {
  std::string const project_id = "alevenb-test";
  std::string const subscription_id = "orderd-sub";

  auto constexpr kWaitTimeout = std::chrono::seconds(30);

  // Create a namespace alias to make the code easier to read.
  namespace pubsub = ::google::cloud::pubsub;
  namespace otel = ::google::cloud::otel;
  namespace experimental = ::google::cloud::experimental;
  namespace gc = ::google::cloud;

  auto project = gc::Project(project_id);
  auto configuration = otel::ConfigureBasicTracing(project);

  // Create a client with OpenTelemetry tracing enabled.
  auto options = gc::Options{}.set<gc::OpenTelemetryTracingOption>(true);
  auto subscriber = pubsub::Subscriber(pubsub::MakeSubscriberConnection(
      pubsub::Subscription(project_id, subscription_id), options));
  std::string const topic_id = "orderd-topic";
  auto publisher = pubsub::Publisher(pubsub::MakePublisherConnection(
      pubsub::Topic(project_id, topic_id),
      gc::Options{}
          .set<gc::OpenTelemetryTracingOption>(true)
          .set<pubsub::MessageOrderingOption>(true)));

  int n = 6;
  std::vector<gc::future<void>> ids;
  for (int i = 0; i < n; i++) {
    std::string ordering_key = (i % 2 == 0 ? "a" : "b");
    auto id =
        publisher
            .Publish(pubsub::MessageBuilder()
                         .SetData(std::to_string(i))
                         .SetOrderingKey(ordering_key)
                         .Build())
            .then([index = i, key =ordering_key](gc::future<gc::StatusOr<std::string>> f) {
              auto status = f.get();
              if (!status) {
                std::cout << "Error in publish: " << status.status() << "\n";
                return;
              }
              std::cout << index << ". ";
              std::cout << "Sent message with id: (" << *status
                        << ") and ordering key (" << key << ")\n";
            });
    ids.push_back(std::move(id));
  }
  // Block until they are actually sent.
  for (auto& id : ids) id.get();

  auto session =
      subscriber.Subscribe([&](pubsub::Message const& m, pubsub::AckHandler h) {
        std::cout << m.data() << ". ";
        std::cout << "Received message with id: (" << m.message_id()
                  << ") and ordering key (" << m.ordering_key() << ")\n";
        sleep(2);
        std::move(h).ack();
      });

  std::cout << "Waiting for messages on " + subscription_id + "...\n";
  // Blocks until the timeout is reached.
  auto result = session.wait_for(kWaitTimeout);
  if (result == std::future_status::timeout) {
    std::cout << "timeout reached, ending session\n";
    session.cancel();
  }

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [END pubsub_quickstart_subscriber] [all]
