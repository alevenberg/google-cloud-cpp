// Copyright 2024 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsub/samples/pubsub_samples_common.h"
#include "google/cloud/pubsub/schema.h"
#include "google/cloud/pubsub/schema_client.h"
#include "google/cloud/pubsub/subscriber.h"
#include "google/cloud/pubsub/subscription_admin_client.h"
#include "google/cloud/pubsub/subscription_builder.h"
#include "google/cloud/pubsub/admin/topic_admin_client.h"
#include "google/cloud/internal/getenv.h"
#include "google/cloud/internal/random.h"
#include "google/cloud/project.h"
#include "google/cloud/status.h"
#include "google/cloud/testing_util/example_driver.h"
#include <google/cloud/pubsub/samples/testdata/schema.pb.h>
#include <google/protobuf/text_format.h>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <tuple>
#include <utility>

namespace {

using ::google::cloud::pubsub::examples::CleanupSchemas;
using ::google::cloud::pubsub::examples::CommitSchemaWithRevisionsForTesting;
using ::google::cloud::pubsub::examples::RandomSchemaId;
using ::google::cloud::pubsub::examples::RandomSnapshotId;
using ::google::cloud::pubsub::examples::RandomSubscriptionId;
using ::google::cloud::pubsub::examples::RandomTopicId;
using ::google::cloud::pubsub::examples::ReadFile;
using ::google::cloud::pubsub::examples::UsingEmulator;

void CreateTopic(google::cloud::pubsub_admin::TopicAdminClient client,
                 std::vector<std::string> const& argv) {
  //! [START pubsub_quickstart_create_topic]
  //! [START pubsub_create_topic] [create-topic]
  namespace pubsub_admin = ::google::cloud::pubsub_admin;
  [](pubsub_admin::TopicAdminClient client, std::string project_id,
     std::string topic_id) {
    auto topic = client.CreateTopic(
        pubsub::Topic(std::move(project_id), std::move(topic_id).FullName()));
    // Note that kAlreadyExists is a possible error when the library retries.
    if (topic.status().code() == google::cloud::StatusCode::kAlreadyExists) {
      std::cout << "The topic already exists\n";
      return;
    }
    if (!topic) throw std::move(topic).status();

    std::cout << "The topic was successfully created: " << topic->DebugString()
              << "\n";
  }
  //! [END pubsub_create_topic] [create-topic]
  //! [END pubsub_quickstart_create_topic]
  (std::move(client), argv.at(0), argv.at(1));
}

// void GetTopic(google::cloud::pubsub_admin::TopicAdminClient client,
//               std::vector<std::string> const& argv) {
//   //! [get-topic]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id) {
//     auto topic = client.GetTopic(
//        pubsub::Topic(std::move(project_id), std::move(topic_id).FullName()));
//     if (!topic) throw std::move(topic).status();

//     std::cout << "The topic information was successfully retrieved: "
//               << topic->DebugString() << "\n";
//   }
//   //! [get-topic]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void UpdateTopic(google::cloud::pubsub_admin::TopicAdminClient client,
//                  std::vector<std::string> const& argv) {
//   //! [update-topic]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id) {
//      google::pubsub::v1::Topic  topic;
//      topic->set_name( pubsub::Topic(std::move(project_id), std::move(topic_id)).FullName());
//      topic->add_label("test-key", "test-value");
//     auto topic = client.UpdateTopic( topic, google::protobuf::FieldMask{}) ;
//     if (!topic) throw std::move(topic).status();

//     std::cout << "The topic was successfully updated: " << topic->DebugString()
//               << "\n";
//   }
//   //! [update-topic]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void ListTopics(google::cloud::pubsub_admin::TopicAdminClient client,
//                 std::vector<std::string> const& argv) {
//   //! [START pubsub_list_topics] [list-topics]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string const& project_id) {
//     int count = 0;
//     for (auto& topic : client.ListTopics(project_id)) {
//       if (!topic) throw std::move(topic).status();
//       std::cout << "Topic Name: " << topic->name() << "\n";
//       ++count;
//     }
//     if (count == 0) {
//       std::cout << "No topics found in project " << project_id << "\n";
//     }
//   }
//   //! [END pubsub_list_topics] [list-topics]
//   (std::move(client), argv.at(0));
// }

// void DeleteTopic(google::cloud::pubsub_admin::TopicAdminClient client,
//                  std::vector<std::string> const& argv) {
//   //! [START pubsub_delete_topic] [delete-topic]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string const& project_id,
//      std::string const& topic_id) {
//     auto status = client.DeleteTopic(pubsub::Topic(project_id, topic_id));
//     // Note that kNotFound is a possible result when the library retries.
//     if (status.code() == google::cloud::StatusCode::kNotFound) {
//       std::cout << "The topic was not found\n";
//       return;
//     }
//     if (!status.ok()) throw std::runtime_error(status.message());

//     std::cout << "The topic was successfully deleted\n";
//   }
//   //! [END pubsub_delete_topic] [delete-topic]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void DetachSubscription(google::cloud::pubsub_admin::TopicAdminClient client,
//                         std::vector<std::string> const& argv) {
//   //! [START pubsub_detach_subscription] [detach-subscription]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string const& project_id,
//      std::string const& subscription_id) {
//     auto response = client.DetachSubscription(
//         pubsub::Subscription(project_id, subscription_id).FullName());
//     if (!response.ok()) throw std::move(response).status();

//     std::cout << "The subscription was successfully detached: "
//               << response->DebugString() << "\n";
//   }
//   //! [END pubsub_detach_subscription] [detach-subscription]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void ListTopicSubscriptions(google::cloud::pubsub_admin::TopicAdminClient client,
//                             std::vector<std::string> const& argv) {
//   //! [START pubsub_list_topic_subscriptions] [list-topic-subscriptions]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string const& project_id,
//      std::string const& topic_id) {
//     auto const topic = pubsub::Topic(project_id, topic_id);
//     std::cout << "Subscription list for topic " << topic << ":\n";
//     for (auto& name : client.ListTopicSubscriptions(topic)) {
//       if (!name) throw std::move(name).status();
//       std::cout << "  " << *name << "\n";
//     }
//   }
//   //! [END pubsub_list_topic_subscriptions] [list-topic-subscriptions]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void ListTopicSnapshots(google::cloud::pubsub_admin::TopicAdminClient client,
//                         std::vector<std::string> const& argv) {
//   //! [list-topic-snapshots]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id) {
//     auto const topic =
//         pubsub::Topic(std::move(project_id), std::move(topic_id));
//     std::cout << "Snapshot list for topic " << topic << ":\n";
//     for (auto& name : client.ListTopicSnapshots(topic)) {
//       if (!name) throw std::move(name).status();
//       std::cout << "  " << *name << "\n";
//     }
//   }
//   //! [list-topic-snapshots]
//   (std::move(client), argv.at(0), argv.at(1));
// }

// void ExampleStatusOr(google::cloud::pubsub_admin::TopicAdminClient client,
//                      std::vector<std::string> const& argv) {
//   //! [example-status-or]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string const& project_id) {
//     // The actual type of `topic` is
//     // google::cloud::StatusOr<google::pubsub::v1::Topic>, but
//     // we expect it'll most often be declared with auto like this.
//     for (auto& topic : client.ListTopics(project_id)) {
//       // Use `topic` like a smart pointer; check it before de-referencing
//       if (!topic) {
//         // `topic` doesn't contain a value, so `.status()` will contain error
//         // info
//         std::cerr << topic.status() << "\n";
//         break;
//       }
//       std::cout << topic->DebugString() << "\n";
//     }
//   }
//   //! [example-status-or]
//   (std::move(client), argv.at(0));
// }

// void CreateTopicWithSchema(google::cloud::pubsub_admin::TopicAdminClient client,
//                            std::vector<std::string> const& argv) {
//   //! [START pubsub_create_topic_with_schema]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id, std::string schema_id, std::string const& encoding) {
//     auto const& schema = pubsub::Schema(project_id, std::move(schema_id));
//     auto topic = client.CreateTopic(
//         pubsub::TopicBuilder(
//             pubsub::Topic(std::move(project_id), std::move(topic_id)))
//             .set_schema(schema)
//             .set_encoding(encoding == "JSON" ? google::pubsub::v1::JSON
//                                              : google::pubsub::v1::BINARY));
//     // Note that kAlreadyExists is a possible error when the library retries.
//     if (topic.status().code() == google::cloud::StatusCode::kAlreadyExists) {
//       std::cout << "The topic already exists\n";
//       return;
//     }
//     if (!topic) throw std::move(topic).status();

//     std::cout << "The topic was successfully created: " << topic->DebugString()
//               << "\n";
//   }
//   //! [END pubsub_create_topic_with_schema]
//   (std::move(client), argv.at(0), argv.at(1), argv.at(2), argv.at(3));
// }

// void CreateTopicWithSchemaRevisions(
//     google::cloud::pubsub_admin::TopicAdminClient client,
//     std::vector<std::string> const& argv) {
//   //! [START pubsub_create_topic_with_schema_revisions]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id, std::string schema_id, std::string const& encoding,
//      std::string const& first_revision_id,
//      std::string const& last_revision_id) {
//     auto const& schema = pubsub::Schema(project_id, std::move(schema_id));
//     auto topic = client.CreateTopic(
//         pubsub::TopicBuilder(
//             pubsub::Topic(std::move(project_id), std::move(topic_id)))
//             .set_schema(schema)
//             .set_encoding(encoding == "JSON" ? google::pubsub::v1::JSON
//                                              : google::pubsub::v1::BINARY)
//             .set_first_revision_id(first_revision_id)
//             .set_last_revision_id(last_revision_id));

//     // Note that kAlreadyExists is a possible error when the
//     // library retries.
//     if (topic.status().code() == google::cloud::StatusCode::kAlreadyExists) {
//       std::cout << "The topic already exists\n";
//       return;
//     }
//     if (!topic) throw std::move(topic).status();

//     std::cout << "The topic was successfully created: " << topic->DebugString()
//               << "\n";
//   }
//   //! [END pubsub_create_topic_with_schema_revisions]
//   (std::move(client), argv.at(0), argv.at(1), argv.at(2), argv.at(3),
//    argv.at(4), argv.at(5));
// }

// void UpdateTopicSchema(google::cloud::pubsub_admin::TopicAdminClient client,
//                        std::vector<std::string> const& argv) {
//   //! [START pubsub_update_topic_schema]
//   namespace pubsub_admin = ::google::cloud::pubsub_admin;
//   [](pubsub_admin::TopicAdminClient client, std::string project_id,
//      std::string topic_id, std::string const& first_revision_id,
//      std::string const& last_revision_id) {
//     auto topic = client.UpdateTopic(
//         pubsub::TopicBuilder(
//             pubsub::Topic(std::move(project_id), std::move(topic_id)))
//             .set_first_revision_id(first_revision_id)
//             .set_last_revision_id(last_revision_id));

//     if (!topic) throw std::move(topic).status();

//     std::cout << "The topic was successfully updated: " << topic->DebugString()
//               << "\n";
//   }
//   //! [END pubsub_update_topic_schema]
//   (std::move(client), argv.at(0), argv.at(1), argv.at(2), argv.at(3));
// }

// void AutoRunAvro(
//     std::string const& project_id, std::string const& testdata_directory,
//     google::cloud::internal::DefaultPRNG& generator,
//     google::cloud::pubsub_admin::TopicAdminClient& topic_admin_client,
//     google::cloud::pubsub::SubscriptionAdminClient& subscription_admin_client) {
//   auto schema_admin = google::cloud::pubsub::SchemaServiceClient(
//       google::cloud::pubsub::MakeSchemaServiceConnection());
//   auto avro_schema_id = RandomSchemaId(generator);
//   auto avro_schema_definition_file = testdata_directory + "schema.avsc";
//   auto avro_revised_schema_definition_file =
//       testdata_directory + "revised_schema.avsc";
//   auto avro_message_file = testdata_directory + "valid_message.avsc";

//   // For testing commands that require a revision id.
//   auto avro_revision_schema_id = RandomSchemaId(generator);
//   auto const avro_revision_topic_id = RandomTopicId(generator);
//   auto const revision_ids = CommitSchemaWithRevisionsForTesting(
//       schema_admin, project_id, avro_revision_schema_id,
//       avro_schema_definition_file, avro_revised_schema_definition_file, "AVRO");
//   auto const first_revision_id = revision_ids.first;
//   auto const last_revision_id = revision_ids.second;
//   std::cout << "\nRunning CreateTopicWithSchemaRevisions sample [avro]"
//             << std::endl;
//   CreateTopicWithSchemaRevisions(
//       topic_admin_client,
//       {project_id, avro_revision_topic_id, avro_revision_schema_id, "JSON",
//        first_revision_id, last_revision_id});
//   UpdateTopicSchema(topic_admin_client, {project_id, avro_revision_topic_id,
//                                          first_revision_id, first_revision_id});

//   std::cout
//       << "\nCleaning up the topic and schema created for testing revisions"
//       << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, avro_revision_topic_id});
//   DeleteSchema(schema_admin, {project_id, avro_revision_schema_id});

//   std::cout << "\nRunning CreateTopicWithSchema() sample [avro]" << std::endl;
//   auto const avro_topic_id = RandomTopicId(generator);
//   CreateTopicWithSchema(topic_admin_client,
//                         {project_id, avro_topic_id, avro_schema_id, "JSON"});

//   auto topic = google::cloud::pubsub::Topic(project_id, avro_topic_id);

//   std::cout << "\nRunning DeleteTopic() sample [avro]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, avro_topic_id});

// }

// void AutoRunProtobuf(
//     std::string const& project_id, std::string const& testdata_directory,
//     google::cloud::internal::DefaultPRNG& generator,
//     google::cloud::pubsub_admin::TopicAdminClient& topic_admin_client,
//     google::cloud::pubsub::SubscriptionAdminClient& subscription_admin_client) {
//   auto schema_admin = google::cloud::pubsub::SchemaServiceClient(
//       google::cloud::pubsub::MakeSchemaServiceConnection());
//   auto proto_schema_id = RandomSchemaId(generator);
//   auto proto_schema_definition_file = testdata_directory + "schema.proto";
//   auto proto_revised_schema_definition_file =
//       testdata_directory + "revised_schema.proto";
//   auto proto_message_file = testdata_directory + "valid_message.pb";

//   // For testing commands that require a revision id.
//   auto proto_revision_schema_id = RandomSchemaId(generator);
//   auto const proto_revision_topic_id = RandomTopicId(generator);
//   auto const revision_ids = CommitSchemaWithRevisionsForTesting(
//       schema_admin, project_id, proto_revision_schema_id,
//       proto_schema_definition_file, proto_revised_schema_definition_file,
//       "PROTO");
//   auto const first_revision_id = revision_ids.first;
//   auto const last_revision_id = revision_ids.second;
//   std::cout << "\nRunning CreateTopicWithSchemaRevisions sample [proto]"
//             << std::endl;
//   CreateTopicWithSchemaRevisions(
//       topic_admin_client,
//       {project_id, proto_revision_topic_id, proto_revision_schema_id, "BINARY",
//        first_revision_id, last_revision_id});
//   UpdateTopicSchema(topic_admin_client, {project_id, proto_revision_topic_id,
//                                          first_revision_id, first_revision_id});

//   std::cout
//       << "\nCleaning up the topic and schema created for testing revisions"
//       << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, proto_revision_topic_id});
//   DeleteSchema(schema_admin, {project_id, proto_revision_schema_id});

//   std::cout << "\nRunning CreateTopicWithSchema() sample [proto]" << std::endl;
//   auto const proto_topic_id = RandomTopicId(generator);
//   CreateTopicWithSchema(topic_admin_client, {project_id, proto_topic_id,
//                                              proto_schema_id, "BINARY"});

//   auto topic = google::cloud::pubsub::Topic(project_id, proto_topic_id);

//   std::cout << "\nRunning DeleteTopic() sample [proto]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, proto_topic_id});
// }

void AutoRun(std::vector<std::string> const& argv) {
  namespace examples = ::google::cloud::testing_util;

  if (!argv.empty()) throw examples::Usage{"auto"};
  examples::CheckEnvironmentVariablesAreSet({"GOOGLE_CLOUD_PROJECT"});
  auto project_id =
      google::cloud::internal::GetEnv("GOOGLE_CLOUD_PROJECT").value();

//   auto generator = google::cloud::internal::MakeDefaultPRNG();
//   auto const topic_id = RandomTopicId(generator);
//   auto const subscription_id = RandomSubscriptionId(generator);
//   auto const exactly_once_subscription_id = RandomSubscriptionId(generator);
//   auto const filtered_subscription_id = RandomSubscriptionId(generator);
//   auto const push_subscription_id = RandomSubscriptionId(generator);
//   auto const unwrapped_push_subscription_id = RandomSubscriptionId(generator);
//   auto const cloud_storage_subscription_id = RandomSubscriptionId(generator);
//   auto const bigquery_subscription_id = RandomSubscriptionId(generator);
//   auto const ordering_subscription_id = RandomSubscriptionId(generator);
//   auto const ordering_topic_id = "ordering-" + RandomTopicId(generator);
//   auto const dead_letter_subscription_id = RandomSubscriptionId(generator);
//   auto const dead_letter_topic_id = "dead-letter-" + RandomTopicId(generator);

//   auto const snapshot_id = RandomSnapshotId(generator);

//   using ::google::cloud::StatusCode;
//   auto ignore_emulator_failures =
//       [](auto lambda, StatusCode code = StatusCode::kUnimplemented) {
//         try {
//           lambda();
//         } catch (google::cloud::Status const& s) {
//           if (UsingEmulator() && s.code() == code) return;
//           throw;
//         } catch (...) {
//           throw;
//         }
//       };

//   google::cloud::pubsub_admin::TopicAdminClient topic_admin_client(
//       google::cloud::pubsub::MakeTopicAdminConnection());
//   google::cloud::pubsub::SubscriptionAdminClient subscription_admin_client(
//       google::cloud::pubsub::MakeSubscriptionAdminConnection());

//   std::cout << "\nRunning CreateTopic() sample [1]" << std::endl;
//   CreateTopic(topic_admin_client, {project_id, topic_id});

//   std::cout << "\nRunning CreateTopic() sample [2]" << std::endl;
//   CreateTopic(topic_admin_client, {project_id, topic_id});

//   std::cout << "\nRunning CreateTopic() sample [3]" << std::endl;
//   CreateTopic(topic_admin_client, {project_id, ordering_topic_id});

//   std::cout << "\nRunning GetTopic() sample" << std::endl;
//   GetTopic(topic_admin_client, {project_id, topic_id});

//   std::cout << "\nRunning UpdateTopic() sample" << std::endl;
//   ignore_emulator_failures(
//       [&] {
//         UpdateTopic(topic_admin_client, {project_id, topic_id});
//       },
//       StatusCode::kInvalidArgument);

//   std::cout << "\nRunning the StatusOr example" << std::endl;
//   ExampleStatusOr(topic_admin_client, {project_id});

//   std::cout << "\nRunning ListTopics() sample" << std::endl;
//   ListTopics(topic_admin_client, {project_id});

//   std::cout << "\nRunning ListTopicSubscriptions() sample" << std::endl;
//   ListTopicSubscriptions(topic_admin_client, {project_id, topic_id});

//   std::cout << "\nRunning ListTopicSnapshots() sample" << std::endl;
//   ListTopicSnapshots(topic_admin_client, {project_id, topic_id});

//   ignore_emulator_failures([&] {
//     AutoRunAvro(project_id, testdata_directory, generator, topic_admin_client,
//                 subscription_admin_client);
//   });
//   ignore_emulator_failures([&] {
//     AutoRunProtobuf(project_id, testdata_directory, generator,
//                     topic_admin_client, subscription_admin_client);
//   });

//   auto topic = google::cloud::pubsub::Topic(project_id, topic_id);

//   std::cout << "\nRunning DeleteTopic() sample [1]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, dead_letter_topic_id});

//   std::cout << "\nRunning DeleteTopic() sample [2]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, ordering_topic_id});

//   std::cout << "\nRunning DeleteTopic() sample [3]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, topic_id});

//   std::cout << "\nRunning DeleteTopic() sample [4]" << std::endl;
//   DeleteTopic(topic_admin_client, {project_id, topic_id});

  std::cout << "\nAutoRun done" << std::endl;
}

}  // namespace

int main(int argc, char* argv[]) {  // NOLINT(bugprone-exception-escape)
  using ::google::cloud::pubsub::examples::CreateTopicAdminCommand;
  using ::google::cloud::testing_util::Example;

  Example example({
      CreateTopicAdminCommand("create-topic", {"project-id", "topic-id"},
                              CreateTopic),
    //   CreateTopicAdminCommand("get-topic", {"project-id", "topic-id"},
    //                           GetTopic),
    //   CreateTopicAdminCommand("update-topic", {"project-id", "topic-id"},
    //                           UpdateTopic),
    //   CreateTopicAdminCommand("list-topics", {"project-id"}, ListTopics),
    //   CreateTopicAdminCommand("delete-topic", {"project-id", "topic-id"},
    //                           DeleteTopic),
    //   CreateTopicAdminCommand("detach-subscription",
    //                           {"project-id", "subscription-id"},
    //                           DetachSubscription),
    //   CreateTopicAdminCommand("list-topic-subscriptions",
    //                           {"project-id", "topic-id"},
    //                           ListTopicSubscriptions),
    //   CreateTopicAdminCommand("list-topic-snapshots",
    //                           {"project-id", "topic-id"}, ListTopicSnapshots),
    //   CreateTopicAdminCommand(
    //       "create-topic-with-schema",
    //       {"project-id", "topic-id", "schema-id", "encoding"},
    //       CreateTopicWithSchema),
    //   CreateTopicAdminCommand(
    //       "create-topic-with-schema-revisions",
    //       {"project-id", "topic-id", "schema-id", "encoding",
    //        "first-revision-id", "last-revision-id"},
    //       CreateTopicWithSchemaRevisions),
    //   CreateTopicAdminCommand(
    //       "update-topic-schema",
    //       {"project-id", "topic-id", "first-revision-id", "last-revision-id"},
    //       UpdateTopicSchema),
      {"auto", AutoRun},
  });
  return example.Run(argc, argv);
}
