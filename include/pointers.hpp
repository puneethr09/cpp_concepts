#pragma once
#include <iostream>
#include <memory>
#include <string>

template <typename T>
class uniquePtr
{
private:
    T *ptr;

public:
    uniquePtr() = delete;

    uniquePtr(T *p)
    {
        ptr = p;
    }

    uniquePtr(T &p)
    {
        ptr = p;
    }

    uniquePtr(const uniquePtr<T> &p) = delete;

    ~uniquePtr()
    {
        delete ptr;
    }

    T *operator->()
    {
        return ptr;
    }

    T *operator*()
    {
        return &ptr;
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

    shared_pointer(T *p)
    {
        ptr = p;
        count = new int(1);
    }

    shared_pointer(const shared_pointer<T> &other)
    {
        ptr = other.ptr;
        count = other.count;
        (*count)++;
    }

    ~shared_pointer()
    {
        (*count)--;
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