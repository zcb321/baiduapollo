## Auto generated by `proto_build_generator.py`
load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")
load("//tools:python_rules.bzl", "py_proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "story_cc_proto",
    deps = [
        ":story_proto",
    ],
)

proto_library(
    name = "story_proto",
    srcs = ["story.proto"],
    deps = [
        "//modules/common_msgs/basic_msgs:header_proto",
    ],
)

py_proto_library(
    name = "story_py_pb2",
    deps = [
        ":story_proto",
        "//modules/common_msgs/basic_msgs:header_py_pb2",
    ],
)

