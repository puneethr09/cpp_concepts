#include <iostream>
#include <memory>
#include <string>

// The Decorator Pattern is a structural design pattern that lets you attach new behaviors to objects by placing them inside wrapper objects that contain the behaviors.
// It allows you to add functionality dynamically without altering the underlying class structure.

// below example explained:
//  Coffee is the base component interface.
//  SimpleCoffee is the concrete component (basic coffee).
//  CoffeeDecorator is the base class for decorators.
//  MilkDecorator and SugarDecorator are concrete decorators adding specific ingredients.
//  Example usage:
//  std::unique_ptr<Coffee> myCoffee = std::make_unique<SimpleCoffee>();
//  myCoffee = std::make_unique<MilkDecorator>(std::move(myCoffee));
//  std::cout << myCoffee->getDescription() << " Cost: " << myCoffee->getCost() << std::endl;
//  Output: Simple Coffee, Milk Cost: 12

// Step 1: Base Component Interface
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Coffee() = default;
};

// Step 2: Concrete Component
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double getCost() const override {
        return 10.0;
    }
};

// Step 3: Base Decorator
// Holds a reference to a Coffee object and implements the Coffee interface, delegating to the wrapped object.
class CoffeeDecorator : public Coffee {
protected:
    std::unique_ptr<Coffee> coffee;

public:
    CoffeeDecorator(std::unique_ptr<Coffee> c) : coffee(std::move(c)) {}

    std::string getDescription() const override {
        return coffee->getDescription();
    }

    double getCost() const override {
        return coffee->getCost();
    }
};

// Step 4: Concrete Decorators
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    double getCost() const override {
        return coffee->getCost() + 2.0;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::unique_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    double getCost() const override {
        return coffee->getCost() + 1.0;
    }
};
