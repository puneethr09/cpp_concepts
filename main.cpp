#include "include/log.hpp"
#include "include/pointers.hpp"
#include "include/stl.hpp"
#include "include/multithread.hpp"
#include <map>
#include <vector>
#include <memory>
#include <set>
#include <list>

#define LOG3(x, y, z) std::cout << x << " " << y << " " << z << std::endl;

class pun
{
private:
    int a;
    string str;

public:
    pun()
    {
        cout << "Default contructor called" << endl;
    }
    pun(string s, int num)
    {
        str = s;
        a = num;
        cout << "pun : Contructor called from " << s << " with value " << a << endl;
    }

    ~pun()
    {
        cout << "pun : Destructor called" << endl;
    }
    void setNum(int n)
    {
        a = n;
    }

    int getNum() const
    {
        return a;
    }

    void setString(string s)
    {
        str = s;
    }

    string getString() const
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

    int *ptr1 = move(ptr);
    LOG("ptr = ", ptr);
    LOG("ptr1 = ", ptr1);
    LOG("*ptr1 = ", *ptr1);
    cout << endl;
    LOG3("unique pointer example", " starts", "here");

    std::unique_ptr<int> p = std::make_unique<int>(15);
    LOG("*p= ", *p);
    std::unique_ptr<int> p1 = move(p);
    LOG("*p1 = ", *p1);
    if (p == nullptr)
    {
        cout << "p is null" << endl;
    }
    if (p1 == nullptr)
    {
        cout << "p1 is null" << endl;
    }
}

void UniqueP()
{
    {
        uniquePtr<pun> p1(new pun("unique pointer", 20));
        p1->setString("Hello! Puneeth here");
        p1->setNum(10);
        cout << p1->getString() << endl;
        cout << p1->getNum() << endl;
    }
}

class map_str
{

public:
    string s;
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
        cout << "map_str : Destr called of string " << s << endl;
    }

    map_str(string str, int n)
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

    cout << endl
         << "-----------------CREATION-----------------" << endl;
    std::map<map_str, int> m;
    map_str m1("xyz", 1);
    map_str m2("def", 2);
    map_str m3("ghi", 3);
    map_str m4("kdb", 100);
    map_str m5;
    shared_ptr<map_str> m6 = make_shared<map_str>("tuv", 11);
    //map_str *m7 = new map_str("llp", 30);

    cout << endl
         << "-----------------INSERTION-----------------" << endl;
    cout << "insert m1" << endl;
    m[m1] = 1;
    cout << "insert m2" << endl;
    m[m2] = 2;
    cout << "insert m3" << endl;
    m[m3] = 3;
    cout << "insert m4" << endl;
    m[m4] = 4;
    cout << "insert m5" << endl;
    m[m5] = 98;
    cout << "insert m6" << endl;
    m[*m6] = 123;
    // cout<<"insert m7" << endl;
    // m[*m7] = 129;

    cout << endl
         << "-----------------DISPLAY-----------------" << endl;
    for (auto &itr : m)
    {
        cout << "string " << itr.first.s << " ---- num " << itr.first.num << " ---- value " << itr.second << endl;
    }

    cout << endl
         << "-----------------COMPLETE-----------------" << endl;
}

void sets()
{

    cout << endl
         << "-----------------SET CREATION-----------------" << endl;
    std::set<map_str> s;
    map_str m1("xyz", 1);
    map_str m2("def", 2);
    map_str m3("ghi", 3);
    map_str m4("kdb", 100);
    map_str m5;
    shared_ptr<map_str> m6 = make_shared<map_str>("tuv", 11);
    //map_str *m7 = new map_str("llp", 30);

    cout << endl
         << "-----------------INSERTION-----------------" << endl;
    cout << "insert m1" << endl;
    s.insert(m1);
    cout << "insert m2" << endl;
    s.insert(m2);
    cout << "insert m3" << endl;
    s.insert(m3);
    cout << "insert m4" << endl;
    s.insert(m4);
    cout << "insert m5" << endl;
    s.insert(m5);
    cout << "insert m6" << endl;
    s.insert(*m6);
    // cout<<"insert m7" << endl;
    // m[*m7] = 129;

    cout << endl
         << "-----------------DISPLAY-----------------" << endl;
    for (auto &itr : s)
    {
        cout << "string " << itr.s << " ---- num " << itr.num << endl;
    }

    cout << endl
         << "-----------------COMPLETE-----------------" << endl;
}

void sharedP()
{
    cout << "sharedP called" << endl;
    {
        shared_pointer<pun> sp(new pun("shared ptr", 10));
        cout << "1) count is " << sp.getCount() << endl;
        {
            shared_pointer<pun> sp1 = sp;
            cout << "2) count is " << sp1.getCount() << endl;
        }
        cout << "3) count is " << sp.getCount() << endl;
    }
    cout << "sharedP done" << endl;
}

void linkedList()
{
    cout << "linkedList start" << endl;
    node *node1 = new node(10);

    //  cout<< "node data is " << node1->getData() << endl;
    //  cout<< "next ptr is " << node1->getNext() << endl;

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

    cout << endl
         << endl
         << "STL lists example" << endl;

    std::list<int> l;
    l.assign(4, 2);
    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;

    std::list<int>::iterator itr = l.begin();
    advance(itr, 2);
    l.insert(itr, 5);

    for (auto i : l)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Singleton
{
private:
    static Singleton *ptr;
    static int count;
    Singleton()
    {
        data = 10;
        cout << "singleton constructor called with data " << data << endl;
    }

public:
    int data;
    static Singleton *getInstance()
    {
        cout << "singleton getInstance called" << endl;
        if (ptr == NULL)
        {
            cout << "singleton ptr creation ongoing" << endl;
            ptr = new Singleton();
        }
        ++count;
        return ptr;
    }

    static void releaseInstance()
    {
        --count;
        cout << "singleton releaseInstance called, current count is " << count << endl;
        if ((0 == count) && (NULL != ptr))
        {
            delete ptr;
            ptr = NULL;
        }
    }

    ~Singleton()
    {
        cout << "singleton destructor called" << endl;
    }
};

Singleton *Singleton::ptr = 0;
int Singleton::count = 0;

int main()
{
    cout << endl
         << endl;
    cout << "STL vec example" << endl;
    stl_vec();
    cout << endl
         << endl
         << endl;
    cout << "smart pointers built-in example" << endl;
    pointer();
    cout << endl
         << endl
         << endl;
    cout << "smart pointers own example" << endl;
    UniqueP();
    cout << endl
         << endl;

    {
        pun pu;
        pu.setString("Hello! Puneeth here from main");
        pu.setNum(-10);
        cout << pu.getString() << endl;
        cout << pu.getNum() << endl;
    }
    //maps start here

    maps();
    sets();

    sharedP();

    linkedList();

    lists();

    cout << endl
         << endl
         << "Singleton implementation" << endl;

    Singleton *p = Singleton::getInstance();

    cout << "Singleton data is " << p->data << endl;

    Singleton *q = Singleton::getInstance();

    p->releaseInstance();
    //cout << "count is " <<
    q->releaseInstance();
    //cin.get();

    cout << endl
         << endl;

    multithreaded();
}