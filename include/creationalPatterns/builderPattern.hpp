// builder pattern example

#ifndef BUILDERPATTERN_HPP
#define BUILDERPATTERN_HPP

#include <iostream>
#include <string>
#include <memory>

// The Builder pattern is a creational design pattern that allows you to construct complex objects step by step.
// It separates the construction of an object from its representation, allowing the same construction process
// to create different representations.

//example explained below:
// Burger class representing the complex object to be built
// BurgerBuilder class to build the Burger object step by step
// Each method in BurgerBuilder adds a specific ingredient to the burger and returns the builder itself
// The build() method returns the final Burger object
// This allows for a fluent interface to create burgers with different combinations of ingredients
// Example usage:
// BurgerBuilder builder;
// Burger myBurger = builder.addBread("Whole Wheat").addMeat("Beef").addCheese("Cheddar").addSauce("Mayo").addVeggies("Lettuce").build();
// myBurger.display();
// Output: Burger with Whole Wheat bread, Beef meat, Cheddar cheese, Mayo sauce and Lettuce veggies
// This demonstrates the Builder pattern by allowing the construction of a complex Burger object with a clear and readable interface.

class Burger
{
public:
    std::string bread;
    std::string meat;
    std::string cheese;
    std::string sauce;
    std::string veggies;

    void display()
    {
        std::cout << "Burger with " << bread << " bread, " << meat << " meat, " << cheese << " cheese, " << sauce << " sauce and " << veggies << " veggies" << std::endl;
    }
};

class BurgerBuilder
{
public:
    Burger burger;

    BurgerBuilder &addBread(const std::string &bread)
    {
        burger.bread = bread;
        return *this;
    }

    BurgerBuilder &addMeat(const std::string &meat)
    {
        burger.meat = meat;
        return *this;
    }

    BurgerBuilder &addCheese(const std::string &cheese)
    {
        burger.cheese = cheese;
        return *this;
    }

    BurgerBuilder &addSauce(const std::string &sauce)
    {
        burger.sauce = sauce;
        return *this;
    }

    BurgerBuilder &addVeggies(const std::string &veggies)
    {
        burger.veggies = veggies;
        return *this;
    }

    Burger build()
    {
        return burger;
    }
};

#endif // BUILDERPATTERN_HPP
