# C++ Resume Upgrade Kit

Based on the `cpp_concepts` repository you built, you can now confidently add the following sections to your resume.

## 1. New Keywords (Add to "Skills" Section)
*   **Languages**: C++17, C++20 (Concepts, Coroutines, Modules)
*   **Build Tools**: Bazel (Starlark), Make
*   **Testing**: GoogleTest (gtest), TDD (Test Driven Development)
*   **Concepts**: RAII, Multithreading (Mutex, Condition Variables), Smart Pointers, STL Internals.
*   **System Design**: LRU Cache, Thread Pool, Design Patterns (Observer, Strategy, Factory).

## 2. New Project Entry (Add to "Projects")

**Modern C++ Verification Framework (Github Link)**
*   Designed and implemented a Google-style C++20 monorepo using **Bazel** and **GoogleTest**.
*   Engineered a custom **Thread Pool** handling concurrent task execution with `std::condition_variable` and RAII-compliant shutdown.
*   Implemented an O(1) **LRU Cache** using `std::list` and `std::unordered_map` to simulate high-performance memory management.
*   Demonstrated mastery of **9 Design Patterns** (including Observer, Strategy, Abstract Factory) via comprehensive unit tests.
*   Created a custom `std::shared_ptr` and `std::vector` implementation from scratch to verify deep understanding of memory ownership and dynamic allocation.

## 3. Interview Talking Points
*   "I didn't just read about these concepts; I built a testing framework to verify them."
*   "I use Bazel because it ensures hermetic builds and scalable dependency management, similar to how Google manages code."
*   "I understand the cost of creating threads, which is why I implemented a Thread Pool to reuse workers."
