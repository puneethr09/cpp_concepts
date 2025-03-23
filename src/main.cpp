#include "include/log.hpp"
#include "include/pointers.hpp"
#include "include/stl.hpp"
#include "include/multithread.hpp"
#include "include/creationalPatterns/factoryPattern.hpp"
#include "include/creationalPatterns/singletonPattern.hpp"
#include "include/creationalPatterns/prototypePattern.hpp"
#include "include/creationalPatterns/abstractFactory.hpp"
#include "include/creationalPatterns/builderPattern.hpp"
#include <map>
#include <vector>
#include <memory> // Ensure this include is present
#include <set>
#include <list>
#include <iostream> // Add this include for std::cout
#include <utility>  // Add this include for std::move

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

int main()
{
    // std::cout << "STL vec example" << std::endl;
    // stl_vec();

    // std::cout << "smart pointers built-in example" << std::endl;
    // pointer();

    // std::cout << "smart pointers own example" << std::endl;
    // UniqueP();

    // block to test pun class
    // {
    //     pun pu;
    //     pu.setString("Hello! Puneeth here from main");
    //     pu.setNum(-10);
    //     std::cout << pu.getString() << std::endl;
    //     std::cout << pu.getNum() << std::endl;
    // }

    // maps start here
    // maps();

    // sets start here
    // sets();

    // shared pointers
    // sharedP();

    // linked list
    // linkedList();

    // lists
    // lists();

    // Singleton example as a shared pointer
    // auto p = Singleton::getInstance();
    // std::cout << "Singleton data is " << p->getData() << std::endl;

    // {
    //     auto q = Singleton::getInstance();
    //     std::cout << "Current shared count: " << q.use_count() << std::endl;
    // }
    // std::cout << "Shared count after q goes out of scope: " << p.use_count() << std::endl;

    // multithreaded example
    // multithreaded();

    // factory pattern example
    // std::string fileType = "Word"; // Simulated user input
    // // Create document dynamically
    // std::unique_ptr<Document> doc = DocumentFactory::createDocument(fileType);
    // if (doc)
    // {
    //     doc->open();
    //     doc->save();
    // }
    // else
    // {
    //     std::cout << "Invalid document type!" << std::endl;
    // }

    // prototype pattern example
    // auto warrior1 = std::make_unique<Warrior>("Sword", 100);
    // auto mage1 = std::make_unique<Mage>("Fireball", 150);
    // warrior1->showCharacter();
    // mage1->showCharacter();
    // cout << "address of warrior1 is " << warrior1.get() << endl;
    // cout << "address of mage1 is " << mage1.get() << endl;
    // // Cloning characters
    // auto warrior2 = warrior1->clone();
    // auto mage2 = mage1->clone();
    // cout << "address of warrior2 is " << warrior2.get() << endl;
    // cout << "address of mage2 is " << mage2.get() << endl;
    // warrior2->showCharacter();
    // mage2->showCharacter();

    // abstract factory pattern example
    // auto car = CarProvider::createCarFactory("sedan");
    // if (car)
    // {
    //     auto engine = car->createEngine();
    //     auto wheels = car->createWheels();
    //     auto body = car->createBody();
    //     engine->display();
    //     wheels->display();
    //     body->display();
    // }

    // builder pattern example
    // BurgerBuilder burgerBuilder;
    // Burger burger = burgerBuilder.addBread("Wheat")
    //                     .addMeat("Chicken")
    //                     .addCheese("Swiss")
    //                     .addSauce("Mayo")
    //                     .addVeggies("Lettuce")
    //                     .build();
    // burger.display();
    // Burger burger1 = burgerBuilder.addBread("White")
    //                      .addMeat("Beef")
    //                      .addCheese("American")
    //                      .addSauce("Mustard")
    //                      .addVeggies("Tomato")
    //                      .build();
    // burger1.display();

    return 0;
}