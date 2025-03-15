#include "include/log.hpp"
#include "include/pointers.hpp"
#include "include/stl.hpp"
#include "include/multithread.hpp"
#include "include/FactoryPattern.hpp"
#include <map>
#include <vector>
#include <memory> // Ensure this include is present
#include <set>
#include <list>
#include <iostream> // Add this include for std::cout
#include <utility>  // Add this include for std::move

#define LOG3(x, y, z) std::cout << x << " " << y << " " << z << std::endl;

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

void stl_vec()
{
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 100, 200};
    size_t s = sizeof(v) / sizeof(int);
    vectors<int> vec(v, s);
    LOG("size is", vec.getSize());
    LOG("capacity is", vec.getCap());
    vec.print();

    vec.push(14, 300);
    vec.push(4, 400);
    vec.print();

    vec.pop();
    vec.print();
}

void pointer()
{
    int a = 5;
    int *ptr = &a;
    LOG("ptr = ", ptr);
    LOG("*ptr = ", *ptr);

    int *ptr1 = std::move(ptr); // Qualify std::move
    LOG("ptr = ", ptr);
    LOG("ptr1 = ", ptr1);
    LOG("*ptr1 = ", *ptr1);
    std::cout << std::endl;
    LOG3("unique pointer example", " starts", "here");

    std::unique_ptr<int> p = std::make_unique<int>(15); // Ensure C++14 support
    LOG("*p= ", *p);
    std::unique_ptr<int> p1 = std::move(p); // Qualify std::move
    LOG("*p1 = ", *p1);
    if (p == nullptr)
    {
        std::cout << "p is null" << std::endl;
    }
    if (p1 == nullptr)
    {
        std::cout << "p1 is null" << std::endl;
    }
}

void UniqueP()
{
    {
        uniquePtr<pun> p1(new pun("unique pointer", 20));
        p1->setString("Hello! Puneeth here");
        p1->setNum(10);
        std::cout << p1->getString() << std::endl;
        std::cout << p1->getNum() << std::endl;
    }
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

void maps()
{

    std::cout << std::endl
              << "-----------------CREATION-----------------" << std::endl;
    std::map<map_str, int> m;
    map_str m1("xyz", 1);
    map_str m2("def", 2);
    map_str m3("ghi", 3);
    map_str m4("kdb", 100);
    map_str m5;
    std::shared_ptr<map_str> m6 = std::make_shared<map_str>("tuv", 11);
    // map_str *m7 = new map_str("llp", 30);

    std::cout << std::endl
              << "-----------------INSERTION-----------------" << std::endl;
    std::cout << "insert m1" << std::endl;
    m[m1] = 1;
    std::cout << "insert m2" << std::endl;
    m[m2] = 2;
    std::cout << "insert m3" << std::endl;
    m[m3] = 3;
    std::cout << "insert m4" << std::endl;
    m[m4] = 4;
    std::cout << "insert m5" << std::endl;
    m[m5] = 98;
    std::cout << "insert m6" << std::endl;
    m[*m6] = 123;
    // std::cout<<"insert m7" << std::endl;
    // m[*m7] = 129;

    std::cout << std::endl
              << "-----------------DISPLAY-----------------" << std::endl;
    for (auto &itr : m)
    {
        std::cout << "string " << itr.first.s << " ---- num " << itr.first.num << " ---- value " << itr.second << std::endl;
    }

    std::cout << std::endl
              << "-----------------COMPLETE-----------------" << std::endl;
}

void sets()
{

    std::cout << std::endl
              << "-----------------SET CREATION-----------------" << std::endl;
    std::set<map_str> s;
    map_str m1("xyz", 1);
    map_str m2("def", 2);
    map_str m3("ghi", 3);
    map_str m4("kdb", 100);
    map_str m5;
    std::shared_ptr<map_str> m6 = std::make_shared<map_str>("tuv", 11);
    // map_str *m7 = new map_str("llp", 30);

    std::cout << std::endl
              << "-----------------INSERTION-----------------" << std::endl;
    std::cout << "insert m1" << std::endl;
    s.insert(m1);
    std::cout << "insert m2" << std::endl;
    s.insert(m2);
    std::cout << "insert m3" << std::endl;
    s.insert(m3);
    std::cout << "insert m4" << std::endl;
    s.insert(m4);
    std::cout << "insert m5" << std::endl;
    s.insert(m5);
    std::cout << "insert m6" << std::endl;
    s.insert(*m6);
    // std::cout<<"insert m7" << std::endl;
    // m[*m7] = 129;

    std::cout << std::endl
              << "-----------------DISPLAY-----------------" << std::endl;
    for (auto &itr : s)
    {
        std::cout << "string " << itr.s << " ---- num " << itr.num << std::endl;
    }

    std::cout << std::endl
              << "-----------------COMPLETE-----------------" << std::endl;
}

void sharedP()
{
    std::cout << "sharedP called" << std::endl;
    {
        shared_pointer<pun> sp(new pun("shared ptr", 10));
        std::cout << "1) count is " << sp.getCount() << std::endl;
        {
            shared_pointer<pun> sp1 = sp;
            std::cout << "2) count is " << sp1.getCount() << std::endl;
        }
        std::cout << "3) count is " << sp.getCount() << std::endl;
    }
    std::cout << "sharedP done" << std::endl;
}

void linkedList()
{
    std::cout << "linkedList start" << std::endl;
    node *node1 = new node(10);

    //  std::cout<< "node data is " << node1->getData() << std::endl;
    //  std::cout<< "next ptr is " << node1->getNext() << std::endl;

    node *head = node1;
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 30);
    print(head);

    insertAtHead(head, 40);
    print(head);

    node *tail = node1;

    inserAtTail(tail, 100);
    inserAtTail(tail, 200);
    inserAtTail(tail, 300);

    print(head);

    insertAtPosition(head, 4, 1000);

    print(head);

    insertAtPosition(head, 1, 1111);

    print(head);

    insertAtPosition(head, 10, 9999);

    print(head);
}

void lists()
{

    std::cout << std::endl
              << std::endl
              << "STL lists example" << std::endl;

    std::list<int> l;
    l.assign(4, 2);
    for (auto i : l)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::list<int>::iterator itr = l.begin();
    std::advance(itr, 2);
    l.insert(itr, 5);

    for (auto i : l)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

class Singleton
{
private:
    static Singleton *ptr;
    static int count;
    Singleton()
    {
        data = 10;
        std::cout << "singleton constructor called with data " << data << std::endl;
    }

public:
    int data;
    static Singleton *getInstance()
    {
        std::cout << "singleton getInstance called" << std::endl;
        if (ptr == NULL)
        {
            std::cout << "singleton ptr creation ongoing" << std::endl;
            ptr = new Singleton();
        }
        ++count;
        return ptr;
    }

    static void releaseInstance()
    {
        --count;
        std::cout << "singleton releaseInstance called, current count is " << count << std::endl;
        if ((0 == count) && (NULL != ptr))
        {
            delete ptr;
            ptr = NULL;
        }
    }

    ~Singleton()
    {
        std::cout << "singleton destructor called" << std::endl;
    }
};

Singleton *Singleton::ptr = 0;
int Singleton::count = 0;

int main()
{
    // std::cout << std::endl
    //           << std::endl;
    // std::cout << "STL vec example" << std::endl;
    // stl_vec();
    // std::cout << std::endl
    //           << std::endl
    //           << std::endl;
    // std::cout << "smart pointers built-in example" << std::endl;
    // pointer();
    // std::cout << std::endl
    //           << std::endl
    //           << std::endl;
    // std::cout << "smart pointers own example" << std::endl;
    // UniqueP();
    // std::cout << std::endl
    //           << std::endl;

    // {
    //     pun pu;
    //     pu.setString("Hello! Puneeth here from main");
    //     pu.setNum(-10);
    //     std::cout << pu.getString() << std::endl;
    //     std::cout << pu.getNum() << std::endl;
    // }
    // // maps start here

    // maps();
    // sets();

    // sharedP();

    // linkedList();

    // lists();

    // std::cout << std::endl
    //           << std::endl
    //           << "Singleton implementation" << std::endl;

    // Singleton *p = Singleton::getInstance();

    // std::cout << "Singleton data is " << p->data << std::endl;

    // Singleton *q = Singleton::getInstance();

    // p->releaseInstance();
    // // std::cout << "count is " <<
    // q->releaseInstance();
    // // std::cin.get();

    // std::cout << std::endl
    //           << std::endl;

    // multithreaded();

    FactoryA factoryA;
    FactoryB factoryB;

    auto productA = factoryA.createProduct();
    auto productB = factoryB.createProduct();

    productA->print();
    productB->print();

    return 0;
}