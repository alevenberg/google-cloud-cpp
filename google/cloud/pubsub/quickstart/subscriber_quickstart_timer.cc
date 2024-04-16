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
  std::string const subscription_id = "my-sub";

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
  options.set<pubsub::MinDeadlineExtensionOption>(std::chrono::seconds(1));
  options.set<pubsub::MaxDeadlineExtensionOption>(std::chrono::seconds(3));
 // lease management options
  options.set<pubsub::MaxOutstandingMessagesOption>(2);
  // options.set<pubsub::MaxOutstandingBytesOption>(8 * kMiB);
          // Concurrency
          //  options .set<pubsub::MaxConcurrencyOption>(8);
          //  options .set<GrpcBackgroundThreadPoolSizeOption>(16);
  auto subscriber = pubsub::Subscriber(pubsub::MakeSubscriberConnection(
      pubsub::Subscription(project_id, subscription_id), options));

  // auto message = subscriber.Pull()
  // auto response = subscriber.Pull();
  // if (!response) throw std::move(response).status();
  // std::cout << "Received message " << response->message << "\n";
  // std::move(response->handler).ack();

  std::string const topic_id = "my-topic";

  // Create a client with OpenTelemetry tracing enabled.
  // .set<pubsub::MaxBatchMessagesOption>(1000)
  // .set<pubsub::MaxHoldTimeOption>(std::chrono::seconds(1));

  auto publisher = pubsub::Publisher(pubsub::MakePublisherConnection(
      pubsub::Topic(project_id, topic_id),
      gc::Options{}.set<gc::OpenTelemetryTracingOption>(true)));

  int n = 1000;
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

  auto session =
      subscriber.Subscribe([&](pubsub::Message const& m, pubsub::AckHandler h) {
        // std::stringstream msg;
        msg << "Received message " << m
            << "with attributes: " << m.attributes().size() << "\n";
        // std::cout << msg.str();
        // for (const auto& item : m.attributes()) {
        //   std::stringstream attribute_msg;
        //   attribute_msg << "Key: " << item.first << "Value: " << item.second
        //                 << "\n";
        //   std::cout << attribute_msg.str();
        // }
        // std::move(h).nack();
        std::move(h).ack();
      });

  std::cout << "Waiting for messages on " + subscription_id + "...\n";

  // session.wait();
  // Blocks until the timeout is reached.
  auto result = session.wait_for(kWaitTimeout);
  if (result == std::future_status::timeout) {
    std::cout << "timeout reached, ending session\n";
    session.cancel();
  }
  session.get();
  session =
      subscriber.Subscribe([&](pubsub::Message const& m, pubsub::AckHandler h) {
        std::cout << "Received message " << m << "\n";
        std::move(h).ack();
      });

  std::cout << "Waiting for messages on " + subscription_id + "...\n";

  // Blocks until the timeout is reached.
  result = session.wait_for(kWaitTimeout);
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
