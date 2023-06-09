load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])
PREDICTION_COPTS = ["-DMODULE_NAME=\\\"prediction\\\""]

cc_library(
    name = "obstacles_container",
    srcs = ["obstacles_container.cc"],
    hdrs = ["obstacles_container.h"],
    copts = PREDICTION_COPTS,
    deps = [
        ":obstacle_clusters",
        "//modules/prediction/common:environment_features",
        "//modules/prediction/common:feature_output",
        "//modules/prediction/common:junction_analyzer",
        "//modules/prediction/common:prediction_constants",
        "//modules/prediction/container",
        "//modules/prediction/container/obstacles:obstacle",
        "//modules/common_msgs/prediction_msgs:prediction_obstacle_cc_proto",
        "//modules/prediction/submodules:submodule_output",
    ],
)

cc_library(
    name = "obstacle",
    srcs = ["obstacle.cc"],
    hdrs = ["obstacle.h"],
    copts = PREDICTION_COPTS,
    deps = [
        ":obstacle_clusters",
        "//modules/common/filters",
        "//modules/prediction/common:junction_analyzer",
        "//modules/prediction/common:prediction_constants",
        "//modules/prediction/network/rnn_model",
        "//modules/prediction/proto:prediction_conf_cc_proto",
        "//modules/common_msgs/prediction_msgs:prediction_obstacle_cc_proto",
    ],
)

cc_test(
    name = "obstacles_container_test",
    size = "small",
    srcs = ["obstacles_container_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/container/obstacles:obstacles_container",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "obstacle_test",
    size = "small",
    srcs = ["obstacle_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/container/obstacles:obstacles_container",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_library(
    name = "obstacle_clusters",
    srcs = ["obstacle_clusters.cc"],
    hdrs = ["obstacle_clusters.h"],
    copts = PREDICTION_COPTS,
    deps = [
        "//modules/common/util",
        "//modules/prediction/common:road_graph",
        "//modules/common_msgs/prediction_msgs:feature_cc_proto",
    ],
)

cc_test(
    name = "obstacle_clusters_test",
    size = "small",
    srcs = ["obstacle_clusters_test.cc"],
    data = [
        "//modules/prediction:prediction_data",
        "//modules/prediction:prediction_testdata",
    ],
    deps = [
        "//modules/prediction/common:kml_map_based_test",
        "//modules/prediction/container/obstacles:obstacle_clusters",
        "@com_google_googletest//:gtest_main",
    ],
)

cpplint()
