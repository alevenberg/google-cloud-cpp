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
#include "google/cloud/pubsub/subscriber.h"
#include "google/cloud/opentelemetry_options.h"
#include <iostream>

auto constexpr kWaitTimeout = std::chrono::minutes(1);

void WaitForSession(google::cloud::future<google::cloud::Status> session,
                    std::string const& name) {
  std::cout << "\nWaiting for session [" << name << "]... " << std::flush;
  auto result = session.wait_for(kWaitTimeout);
  if (result == std::future_status::timeout) {
    std::cout << "TIMEOUT" << std::endl;
    throw std::runtime_error("session timeout");
  }
  std::cout << "DONE (" << session.get() << ")" << std::endl;
}
class EventCounter {
 public:
  EventCounter() = default;

  void Increment() {
    std::lock_guard<std::mutex> lk(mu_);
    ++counter_;
    cv_.notify_all();
  }

  std::int64_t Current() {
    std::lock_guard<std::mutex> lk(mu_);
    return counter_;
  }

  template <typename Predicate>
  void Wait(Predicate&& predicate,
            google::cloud::future<google::cloud::Status> session,
            std::string const& name) {
    std::unique_lock<std::mutex> lk(mu_);
    cv_.wait_for(lk, kWaitTimeout,
                 [this, &predicate] { return predicate(counter_); });
    lk.unlock();
    session.cancel();
    WaitForSession(std::move(session), name);
  }

  template <typename Predicate>
  void Wait(Predicate&& predicate) {
    std::unique_lock<std::mutex> lk(mu_);
    cv_.wait_for(lk, kWaitTimeout,
                 [this, &predicate] { return predicate(counter_); });
  }

  static EventCounter& Instance() {
    static auto* const kInstance = new EventCounter;
    return *kInstance;
  }

 private:
  std::int64_t counter_ = 0;
  std::mutex mu_;
  std::condition_variable cv_;
};
// bazel run //google/cloud/pubsub/quickstart:subscriber_quickstart
int main(int argc, char* argv[]) try {
  std::string const project_id = "alevenb-test";
  std::string const subscription_id = "my-sub";

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
auto current = EventCounter::Instance().Current(); 
  auto session =
      subscriber.Subscribe([&](pubsub::Message const& m, pubsub::AckHandler h) {
        std::stringstream msg;
        msg << "Received message " << m
            << "with attributes: " << m.attributes().size() << "\n";
        std::cout << msg.str();

        for (const auto& item : m.attributes()) {
          std::stringstream attribute_msg;
          attribute_msg << "Key: " << item.first << "Value: " << item.second
                        << "\n";
          std::cout << attribute_msg.str();
        }
        std::move(h).ack();
        EventCounter::Instance().Increment();
      });

  // // session.wait();
  // Blocks until the timeout is reached.
  EventCounter::Instance().Wait(
      [current](std::int64_t count) { return count > current; }, std::move(session), "name");
  session.cancel();
  session.get();
  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [END pubsub_quickstart_subscriber] [all]
