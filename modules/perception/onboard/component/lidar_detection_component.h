/******************************************************************************
 * Copyright 2020 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <atomic>
#include <memory>
#include <string>
#include <limits>

#include "cyber/cyber.h"
#include "modules/perception/lidar/app/lidar_obstacle_detection.h"
#include "modules/perception/lidar/common/lidar_frame.h"
#include "modules/perception/onboard/inner_component_messages/lidar_inner_component_messages.h"
#include "modules/perception/onboard/transform_wrapper/transform_wrapper.h"

#include "modules/common_msgs/sensor_msgs/pointcloud.pb.h"
#include "modules/perception/onboard/proto/lidar_component_config.pb.h"

namespace apollo {
namespace perception {
namespace onboard {

class LidarDetectionComponent : public cyber::Component<drivers::PointCloud> {
 public:
  using PipelineConfig = pipeline::PipelineConfig;

 public:
  LidarDetectionComponent() = default;
  virtual ~LidarDetectionComponent() = default;

  bool Init() override;
  bool Proc(const std::shared_ptr<drivers::PointCloud>& message) override;

 private:
  bool InitAlgorithmPlugin();
  bool InternalProc(
      const std::shared_ptr<const drivers::PointCloud>& in_message,
      const std::shared_ptr<LidarFrameMessage>& out_message);

  bool ConvertCloud(
      const std::shared_ptr<const drivers::PointCloud>& from,
      std::shared_ptr<base::AttributePointCloud<base::PointF>> to);

 private:
  static std::atomic<uint32_t> seq_num_;
  std::string sensor_name_;
  std::string detector_name_;
  bool enable_hdmap_ = true;
  float lidar_query_tf_offset_ = 20.0f;
  std::string lidar2novatel_tf2_child_frame_id_;
  std::string output_channel_name_;
  base::SensorInfo sensor_info_;
  TransformWrapper lidar2world_trans_;
  // std::unique_ptr<lidar::BaseLidarObstacleDetection> detector_;

  std::unique_ptr<lidar::BaseLidarObstacleDetection> lidar_detection_pipeline_;

  pipeline::PipelineConfig lidar_detection_config_;

  std::shared_ptr<apollo::cyber::Writer<LidarFrameMessage>> writer_;
};

CYBER_REGISTER_COMPONENT(LidarDetectionComponent);

}  // namespace onboard
}  // namespace perception
}  // namespace apollo
