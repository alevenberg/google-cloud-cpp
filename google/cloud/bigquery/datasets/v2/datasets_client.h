// Copyright 2024 Google LLC
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
// source: google/cloud/bigquery/datasets/v2/datasets.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_DATASETS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_DATASETS_CLIENT_H

#include "google/cloud/bigquery/datasets/v2/datasets_rest_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_datasets_v2 {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for the datasets resource.
/// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class DatasetsClient {
 public:
  explicit DatasetsClient(std::shared_ptr<DatasetsConnection> connection, Options opts = {});
  ~DatasetsClient();

  ///@{
  /// @name Copy and move support
  DatasetsClient(DatasetsClient const&) = default;
  DatasetsClient& operator=(DatasetsClient const&) = default;
  DatasetsClient(DatasetsClient&&) = default;
  DatasetsClient& operator=(DatasetsClient&&) = default;
  ///@}

  ///@{
  /// @name Equality
  friend bool operator==(DatasetsClient const& a, DatasetsClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(DatasetsClient const& a, DatasetsClient const& b) {
    return !(a == b);
  }
  ///@}

  // clang-format off
  ///
  /// Deletes the dataset specified by the datasetId value. Before you can delete
  /// a dataset, you must delete all its tables, either manually or by specifying
  /// deleteContents. Immediately after deletion, you can create another dataset
  /// with the same name.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/delete
  ///
  /// @param project_id  Required. Project ID of the dataset being deleted
  /// @param dataset_id  Required. Dataset ID of dataset being deleted
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.DeleteDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L119}
  ///
  // clang-format on
  Status
  DeleteDataset(std::string const& project_id, std::string const& dataset_id, Options opts = {});

  // clang-format off
  ///
  /// Deletes the dataset specified by the datasetId value. Before you can delete
  /// a dataset, you must delete all its tables, either manually or by specifying
  /// deleteContents. Immediately after deletion, you can create another dataset
  /// with the same name.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/delete
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.DeleteDatasetRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return a [`Status`] object. If the request failed, the
  ///     status contains the details of the failure.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.DeleteDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L119}
  ///
  // clang-format on
  Status
  DeleteDataset(google::cloud::cpp::bigquery::datasets::v2::DeleteDatasetRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Returns the dataset specified by datasetID.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/get
  ///
  /// @param project_id  Required. Project ID of the requested dataset
  /// @param dataset_id  Required. Dataset ID of the requested dataset
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.GetDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L132}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  GetDataset(std::string const& project_id, std::string const& dataset_id, Options opts = {});

  // clang-format off
  ///
  /// Returns the dataset specified by datasetID.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/get
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.GetDatasetRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.GetDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L132}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  GetDataset(google::cloud::cpp::bigquery::datasets::v2::GetDatasetRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Creates a new empty dataset.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/insert
  ///
  /// @param project_id  Required. Project ID of the new dataset
  /// @param dataset_resource  The Dataset for this request.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.InsertDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L151}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  InsertDataset(std::string const& project_id, google::cloud::cpp::bigquery::v2::Dataset const& dataset_resource, Options opts = {});

  // clang-format off
  ///
  /// Creates a new empty dataset.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/insert
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.InsertDatasetRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.InsertDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L151}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  InsertDataset(google::cloud::cpp::bigquery::datasets::v2::InsertDatasetRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Lists all datasets in the specified project to which the user has been
  /// granted the READER dataset role.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/list
  ///
  /// @param project_id  Required. Project ID of the datasets to be listed
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.DatasetList])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.ListDatasetsRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L160}
  /// [google.cloud.cpp.bigquery.v2.DatasetList]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L264}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::DatasetList>
  ListDatasets(std::string const& project_id, Options opts = {});

  // clang-format off
  ///
  /// Lists all datasets in the specified project to which the user has been
  /// granted the READER dataset role.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/list
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.ListDatasetsRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.DatasetList])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.ListDatasetsRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L160}
  /// [google.cloud.cpp.bigquery.v2.DatasetList]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L264}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::DatasetList>
  ListDatasets(google::cloud::cpp::bigquery::datasets::v2::ListDatasetsRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Updates information in an existing dataset. The update method replaces the
  /// entire dataset resource, whereas the patch method only replaces fields that
  /// are provided in the submitted dataset resource. This method supports
  /// RFC5789 patch semantics.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/patch
  ///
  /// @param project_id  Required. Project ID of the dataset being updated
  /// @param dataset_id  Required. Dataset ID of the dataset being updated
  /// @param dataset_resource  The Dataset for this request.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.PatchDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L185}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  PatchDataset(std::string const& project_id, std::string const& dataset_id, google::cloud::cpp::bigquery::v2::Dataset const& dataset_resource, Options opts = {});

  // clang-format off
  ///
  /// Updates information in an existing dataset. The update method replaces the
  /// entire dataset resource, whereas the patch method only replaces fields that
  /// are provided in the submitted dataset resource. This method supports
  /// RFC5789 patch semantics.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/patch
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.PatchDatasetRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.PatchDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L185}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  PatchDataset(google::cloud::cpp::bigquery::datasets::v2::PatchDatasetRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Undeletes a dataset which is within time travel window based on datasetId.
  /// If a time is specified, the dataset version deleted at that time is
  /// undeleted, else the last live version is undeleted.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/undelete
  ///
  /// @param project_id  Required. Project ID of the dataset to be undeleted
  /// @param dataset_id  Required. Dataset ID of dataset being deleted
  /// @param undelete_dataset_request_resource  The UndeleteDatasetRequest for this request.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.UndeleteRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L197}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  Undelete(std::string const& project_id, std::string const& dataset_id, google::cloud::cpp::bigquery::v2::UndeleteDatasetRequest const& undelete_dataset_request_resource, Options opts = {});

  // clang-format off
  ///
  /// Undeletes a dataset which is within time travel window based on datasetId.
  /// If a time is specified, the dataset version deleted at that time is
  /// undeleted, else the last live version is undeleted.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/undelete
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.UndeleteRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.UndeleteRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L197}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  Undelete(google::cloud::cpp::bigquery::datasets::v2::UndeleteRequest const& request, Options opts = {});

  // clang-format off
  ///
  /// Updates information in an existing dataset. The update method replaces the
  /// entire dataset resource, whereas the patch method only replaces fields that
  /// are provided in the submitted dataset resource.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/update
  ///
  /// @param project_id  Required. Project ID of the dataset being updated
  /// @param dataset_id  Required. Dataset ID of the dataset being updated
  /// @param dataset_resource  The Dataset for this request.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.UpdateDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L209}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  UpdateDataset(std::string const& project_id, std::string const& dataset_id, google::cloud::cpp::bigquery::v2::Dataset const& dataset_resource, Options opts = {});

  // clang-format off
  ///
  /// Updates information in an existing dataset. The update method replaces the
  /// entire dataset resource, whereas the patch method only replaces fields that
  /// are provided in the submitted dataset resource.
  /// https://cloud.google.com/bigquery/docs/reference/rest/v2/datasets/update
  ///
  /// @param request Unary RPCs, such as the one wrapped by this
  ///     function, receive a single `request` proto message which includes all
  ///     the inputs for the RPC. In this case, the proto message is a
  ///     [google.cloud.cpp.bigquery.datasets.v2.UpdateDatasetRequest].
  ///     Proto messages are converted to C++ classes by Protobuf, using the
  ///     [Protobuf mapping rules].
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return the result of the RPC. The response message type
  ///     ([google.cloud.cpp.bigquery.v2.Dataset])
  ///     is mapped to a C++ class using the [Protobuf mapping rules].
  ///     If the request fails, the [`StatusOr`] contains the error details.
  ///
  /// [Protobuf mapping rules]: https://protobuf.dev/reference/cpp/cpp-generated/
  /// [input iterator requirements]: https://en.cppreference.com/w/cpp/named_req/InputIterator
  /// [`std::string`]: https://en.cppreference.com/w/cpp/string/basic_string
  /// [`future`]: @ref google::cloud::future
  /// [`StatusOr`]: @ref google::cloud::StatusOr
  /// [`Status`]: @ref google::cloud::Status
  /// [google.cloud.cpp.bigquery.datasets.v2.UpdateDatasetRequest]: @cloud_cpp_reference_link{google/cloud/bigquery/datasets/v2/datasets.proto#L209}
  /// [google.cloud.cpp.bigquery.v2.Dataset]: @cloud_cpp_reference_link{google/cloud/bigquery/v2/internal/common_007.proto#L28}
  ///
  // clang-format on
  StatusOr<google::cloud::cpp::bigquery::v2::Dataset>
  UpdateDataset(google::cloud::cpp::bigquery::datasets::v2::UpdateDatasetRequest const& request, Options opts = {});

 private:
  std::shared_ptr<DatasetsConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_datasets_v2
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGQUERY_DATASETS_V2_DATASETS_CLIENT_H
