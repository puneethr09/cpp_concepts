#pragma once
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class uniquePtr
{
private:
    // Pointer to store the pointer passed to the unique pointer. This is made private to ensure that the pointer is not accessed directly.
    T *ptr;

public:
    // Default constructor is deleted, this is to ensure that the unique pointer is not created without a pointer.
    uniquePtr() = delete;

    // Constructor to initialize the unique pointer with a pointer. This is the main constructor.
    // Constructor: Takes ownership of the raw pointer.
    uniquePtr(T *p)
    {
        ptr = p;
    }

    // Delete copy constructor to ensure unique ownership (cannot copy, must move).
    uniquePtr(const uniquePtr<T> &p) = delete;

    // Destructor to delete the pointer when the unique pointer goes out of scope.
    // Destructor: Automatically releases the owned memory when the object goes out of scope.
    ~uniquePtr()
    {
        delete ptr;
    }

    // Overloading the -> operator to access the pointer. This is similar to the normal pointer.
    // Arrow Operator: Allows accessing members of the underlying object like a raw pointer.
    T *operator->()
    {
        return ptr;
    }

    // Overloading the * operator to access the value of the pointer. This is similar to the normal pointer.
    T *operator*()
    {
        return ptr;
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