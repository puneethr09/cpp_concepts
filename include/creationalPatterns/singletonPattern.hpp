#include <iostream>
#include <memory>
#include <mutex>

class Singleton
{
private:
    int data;
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

    static std::weak_ptr<Singleton> instance;
    static std::mutex mtx;

public:
    int getData() const { return data; }

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
