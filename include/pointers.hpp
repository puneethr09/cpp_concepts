#pragma once
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class uniquePtr
{
private:
    // The raw heap pointer. This is trapped inside this Stack object.
    // Made private so external code cannot accidentally 'delete' it or alias it.
    T *ptr;

public:
    // Default constructor is deleted to force the user to provide a valid heap pointer upon creation.
    // Note: std::unique_ptr DOES allow default construction (initializing to nullptr), 
    // but deleting it here guarantees we never have an empty wrapper.
    uniquePtr() = delete;

    // Constructor: Takes ownership of the raw heap pointer. 
    // This is where the Stack wrapper securely grabs the Heap payload.
    uniquePtr(T *p)
    {
        ptr = p;
    }

    // ❌ COPY CONSTRUCTOR IS DELETED
    // This physically prevents two uniquePtrs from wrapping the same raw pointer,
    // guaranteeing single, exclusive ownership and preventing Double Free errors.
    uniquePtr(const uniquePtr<T> &p) = delete;

    // ❌ COPY ASSIGNMENT IS DELETED
    // Just to be safe, we must also prevent p1 = p2
    uniquePtr& operator=(const uniquePtr<T> &p) = delete;

    // ✅ MOVE CONSTRUCTOR
    // Safely transfers ownership from one stack wrapper to another.
    // We steal the heap address, and leave the old wrapper empty (nullptr).
    uniquePtr(uniquePtr<T>&& other) noexcept
    {
        ptr = other.ptr;     // Steal the memory address
        other.ptr = nullptr; // Nullify the old one so its destructor doesn't double-free!
    }

    // ✅ MOVE ASSIGNMENT
    // Same concept, but handling an assignment to an already-existing uniquePtr.
    uniquePtr& operator=(uniquePtr<T>&& other) noexcept
    {
        if (this != &other) {
            delete ptr;          // Free our current memory before taking new memory
            ptr = other.ptr;     // Steal the new memory
            other.ptr = nullptr; // Nullify the old owner
        }
        return *this;
    }

    // RAII in Action (Destructor): 
    // When this uniquePtr stack variable goes out of scope, it automatically deletes the heap payload.
    ~uniquePtr()
    {
        delete ptr;
    }

    // Overloading the -> operator so we can interact with the wrapper exactly like a normal pointer.
    T *operator->()
    {
        return ptr;
    }

    // Overloading the * operator so we can dereference the pointer.
    // returning T& instead of T*. Dereferencing a pointer should return a reference to the actual object!
    T& operator*()
    {
        return *ptr;
    }
};

template <typename T>
class shared_pointer
{
private:
    int *count;
    T *ptr;

public:
    shared_pointer()
    {
    }

    // Constructor: initializes the pointer and creates a new reference count on the heap.
    shared_pointer(T *p)
    {
        // Initialize reference count on the heap to track shared ownership.
        ptr = p;
        count = new int(1);
    }

    shared_pointer(const shared_pointer<T> &other)
    {
        // Increment reference count when a new pointer shares ownership.
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    ~shared_pointer()
    {
        (*count)--;
        // Decrement count; delete data only when count reaches zero (last owner).
        if ((*count) == 0)
        {
            delete ptr;
            delete count;
        }
    }

    T *operator*()
    {
        return ptr;
    }

    T *operator->()
    {
        return ptr;
    }

    // Helper to check the current reference count (for debugging/testing).
    int getCount() const
    {
        return *count;
    }
};

class pun
{
private:
    int a;
    std::string str;

public:
    pun()
    {
        std::cout << "Default constructor called" << std::endl;
    }
    pun(std::string s, int num)
    {
        str = s;
        a = num;
        std::cout << "pun : Constructor called from " << s << " with value " << a << std::endl;
    }

    ~pun()
    {
        std::cout << "pun : Destructor called" << std::endl;
    }
    void setNum(int n)
    {
        a = n;
    }

    int getNum() const
    {
        return a;
    }

    void setString(std::string s)
    {
        str = s;
    }

    std::string getString() const
    {
        return str;
    }
};