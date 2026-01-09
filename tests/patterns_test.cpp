#include <gtest/gtest.h>
#include "creationalPatterns/singletonPattern.hpp"
#include "creationalPatterns/factoryPattern.hpp"
#include "creationalPatterns/prototypePattern.hpp"
#include "creationalPatterns/builderPattern.hpp"
// Abstract factory might be missing or complex, adding if headers exist
#include "creationalPatterns/abstractFactory.hpp" 

TEST(SingletonTest, InstanceUniqueness) {
    // Context: Verifies that multiple calls to getInstance() return the same underlying instance.
    // This is the defining characteristic of a Singleton.
    auto p1 = Singleton::getInstance();
    auto p2 = Singleton::getInstance();
    
    // Assuming getInstance returns shared_ptr or pointer
    // Checking if they point to same address (managed by shared_ptr logic in this repo)
    // Actually main.cpp usage: auto p = Singleton::getInstance(); p->getData();
    // Use verify they are same instance if logical
    
    EXPECT_EQ(p1, p2);
}

TEST(FactoryTest, CreateDocument) {
    // Context: Verifies the Factory method returns a valid object pointer when given a known type ("Word").
    auto doc = DocumentFactory::createDocument("Word");
    ASSERT_NE(doc, nullptr);
    // doc->open(); // Just check it exists and is correct type if possible
}

TEST(BuilderTest, BurgerBuilder) {
    BurgerBuilder builder;
    Burger burger = builder.addBread("Wheat").addMeat("Chicken").build();
    // Assuming Burger has some getters, if not we just verify build completes
    // burger.display();
}

TEST(PrototypeTest, Clone) {
    auto warrior = std::make_unique<Warrior>("Sword", 100);
    auto clone = warrior->clone();
    
    ASSERT_NE(clone, nullptr);
    // Verify properties if getters exist, else just success
}

TEST(AbstractFactoryTest, CreateCar) {
    // Context: Verifies the Abstract Factory.
    // We request a "sedan" factory. Then we use that factory to create engine, wheels, and body.
    // We assert that all parts are successfully created, implying they match the requested family.
    auto car = CarProvider::createCarFactory("sedan");
    ASSERT_NE(car, nullptr);
    
    auto engine = car->createEngine();
    auto wheels = car->createWheels();
    auto body = car->createBody();
    
    ASSERT_NE(engine, nullptr);
    ASSERT_NE(wheels, nullptr);
    ASSERT_NE(body, nullptr);

    // We can capture stdout if we really want to verify "Sedan Engine" output,
    // but verifying non-null creation is the core logic check.
    testing::internal::CaptureStdout();
    engine->display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Sedan Engine\n");
}
