// builder pattern example

#ifndef BUILDERPATTERN_HPP
#define BUILDERPATTERN_HPP

#include <iostream>
#include <string>
#include <memory>

// builder patttern example to create burger with different ingredients

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
