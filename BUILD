# filepath: /Users/puneeth/Documents/repo/repo_cpp_practice/BUILD
cc_library(
    name = "mylib",
    srcs = [
        "src/log.cpp",
        "src/multithread.cpp",
    ],
    hdrs = glob(["include/*.hpp"]),
    copts = [
        "-Wall",
        "-std=c++14",
        "-I.",  # Now the include folder (./include) is accessible.
    ],
)

cc_binary(
    name = "output",
    srcs = ["src/main.cpp"],
    deps = [":mylib"],
    linkopts = [
        "-lpthread",
    ],
)