# CPP Concepts

This project demonstrates various C++ concepts including:

- Pointer manipulation (including smart pointers)
- STL containers (vectors, maps, sets, lists)
- Custom logging utilities
- Multi-threading examples
- Design patterns (e.g., Singleton implementation)

## Project Structure

- **main.cpp**: The main driver file showcasing examples and using various utility functions.
- **include/**: Contains header files such as:
  - `log.hpp`: Logging utilities.
  - `pointers.hpp`: Custom unique pointer implementation.
  - `stl.hpp`: STL-based functionalities.
  - `multithread.hpp`: Multi-threading examples.
- **log.cpp**: Implementation of logging functionalities.
- **multithread.cpp**: Examples and implementation of multi-threading.
- **makefile**: Build instructions using Make.
- **BUILD**: Bazel build configuration for the project.
- **WORKSPACE**: Empty file marking the root of the Bazel workspace.

## Requirements

- A C++14 compliant compiler (e.g., g++ or clang++).
- Make build system (for Makefile-based builds).
- [Bazel](https://bazel.build/) (if you prefer a Bazel-based build).

## Building the Project

### Using Makefile

Open your terminal, navigate to the project directory, and run:

```sh
make
```
### Using Bazel

Ensure that Bazel is installed on your system (for example, via Homebrew on macOS):
```sh
brew install bazel
```

Navigate to the project directory (which contains the WORKSPACE and BUILD files).
Build the project with:
```sh
bazel build //:output
```
Running the Project
```sh
bazel run //:output
```

## How Bazel Builds the Project
When you run `bazel build //:output` Bazel does the following:

- ***Workspace Initialization:***
Bazel reads the WORKSPACE file to treat the current directory as a Bazel workspace.

- ***Target Analysis:***
It parses the BUILD file, creates a dependency graph, and identifies that the output binary target depends on the mylib library.

- ***Sandboxed Build Actions:***
Bazel creates an isolated sandbox environment where it compiles source files using the specified compiler options (e.g., -Wall, -std=c++14, -I.).

#### Compilation and Linking:

- `log.cpp` and `multithread.cpp` are compiled as part of the `mylib cc_library` target.
- `main.cpp` is compiled as part of the output `cc_binary` target.
- Bazel links these object files together using the `-lpthread` flag as specified in the `BUILD` file.

##### Incremental Builds:
Bazel only rebuilds parts of the project that have changed, making subsequent builds faster.

- Running the Binary:
When you run `bazel run //:output`, Bazel ensures that the targets are up-to-date then executes the built binary.

## License
This project is provided as-is without any warranty. Use and modify it according to your needs.

