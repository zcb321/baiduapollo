load("//tools/install:install.bzl", "install", "install_files", "install_src_files")

package(
    default_visibility = ["//visibility:public"],
)

install(
    name = "install",
    data_dest = "3rd-openh264",
    data = [
        ":cyberfile.xml",
        ":3rd-openh264.BUILD",
    ],
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "3rd-openh264/src",
    filter = "*",
)
