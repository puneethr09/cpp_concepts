package(default_visibility = ["//visibility:public"])

cc_library(
    name = "mylib",
    srcs = glob(["src/*.cpp"], exclude = ["src/main.cpp"]),
    hdrs = glob(["include/**/*.hpp"]),
    strip_include_prefix = "include",
    copts = [
        "-Wall",
        "-Wextra",
        "-std=c++20",
    ],
)

cc_binary(
    name = "cpp_concepts",
    srcs = ["src/main.cpp"],
    deps = [":mylib"],
    copts = ["-std=c++20"],
    linkopts = [
        "-lpthread",
    ],
)