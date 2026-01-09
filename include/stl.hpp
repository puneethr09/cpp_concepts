#pragma once

#include "log.hpp"
#include <iostream>

using namespace std;

template <typename T>
class vectors
{

private:
    T *arr;
    int curr;
    int cap;

public:
    // Default Constructor: Initializes an empty vector with capacity of 1.
    vectors()
    {
        arr = new T[1];
        curr = 0;
        cap = 1;
    }

    ~vectors()
    {
        delete[] arr;
    }

    vectors(T *a, size_t s)
    {
        arr = new T[1];
        curr = 0;
        cap = 1;
        for (int i = 0; i < s; i++)
        {
            push(a[i]);
        }
    }

    // Push: Adds an element to the end. Resizes array if capacity is full.
    void push(T data)
    {
        // Double capacity when full to ensure amortized O(1) insertion time.
        if (curr == cap)
        {
            cap *= 2;
            T *temp = new T[cap];
            for (int i = 0; i < curr; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[curr] = data;
        curr++;
    }

    // Pop: Removes the last element by decrementing the size counter (lazy deletion).
    void pop()
    {
        curr--;
    }

    unsigned int getSize()
    {
        return curr;
    }

    unsigned int getCap()
    {
        return cap;
    }

    void push(int index, T data)
    {
        if (index == curr)
            push(data);
        else if (index > curr)
        {
            LOG("accessing illegal index, current size is", getSize());
        }
        else
            arr[index] = data;
    }

    void print()
    {
        for (int i = 0; i < curr; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// linked list
class node
{
    int data;
    node *next;

public:
    node(int n)
    {
        data = n;
        next = nullptr;
    }

    int getData() const
    {
        return data;
    }

    node *getNext() const
    {
        return next;
    }

    void setData(const int &d)
    {
        data = d;
    }

    void setNext(node *node)
    {
        next = node;
    }
};

// Insert a new value at the beginning of the list. Updates head pointer.
void insertAtHead(node *&head, int n)
{
    cout << "inserting value " << n << " at head" << endl;
    // Insert at head is an O(1) operation involving simple pointer checks.
    // new node
    node *temp = new node(n);
    temp->setNext(head);
    head = temp;
}

// Traverse to the end of the list and append a new value. O(N) operation.
void inserAtTail(node *&tail, int n)
{
    cout << "inserting value " << n << " at tail" << endl;

    // new node
    node *temp = new node(n);
    tail->setNext(temp);
    tail = temp;
}

void insertAtPosition(node *&head, int pos, int n)
{
    cout << "inserting value " << n << " at position " << pos << endl;

    if (pos == 1)
    {
        insertAtHead(head, n);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->getNext();
        cnt++;
        // cout << "count " << cnt << " temp data val " << temp->getData()<<endl ;
    }

    if (temp->getNext() == NULL)
    {
        inserAtTail(temp, n);
        return;
    }

    // new node
    node *nodeInsert = new node(n);
    nodeInsert->setNext(temp->getNext());
    temp->setNext(nodeInsert);
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

class map_str
{

public:
    std::string s;
    int num;

public:
    map_str()
    {
        s = "default";
        num = -1;
        LOG3(" map_str : default constr with", s, num);
    }

    ~map_str()
    {
        std::cout << "map_str : Destr called of string " << s << std::endl;
    }

    map_str(std::string str, int n)
    {
        s = str;
        num = n;
        LOG3("param constr with", s, n);
    }

    map_str(const map_str &other)
    {
        s = other.s;
        num = other.num;
        LOG3("copy constr with", s, num);
    }

    bool operator<(const map_str &rhs) const
    {
        if (s == rhs.s)
            return num < rhs.num;
        else
            return s < rhs.s;
    }
};
