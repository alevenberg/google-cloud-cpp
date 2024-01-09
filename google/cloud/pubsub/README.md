# Google Cloud Pub/Sub C++ Client Library

This directory contains an idiomatic C++ client library for interacting with
[Cloud Pub/Sub](https://cloud.google.com/pubsub/), an asynchronous messaging
service that decouples services that produce events from services that process
events.

While this library is **GA**, please note that the Google Cloud C++ client
libraries do **not** follow [Semantic Versioning](https://semver.org/).

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->

```cc
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
```

<!-- inject-quickstart-end -->

## More Information

- Official documentation about the [Cloud Pub/Sub][cloud-pubsub-docs] service
- [Reference doxygen documentation][doxygen-link] for each release of this
  client library
- Detailed header comments in our [public `.h`][source-link] files

[cloud-pubsub-docs]: https://cloud.google.com/pubsub/docs/
[doxygen-link]: https://cloud.google.com/cpp/docs/reference/pubsub/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/pubsub
