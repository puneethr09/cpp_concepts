# filepath: /Users/puneeth/Documents/repo/repo_cpp_practice/BUILD
cc_library(
    name = "mylib",
    srcs = [
        "src/log.cpp",
        "src/multithread.cpp",
    ],
    hdrs = glob(["include/*.hpp", "include/**/*.hpp"]),
    includes = ["include"],
    copts = [
        "-Wall",
        "-std=c++14",
    ],
)

cc_binary(
    name = "cpp_concepts",
    srcs = ["src/main.cpp"],
    deps = [":mylib"],
    linkopts = [
        "-lpthread",
    ],
)