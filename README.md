# C++ Interview Prep Framework

This repository is a comprehensive **Interview Preparation Framework** designed effectively to clear Senior C++ Engineer interviews. It is structured to mirror a professional Big Tech codebase (Google/Meta style).

## 📚 Core Resources

1.  **[CONCEPT_GUIDE.md](CONCEPT_GUIDE.md)**: The "Textbook". A comprehensive theoretical guide covering:
    *   **Core Concepts**: Smart Pointers, Memory Management, STL Internals.
    *   **Concurrency**: Threading models, Mutexes, Deadlocks.
    *   **Design Patterns**: 9 implemented patterns (Singleton, Factory, Observer, etc.) + System Design (LRU Cache, Thread Pool).

2.  **[CPP_DICTIONARY.md](CPP_DICTIONARY.md)**: The "Encyclopedia".
    *   An alphabetical glossary of keywords (`volatile`, `mutable`, `explicit`).
    *   Deep dives into Mechanics (`RAII`, `SFINAE`, `Undefined Behavior`).
    *   **Dual Explanation Format**: Every term has a "Technical Definition" and an "ELI5" (Explain Like I'm 5) analogy.

3.  **[INTERVIEW_PREP.md](INTERVIEW_PREP.md)**: The "Tracker".
    *   An interactive checklist to track your progress.
    *   Mark items as done only when you can explain them without looking at notes.

---

## 🛠 Project Structure

*   **`include/`**: The public API.
    *   `cpp_vocabulary.hpp`: Compilable cheatsheet of keywords and Modern C++ features.
    *   `systemDesign/`: Fully functioning **LRU Cache** and **Thread Pool**.
    *   `behavioralPatterns/`, `structuralPatterns/`, `creationalPatterns/`.
    *   `stl.hpp`, `pointers.hpp`: Hand-written implementations of standard library features (for deep understanding).
*   **`tests/`**: Comprehensive **GoogleTest** suite.
    *   Verifies every single concept in the repo.
    *   Use these tests to understand the *expected behavior* of code.
*   **`BUILD`**: Bazel build configuration (Modern Standard).

---

## 🚀 How to Use

### 1. Build Everything
We use **Bazel** and **C++20**.
```sh
# Build all targets
bazel build //...
```

### 2. Run Tests (Verify Your Knowledge)
Run all 6 test suites to confirm the code works as expected.
```sh
bazel test //...
```
*   `system_design_test`: Verifies LRU Cache & Thread Pool.
*   `vocabulary_test`: Verifies language keywords.
*   `patterns_test`: Verifies Design Patterns.

### 3. Study Flow
1.  Read a section in **[CONCEPT_GUIDE.md](CONCEPT_GUIDE.md)** (e.g., Smart Pointers).
2.  Read the corresponding code in `include/pointers.hpp`.
3.  Run the test `bazel test //tests:smart_pointers_test`.
4.  Mark it as Done in **[INTERVIEW_PREP.md](INTERVIEW_PREP.md)**.
5.  Use **[CPP_DICTIONARY.md](CPP_DICTIONARY.md)** to look up any confusing terms you encounter.

---
**Good Luck!**
