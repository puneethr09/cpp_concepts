#include <iostream>
#include <string>
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
