# C++ Dictionary & Keyword Reference

A quick-lookup glossary for keywords, types, and tricky concepts.

---

## A
*   **`alignas(T)`**: Specifies the storage alignment (e.g., `alignas(16) char buffer[16]`). Used for SIMD or Cache Line optimization.
*   **`alignof(T)`**: Returns the alignment requirements of type T.
*   **`auto`**: Tells compiler to deduce type (C++11). `auto x = 5;`. Always strips refs/const unless you use `auto&` or `const auto&`.
*   **`atomic`**: `std::atomic<T>`. Prevents data races without mutexes for simple types. Ensures memory ordering.

## B
*   **Bitwise Operators**: `&` (AND), `|` (OR), `^` (XOR), `~` (NOT), `<<` (L-Shift), `>>` (R-Shift).
*   **Bitset**: `std::bitset`. Space-efficient array of bits.

## C
*   **`class`**: Default access is `private`.
*   **`const`**: "I promise strictly not to change this."
*   **`constexpr`**: "I promise this can be calculated at compile-time."
*   **`const_cast`**: The only cast that can remove `const`. Dangerous.
*   **Copy Constructor**: `Class(const Class& other)`. Called when creating a new object from an existing one.
*   **Copy Assignment**: `operator=(const Class& other)`. Called when updating an existing object.

## D
*   **`decltype(expr)`**: Inspects the declared type of an expression.
*   **Deep Copy**: Copying the *data* a pointer points to, not just the pointer address.
*   **Default Argument**: `void func(int x = 5)`. Must be at the end of parameter list.
*   **Destructor**: `~Class()`. Cleans up resources. **Always make it `virtual` in a base class!**
*   **Delete**: `delete ptr`. Frees heap memory. `delete[] ptr` for arrays.
*   **`dynamic_cast`**: Safe downcasting in inheritance hierarchy. Returns `nullptr` if cast fails. Slow (RTTI).

## E
*   **`explicit`**: Prevents implicit conversion in single-argument constructors. `explicit Foo(int x);`.
*   **`enum class`**: Strongly typed enum. `Color::RED` != `Fruit::APPLE`.
*   **`extern`**: "This variable is defined in another .cpp file."

## F
*   **`friend`**: A class/function allowed to touch your `private` parts.
*   **`final`**: Prevents inheritance (`class A final`) or overriding (`void func() final`).

## I
*   **`inline`**: Hint to compiler to copy-paste function body to call site. Also allows definition in header files without "multiple definition" errors.
*   **Implicit Conversion**: Automatic type change. `float f = 5;` (int -> float).

## O
*   **`std::optional`** (C++17): Wrapper that may or may not contain a value. Prevents null pointer crashes/magic return values.


## L
*   **Lambda**: `[capture](params){ body }`. Anonymous function.
    *   `[=]`: Capture all by value.
    *   `[&]`: Capture all by reference.
*   **L-Value**: "Locator Value". Has an address. `int x = 5;` -> `x` is L-Value.

## M
*   **Move Semantics**: Stealing resources from a temporary object instead of copying. `std::vector` resizing uses this.
*   **`mutable`**: Allows a member variable to be changed inside a `const` function. Useful for mutexes or counters.
*   **`malloc/free`**: C-style memory. Don't use in C++. Use `new/delete`.

## N
*   **Namespace**: Wraps code to avoid name collisions. `namespace MyLib { ... }`.
*   **`noexcept`**: "I promise I wont throw." If I do, terminate program immediately. Helps compiler optimize.
*   **`nullptr`**: The null pointer literal. `NULL` is just `0` (int), `nullptr` is type-safe.

## O
*   **Operator Overloading**: Giving new meaning to `+`, `-`, `==` for custom classes.
*   **Override**: `void func() override`. Ensures you are actually overriding a virtual method, not making a typo.

## P
*   **Polymorphism**: Treating derived objects as base objects. requires `virtual` functions.
*   **Placement New**: `new (address) Type()`. Constructs object at specific pre-allocated memory address.
*   **Private**: Only this class can access.

## R
*   **RAII**: Resource Acquisition Is Initialization. Constructor acquires, Destructor releases.
*   **Reference (`&`)**: An alias. Must be initialized. Cannot be null. Cannot be reseated.
*   **`reinterpret_cast`**: "Trust me." Reinterprets bits (e.g., int* to char*).
*   **R-Value**: Temporary value. `5`, `x + y`, `func()`.

## S
*   **`static`**:
    *   In Class: Shared by everyone.
    *   In Function: Remembers value between calls.
    *   Global: Visible only to this file (Internal Linkage).
*   **`static_cast`**: Standard compile-time cast.
*   **`struct`**: Default access is `public`. Otherwise same as class.
*   **Smart Pointers**: `unique_ptr`, `shared_ptr`, `weak_ptr`.
*   **Structured Binding** (C++17): Unpacking objects. `auto [x, y] = point;`.


## T
*   **Template**: `template <typename T>`. Generics. Code generation at compile time.
*   **Translation Unit**: A single source file + all included headers.
*   **`this`**: Pointer to the current object.
*   **`thread_local`**: Each thread gets its own copy of this variable.

## U
*   **Undefined Behavior (UB)**: "Demons fly out of your nose." Accessing deleted memory, divide by zero, signed overflow.
*   **`using`**: Type alias. `using Count = int;`. Better than `typedef`.
*   **`union`**: Stores different types in same memory location. Only one active at a time.

## V
*   **`virtual`**: Enables runtime polymorphism (Dynamic Dispatch). Adds a vptr/vtable to the object.
*   **`std::variant`** (C++17): Type-safe Union. Can hold one of several types. `std::variant<int, float>`.
*   **`void*`**: Pointer to "anything". No type safety.

*   **`volatile`**: Tells compiler "Hardware might change this, do not optimize reads".

## W
*   **`weak_ptr`**: Non-owning reference to `shared_ptr`. Breaks circular dependencies.
