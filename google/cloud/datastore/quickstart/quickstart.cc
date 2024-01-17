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
#include "google/cloud/datastore/v1/datastore_client.h"
#include <iostream>

namespace datastore = ::google::cloud::datastore_v1;

void InsertItem(datastore::DatastoreClient& client, std::string project_id, std::string my_key, std::string my_action, std::string my_value) {
  google::datastore::v1::Key key;
  auto partition = key.mutable_partition_id();
  partition->set_project_id(project_id); 
  partition->set_database_id("my-native-db");
  auto& path = *key.add_path();
  path.set_kind("Task");
  path.set_name(my_key);

  google::datastore::v1::Mutation mutation;
  auto& upsert = *mutation.mutable_upsert();
  *upsert.mutable_key() = key;
  google::datastore::v1::Value value;
  value.set_string_value(my_action);
  upsert.mutable_properties()->insert({"action", std::move(value)});
  google::datastore::v1::Value value2;
  value2.set_string_value(my_value);
  upsert.mutable_properties()->insert({"item", std::move(value2)});

  google::datastore::v1::CommitRequest request;
  request.set_project_id(project_id);
  request.set_database_id("my-native-db");
  request.set_mode( google::datastore::v1::CommitRequest::NON_TRANSACTIONAL);
  *request.add_mutations() = mutation;

  auto put = client.Commit(request);
  if (!put) throw std::move(put).status();

  std::cout << "Saved " << key.DebugString() << " " << put->DebugString()
            << "\n";
}

void Query(datastore::DatastoreClient& client, std::string project_id) {
  google::datastore::v1::Query query;
  query.add_kind()->set_name("Task");

  // Create filter
  auto composite_filter = query.mutable_filter()->mutable_composite_filter();
  composite_filter->set_op(google::datastore::v1::CompositeFilter::AND); // Set the operator to AND

  auto *filter = composite_filter->add_filters();
  filter->mutable_property_filter()->mutable_property()->set_name("action");
  filter->mutable_property_filter()->set_op(google::datastore::v1::PropertyFilter::EQUAL);
  filter->mutable_property_filter()->mutable_value()->set_string_value("Buy");

  auto *filter2 = composite_filter->add_filters();
  filter2->mutable_property_filter()->mutable_property()->set_name("item");
  filter2->mutable_property_filter()->set_op(google::datastore::v1::PropertyFilter::EQUAL);
  filter2->mutable_property_filter()->mutable_value()->set_string_value("Milk");

  google::datastore::v1::RunQueryRequest request;
  *request.mutable_query() = std::move(query);
  request.set_project_id(project_id);
  request.set_database_id("my-native-db");  

  auto response = client.RunQuery(request);
  if (!response) throw std::move(response).status();

  for (auto const& c : response.value().batch().entity_results()) {
    for (auto const& p : c.entity().key().path()) {
      std::cout << p.name() << "\n";
    }
  }
}

int main(int argc, char* argv[]) try {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " project-id\n";
    return 1;
  }

  auto client =
      datastore::DatastoreClient(datastore::MakeDatastoreConnection());

  auto const* project_id = argv[1];

// Create and insert 3 elements
  // InsertItem(client, project_id, "sampletask4", "Buy", "Milk");
  // InsertItem(client, project_id, "sampletask5", "Buy", "Tea");
  //  InsertItem(client, project_id, "sampletask6", "Buy", "Coffee");
// Query using a composite filter for "action=Buy" and "item=Milk"
  Query(client, project_id);

  return 0;
} catch (google::cloud::Status const& status) {
  std::cerr << "google::cloud::Status thrown: " << status << "\n";
  return 1;
}
//! [all]