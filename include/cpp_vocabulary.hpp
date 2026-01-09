#ifndef CPP_VOCABULARY_HPP
#define CPP_VOCABULARY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <utility> // std::move
#include <limits>  // std::numeric_limits

// --- 1. Keywords & Storage Classes ---

// 'static': 
// - Inside class: Shared by all instances.
// - Inside function: Persists between calls.
// - Global scope: Local to translation unit (file).
class StaticDemo {
public:
    inline static int sharedCount = 0; // 'inline' allows init here (C++17)
    static void increment() { sharedCount++; }
};

// 'const': Value cannot change.
const int MAX_VAL = 100;

// 'constexpr': Evaluated at Compile Time (Performance boost).
constexpr int square(int x) { return x * x; }

// 'mutable': Allows modification even inside a 'const' method.
struct Monitor {
    mutable int accessCount = 0; 
    void check() const { // Method is const (doesn't change logic state)
        accessCount++;   // But we can change this logging var thanks to 'mutable'
    }
};

// 'explicit': Prevents accidental implicit conversions.
class Wrapper {
public:
    explicit Wrapper(int x) {} // Cannot do: Wrapper w = 10; Must do: Wrapper w(10);
};

// 'friend': Gives another class access to private members.
class SecretBox {
private:
    int code = 1234;
    friend class Hacker; // Hacker can see 'code'
};

class Hacker {
public:
    int steal(const SecretBox& box) { return box.code; }
};

// --- 2. Type System & Casts ---

// 'auto': Type deduction.
auto myNum = 10; // deduced as int

// 'decltype': Get type of an expression.
using NumType = decltype(myNum); // NumType is int

// 'enum class': Scoped enum (Safe). OLD: 'enum Color { RED }' pollutes scope.
enum class Color { RED, GREEN, BLUE };

// C-Style Casting: (int)x -> DANGEROUS.
// C++ Casts:
// 1. static_cast: Compile-time check (e.g., int to float). Safe basics.
// 2. dynamic_cast: Runtime check (Polymorphism). Requires vtable.
// 3. const_cast: Removes 'const'. Evil but sometimes needed for legacy APIs.
// 4. reinterpret_cast: Treat bits as something else. "Trust me bro".

void castingDemo() {
    double pi = 3.14;
    int i = static_cast<int>(pi); 
    (void)i; // Suppress unused warning
    
    const int readOnly = 10;
    int* modifiable = const_cast<int*>(&readOnly); 
    
    long address = reinterpret_cast<long>(modifiable); 
    (void)address; // Suppress unused warning
}

// --- 3. Minute Concepts ---

// L-Value vs R-Value
// L-Value: Has a name, addressable (e.g., int x).
// R-Value: Temporary, short-lived (e.g., 10, x + y).

void moveSemantics() {
    std::string s1 = "Hello";
    std::string s2 = std::move(s1); 
    // s1 is now empty. s2 owns the string.
}

// Volatile: "Don't optimize me". Compiler normally caches reads.
volatile int sensorValue; 

// Inline: Hint to insert function body at call site.
inline void fastFunc() {}

// --- 4. Modern C++ (C++17/20) ---

#include <optional>
#include <variant>
#include <any>

// std::optional: May or may not have a value. No more 'return -1' for errors.
std::optional<int> divide(int a, int b) {
    if (b == 0) return std::nullopt;
    return a / b;
}

// std::variant: Type-safe Union. Can be Int OR Float.
using Number = std::variant<int, float>;

// std::any: Type-safe void*. Can hold anything.
std::any arbitrary = 10;

// Structured Binding (C++17):
struct Point { int x, y; };
void bindingDemo() {
    Point p{1, 2};
    auto [x, y] = p; // x=1, y=2. Clean unpacking.
    (void)x; (void)y;
}


#endif // CPP_VOCABULARY_HPP
