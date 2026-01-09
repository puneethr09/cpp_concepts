#include <iostream>
#include <memory>
#include <mutex>

// The Singleton Pattern is a creational design pattern that ensures a class has only one instance and provides a global point of access to that instance.
// It is useful when exactly one object is needed to coordinate actions across the system.
// This pattern promotes controlled access to the sole instance and can be used for managing shared resources, configurations, or logging.

// below example explained:
//  Singleton class has a private constructor to prevent direct instantiation
//  It uses a static method getInstance() to provide access to the single instance
//  The instance is managed using a std::shared_ptr and std::weak_ptr to ensure proper memory management and avoid memory leaks
//  A mutex is used to ensure thread safety when creating the instance
//  Example usage:
//  auto singleton1 = Singleton::getInstance();
//  auto singleton2 = Singleton::getInstance();
//  std::cout << "Data from singleton1: " << singleton1->getData() << std::endl;
//  std::cout << "Data from singleton2: " << singleton2->getData() << std::endl;
//  Output: Creating Singleton instance using shared pointer.
//          Data from singleton1: 10
//          Returning existing Singleton instance.
//          Data from singleton2: 10
//  This demonstrates the Singleton Pattern by ensuring that only one instance of the Singleton class is created and providing a global access point to it.
//  Note: Remember to include necessary headers and use appropriate namespaces in your actual implementation.
//  This code is written in C++14 standard.

class Singleton
{
private:
    int data;
    // Private Constructor: Prevents direct instantiation of the class from outside.
    Singleton()
    {
        data = 10;
        std::cout << "singleton constructor called with data " << data << std::endl;
    }
    ~Singleton()
    {
        std::cout << "singleton destructor called" << std::endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;


    
    // Static weak_ptr to hold the single instance without preventing destruction if needed.
    static std::weak_ptr<Singleton> instance;
    static std::mutex mtx;

public:
    int getData() const { return data; }

    // Public Static Accessor: The only way to get the instance of the Singleton.
    // Uses Double-Checked Locking (via call_once style logic with mutex) to ensure thread safety.
    static std::shared_ptr<Singleton> getInstance()
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::shared_ptr<Singleton> sharedInstance = instance.lock();
        if (!sharedInstance)
        {
            std::cout << "Creating Singleton instance using shared pointer." << std::endl;
            sharedInstance = std::shared_ptr<Singleton>(new Singleton(), [](Singleton *ptr)
                                                        { delete ptr; });
            instance = sharedInstance;
        }
        else
        {
            std::cout << "Returning existing Singleton instance." << std::endl;
        }
        return sharedInstance;
    }
};

std::weak_ptr<Singleton> Singleton::instance;
std::mutex Singleton::mtx;
