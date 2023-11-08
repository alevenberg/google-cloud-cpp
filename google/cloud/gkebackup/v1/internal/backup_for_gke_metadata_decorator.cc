// Copyright 2023 Google LLC
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
// source: google/cloud/gkebackup/v1/gkebackup.proto

#include "google/cloud/gkebackup/v1/internal/backup_for_gke_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/internal/url_encode.h"
#include "google/cloud/status_or.h"
#include <google/cloud/gkebackup/v1/gkebackup.grpc.pb.h>
#include <memory>
#include <utility>

namespace google {
namespace cloud {
namespace gkebackup_v1_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BackupForGKEMetadata::BackupForGKEMetadata(
    std::shared_ptr<BackupForGKEStub> child,
    std::multimap<std::string, std::string> fixed_metadata,
    std::string api_client_header)
    : child_(std::move(child)),
      fixed_metadata_(std::move(fixed_metadata)),
      api_client_header_(
          api_client_header.empty()
              ? google::cloud::internal::GeneratedLibClientHeader()
              : std::move(api_client_header)) {}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncCreateBackupPlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::CreateBackupPlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateBackupPlan(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListBackupPlansResponse>
BackupForGKEMetadata::ListBackupPlans(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListBackupPlansRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListBackupPlans(context, request);
}

StatusOr<google::cloud::gkebackup::v1::BackupPlan>
BackupForGKEMetadata::GetBackupPlan(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetBackupPlanRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetBackupPlan(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncUpdateBackupPlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::UpdateBackupPlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("backup_plan.name=",
                           internal::UrlEncode(request.backup_plan().name())));
  return child_->AsyncUpdateBackupPlan(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncDeleteBackupPlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::DeleteBackupPlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteBackupPlan(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::CreateBackupRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateBackup(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListBackupsResponse>
BackupForGKEMetadata::ListBackups(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListBackupsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListBackups(context, request);
}

StatusOr<google::cloud::gkebackup::v1::Backup> BackupForGKEMetadata::GetBackup(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetBackupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetBackup(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncUpdateBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::UpdateBackupRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("backup.name=",
                           internal::UrlEncode(request.backup().name())));
  return child_->AsyncUpdateBackup(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncDeleteBackup(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::DeleteBackupRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteBackup(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListVolumeBackupsResponse>
BackupForGKEMetadata::ListVolumeBackups(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListVolumeBackupsRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListVolumeBackups(context, request);
}

StatusOr<google::cloud::gkebackup::v1::VolumeBackup>
BackupForGKEMetadata::GetVolumeBackup(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetVolumeBackupRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetVolumeBackup(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncCreateRestorePlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::CreateRestorePlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateRestorePlan(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListRestorePlansResponse>
BackupForGKEMetadata::ListRestorePlans(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListRestorePlansRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListRestorePlans(context, request);
}

StatusOr<google::cloud::gkebackup::v1::RestorePlan>
BackupForGKEMetadata::GetRestorePlan(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetRestorePlanRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetRestorePlan(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncUpdateRestorePlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::UpdateRestorePlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("restore_plan.name=",
                           internal::UrlEncode(request.restore_plan().name())));
  return child_->AsyncUpdateRestorePlan(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncDeleteRestorePlan(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::DeleteRestorePlanRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteRestorePlan(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncCreateRestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::CreateRestoreRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->AsyncCreateRestore(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListRestoresResponse>
BackupForGKEMetadata::ListRestores(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListRestoresRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListRestores(context, request);
}

StatusOr<google::cloud::gkebackup::v1::Restore>
BackupForGKEMetadata::GetRestore(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetRestoreRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetRestore(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncUpdateRestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::UpdateRestoreRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("restore.name=",
                           internal::UrlEncode(request.restore().name())));
  return child_->AsyncUpdateRestore(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncDeleteRestore(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::cloud::gkebackup::v1::DeleteRestoreRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncDeleteRestore(cq, std::move(context), request);
}

StatusOr<google::cloud::gkebackup::v1::ListVolumeRestoresResponse>
BackupForGKEMetadata::ListVolumeRestores(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::ListVolumeRestoresRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("parent=", internal::UrlEncode(request.parent())));
  return child_->ListVolumeRestores(context, request);
}

StatusOr<google::cloud::gkebackup::v1::VolumeRestore>
BackupForGKEMetadata::GetVolumeRestore(
    grpc::ClientContext& context,
    google::cloud::gkebackup::v1::GetVolumeRestoreRequest const& request) {
  SetMetadata(context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->GetVolumeRestore(context, request);
}

future<StatusOr<google::longrunning::Operation>>
BackupForGKEMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> BackupForGKEMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::shared_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, internal::CurrentOptions(),
              absl::StrCat("name=", internal::UrlEncode(request.name())));
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void BackupForGKEMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options,
                                       std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context, options);
}

void BackupForGKEMetadata::SetMetadata(grpc::ClientContext& context,
                                       Options const& options) {
  for (auto const& kv : fixed_metadata_) {
    context.AddMetadata(kv.first, kv.second);
  }
  context.AddMetadata("x-goog-api-client", api_client_header_);
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gkebackup_v1_internal
}  // namespace cloud
}  // namespace google
