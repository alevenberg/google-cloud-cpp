# Google Workspace Add-ons API C++ Client Library

This directory contains an idiomatic C++ client library for the
[Google Workspace Add-ons API][cloud-service-docs], a service to allow
deployments to GCP of "add ons" for things like GMail and Google Docs.

While this library is **GA**, please note that the Google Cloud C++ client
libraries do **not** follow [Semantic Versioning](https://semver.org/).

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->

```cc
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
  for (auto r : client.ListDeployments(project.FullName())) {
    if (!r) throw std::move(r).status();
    std::cout << r->DebugString() << "\n";
  }

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
```

<!-- inject-quickstart-end -->

## More Information

- Official documentation about the
  [Google Workspace Add-ons API][cloud-service-docs] service
- [Reference doxygen documentation][doxygen-link] for each release of this
  client library
- Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/gsuiteaddons
[doxygen-link]: https://cloud.google.com/cpp/docs/reference/gsuiteaddons/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/gsuiteaddons
