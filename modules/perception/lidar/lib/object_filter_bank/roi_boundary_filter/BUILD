load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "roi_boundary_filter",
    srcs = ["roi_boundary_filter.cc"],
    hdrs = ["roi_boundary_filter.h"],
    deps = [
        "//cyber",
        "//modules/perception/base:point_cloud",
        "//modules/perception/common/geometry:common",
        "//modules/perception/lib/config_manager",
        "//modules/perception/lidar/lib/interface:base_object_filter",
        "//modules/perception/pipeline:plugin",
        "//modules/perception/pipeline/proto/plugin:roi_boundary_filter_config_cc_proto",
        "@com_google_googletest//:gtest",
        "@eigen",
    ],
    alwayslink = True,
)

cc_test(
    name = "roi_boundary_filter_test",
    size = "small",
    srcs = ["roi_boundary_filter_test.cc"],
    deps = [
        ":roi_boundary_filter",
        "//modules/perception/common:perception_gflags",
        "@com_google_googletest//:gtest_main",
    ],
)

cpplint()
