# ~~~
# Copyright 2023 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

include(GoogleCloudCppLibrary)

set(GOOGLE_CLOUD_CPP_SERVICE_DIRS "v1/")

external_googleapis_add_library(
  "google/apps/script/type/calendar/calendar_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_calendar_calendar_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/docs/docs_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_docs_docs_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/drive/drive_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_drive_drive_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/gmail/gmail_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_gmail_gmail_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/sheets/sheets_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_sheets_sheets_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/slides/slides_addon_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("google_cloud_cpp_apps_script_type_slides_slides_addon_manifest_protos")

external_googleapis_add_library(
  "google/apps/script/type/script_manifest.proto" api_field_behavior_protos)
external_googleapis_install_pc("apps_script_type_type_protos")
# message(STATUS $(BUILDSYSTEM_TARGETS))

# target_link_libraries(google-cloud-cpp::gsuiteaddons_protos PRIVATE google_cloud_cpp_apps_script_type_slides_slides_addon_manifest_protos)
google_cloud_cpp_add_ga_grpc_library(gsuiteaddons
                                     "Google Workspace Add-ons API"
                                     ADDITIONAL_PROTO_LISTS
                                     "${EXTERNAL_GOOGLEAPIS_SOURCE}/google/apps/script/type/calendar/calendar_addon_manifest.proto"
                                     "${EXTERNAL_GOOGLEAPIS_SOURCE}/google/apps/script/type/script_manifest.proto"
                                     CROSS_LIB_DEPS
                                     "apps_script_type_type_protos"
                                     "apps_script_type_slides_slides_addon_manifest_protos")

if (BUILD_TESTING AND GOOGLE_CLOUD_CPP_ENABLE_CXX_EXCEPTIONS)
    add_executable(gsuiteaddons_quickstart "quickstart/quickstart.cc")
    target_link_libraries(gsuiteaddons_quickstart
                          PRIVATE google-cloud-cpp::gsuiteaddons)
    google_cloud_cpp_add_common_options(gsuiteaddons_quickstart)
    add_test(
        NAME gsuiteaddons_quickstart
        COMMAND
            cmake -P "${PROJECT_SOURCE_DIR}/cmake/quickstart-runner.cmake"
            $<TARGET_FILE:gsuiteaddons_quickstart> GOOGLE_CLOUD_PROJECT
            cloud-cpp-testing-resources)
    set_tests_properties(gsuiteaddons_quickstart
                         PROPERTIES LABELS "integration-test;quickstart")
endif ()
