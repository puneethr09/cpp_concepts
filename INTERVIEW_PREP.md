# C++ Interview Interactive Checklist

Use this file to track your progress. Mark an `[x]` when you feel confident explaining the concept *without* looking at notes.

## 1. Core Language (Mechanics)
- [ ] **Smart Pointers**
    - [ ] Explain `unique_ptr` vs `shared_ptr` (Ownership models).
    - [ ] Explain why `unique_ptr` cannot be copied (deleted copy constructor).
    - [ ] Explain "Reference Counting" in `shared_ptr` (Control Block).
    - [ ] Explain "Circular Dependency" and how `weak_ptr` solves it.
- [ ] **Memory Management**
    - [ ] Explain Stack vs Heap memory.
    - [ ] Explain RAII (Resource Acquisition Is Initialization).
    - [ ] Explain Move Semantics (`std::move`, rvalue references).
- [ ] **Data Structures (STL)**
    - [ ] Explain `std::vector` resizing logic (Capacity vs Size, Geometric Growth).
    - [ ] Explain `std::map` vs `std::unordered_map` (Tree vs Hash Table).
    - [ ] Explain Iterator validation (and invalidation rules).

## 2. Concurrency (Multithreading)
- [ ] **Basics**
    - [ ] Explain `std::thread` and why `join()` is mandatory.
    - [ ] Explain Race Conditions (Why `count++` is not atomic).
- [ ] **Synchronization**
    - [ ] Explain `std::mutex` and `std::lock_guard`.
    - [ ] Explain Deadlocks (Circular wait) and how to avoid them (Lock Ordering).
- [x] **Advanced (Implemented in Repo)**
    - [x] **Thread Pool**: Explain `std::condition_variable` and the "Worker Loop".
    - [ ] **Future/Promise**: (Bonus) How to return a value from a thread?

## 3. Design Patterns
- [ ] **Creational**
    - [ ] **Singleton**: Thread-safe initialization.
    - [ ] **Factory**: Comparison with simple constructor.
    - [ ] **Builder**: Comparison with telescoping constructors.
    - [ ] **Abstract Factory**: Family consistency.
    - [ ] **Prototype**: Cloning vs Instantiation.
- [ ] **Structural**
    - [ ] **Adapter**: Interface incompatibility.
    - [ ] **Decorator**: Runtime behavior extension (Composition > Inheritance).
- [ ] **Behavioral**
    - [ ] **Observer**: Push vs Pull notifications.
    - [ ] **Strategy**: Algorithms as objects.

## 4. System Design (The "Senior" Signal)
- [x] **LRU Cache**: Explain the combination of Doubly Linked List + HashMap.
- [x] **Thread Pool**: Explain how to protect a queue with a mutex for a Producer-Consumer problem.

## 5. Mock Interview Strategy
1.  **Opening**: "I have a repo where I've implemented a modern C++20 standard library from scratch using Bazel and GoogleTest." (This sets a high bar).
2.  **Coding Round**: Start by writing a test case first (TDD). "Before I implement the logic, let me define the expected behavior."
3.  **Design Round**: Use the Pattern vocab. "I'll use a Factory here to decouple the creation logic..."

---
*Last Updated: 2026-01-09*
