// implementing a abstract factory class with usecase, types of cars and the componenets associated with it

// cars type be suv, sedan, hatchback
// components be engine, wheels, body
// each car type has its own engine, wheels and body
// each component has its own type
// each component has its own method to display the type

#include <iostream>
#include <memory>
#include <string>

class Engine
{
public:
    virtual void display() = 0;
    virtual ~Engine() = default;
};

class SUVEngine : public Engine
{
public:
    void display() override
    {
        std::cout << "SUV Engine" << std::endl;
    }
};

class SedanEngine : public Engine
{
public:
    void display() override
    {
        std::cout << "Sedan Engine" << std::endl;
    }
};

class HatchbackEngine : public Engine
{
public:
    void display() override
    {
        std::cout << "Hatchback Engine" << std::endl;
    }
};

class Wheels
{
public:
    virtual void display() = 0;
    virtual ~Wheels() = default;
};

class SUVWheels : public Wheels
{
public:
    void display() override
    {
        std::cout << "SUV Wheels" << std::endl;
    }
};

class SedanWheels : public Wheels
{
public:
    void display() override
    {
        std::cout << "Sedan Wheels" << std::endl;
    }
};

class HatchbackWheels : public Wheels
{
public:
    void display() override
    {
        std::cout << "Hatchback Wheels" << std::endl;
    }
};

class Body
{
public:
    virtual void display() = 0;
    virtual ~Body() = default;
};

class SUVBody : public Body
{
public:
    void display() override
    {
        std::cout << "SUV Body" << std::endl;
    }
};

class SedanBody : public Body
{
public:
    void display() override
    {
        std::cout << "Sedan Body" << std::endl;
    }
};

class HatchbackBody : public Body
{
public:
    void display() override
    {
        std::cout << "Hatchback Body" << std::endl;
    }
};

class CarFactory
{
public:
    virtual std::unique_ptr<Engine> createEngine() = 0;
    virtual std::unique_ptr<Wheels> createWheels() = 0;
    virtual std::unique_ptr<Body> createBody() = 0;
    virtual ~CarFactory() = default;
};

class SUVFactory : public CarFactory
{
public:
    std::unique_ptr<Engine> createEngine() override
    {
        return std::make_unique<SUVEngine>();
    }

    std::unique_ptr<Wheels> createWheels() override
    {
        return std::make_unique<SUVWheels>();
    }

    std::unique_ptr<Body> createBody() override
    {
        return std::make_unique<SUVBody>();
    }
};

class SedanFactory : public CarFactory
{
public:
    std::unique_ptr<Engine> createEngine() override
    {
        return std::make_unique<SedanEngine>();
    }

    std::unique_ptr<Wheels> createWheels() override
    {
        return std::make_unique<SedanWheels>();
    }

    std::unique_ptr<Body> createBody() override
    {
        return std::make_unique<SedanBody>();
    }
};

class HatchbackFactory : public CarFactory
{
public:
    std::unique_ptr<Engine> createEngine() override
    {
        return std::make_unique<HatchbackEngine>();
    }

    std::unique_ptr<Wheels> createWheels() override
    {
        return std::make_unique<HatchbackWheels>();
    }

    std::unique_ptr<Body> createBody() override
    {
        return std::make_unique<HatchbackBody>();
    }
};

class CarProvider
{
public:
    static std::unique_ptr<CarFactory> createCarFactory(const std::string &type)
    {
        // convert type to uppercase
        std::string typeUpper = type;
        for (auto &c : typeUpper)
        {
            c = toupper(c);
        }
        if (typeUpper == "SUV")
        {
            return std::make_unique<SUVFactory>();
        }
        else if (typeUpper == "SEDAN")
        {
            return std::make_unique<SedanFactory>();
        }
        else if (typeUpper == "HATCHBACK")
        {
            return std::make_unique<HatchbackFactory>();
        }
        else // Invalid car type
        {
            std::cout << "Invalid car type!" << std::endl;
            return nullptr;
        }
        return nullptr;
    }
};
