load("@rules_cc//cc:defs.bzl", "cc_library")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "interface",
    deps = [
        ":base_bipartite_graph_matcher",
        ":base_classifier",
        ":base_ground_detector",
        ":base_multi_target_tracker",
        ":base_roi_filter",
        ":base_lidar_detector",
        ":base_pointcloud_preprocessor",
    ],
)

cc_library(
    name = "base_bipartite_graph_matcher",
    hdrs = ["base_bipartite_graph_matcher.h"],
    deps = [
        "//modules/perception/common/graph:secure_matrix",
        "//modules/perception/lib/registerer",
        "@eigen",
    ],
)

cc_library(
    name = "base_lidar_detector",
    hdrs = ["base_lidar_detector.h"],
    deps = [
        "//cyber",
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cc_library(
    name = "base_lidar_obstacle_detection",
    hdrs = ["base_lidar_obstacle_detection.h"],
    deps = [
        "//cyber",
        "//modules/common_msgs/sensor_msgs:pointcloud_cc_proto",
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_error_code",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline",
        "@eigen",
    ],
)

cc_library(
    name = "base_lidar_obstacle_tracking",
    hdrs = ["base_lidar_obstacle_tracking.h"],
    deps = [
        "//cyber",
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_error_code",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline",
    ],
)

cc_library(
    name = "base_pointcloud_preprocessor",
    hdrs = ["base_pointcloud_preprocessor.h"],
    deps = [
        "//cyber",
        "//modules/common_msgs/sensor_msgs:pointcloud_cc_proto",
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cc_library(
    name = "base_classifier",
    hdrs = ["base_classifier.h"],
    deps = [
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cc_library(
    name = "base_ground_detector",
    hdrs = ["base_ground_detector.h"],
    deps = [
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cc_library(
    name = "base_multi_target_tracker",
    hdrs = ["base_multi_target_tracker.h"],
    deps = [
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cc_library(
    name = "base_object_filter",
    hdrs = ["base_object_filter.h"],
    deps = [
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:plugin",
    ],
)

cc_library(
    name = "base_roi_filter",
    hdrs = ["base_roi_filter.h"],
    deps = [
        "//modules/perception/lib/registerer",
        "//modules/perception/lidar/common:lidar_frame",
        "//modules/perception/pipeline:stage",
    ],
)

cpplint()
