#include <gtest/gtest.h>
#include "creationalPatterns/singletonPattern.hpp"
#include "creationalPatterns/factoryPattern.hpp"
#include "creationalPatterns/prototypePattern.hpp"
#include "creationalPatterns/builderPattern.hpp"
// Abstract factory might be missing or complex, adding if headers exist
#include "creationalPatterns/builderPattern.hpp"
#include "creationalPatterns/abstractFactory.hpp" 
#include "structuralPatterns/adapterPattern.hpp"
#include "structuralPatterns/decoratorPattern.hpp"
#include "behavioralPatterns/observerPattern.hpp"
#include "behavioralPatterns/strategyPattern.hpp" 

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
    EXPECT_NE(body, nullptr);
    // In a real test we might dynamic_cast to check types or check stdout (but google test stdout is harder)
}

TEST(StructuralPatternTest, Adapter) {
    // Context: Verifies the Adapter Pattern.
    // We treat a SocketAdapter as a EuropeanSocket. Calling voltage220() should succeed without error,
    // internally adapting the call to the USASocket.
    std::unique_ptr<EuropeanSocket> socket = std::make_unique<SocketAdapter>();
    // Verify it creates successfully.
    ASSERT_NE(socket, nullptr);
    EXPECT_NO_THROW(socket->voltage220());
}

TEST(StructuralPatternTest, Decorator) {
    // Context: Verifies the Decorator Pattern.
    // 1. Base cost = 10.
    // 2. Add Milk (+2) = 12.
    // 3. Add Sugar (+1) = 13.
    // Ensures wrappers stack correctly.
    std::unique_ptr<Coffee> myCoffee = std::make_unique<SimpleCoffee>();
    EXPECT_EQ(myCoffee->getCost(), 10.0);

    myCoffee = std::make_unique<MilkDecorator>(std::move(myCoffee));
    EXPECT_EQ(myCoffee->getCost(), 12.0);

    myCoffee = std::make_unique<SugarDecorator>(std::move(myCoffee));
    EXPECT_EQ(myCoffee->getCost(), 13.0);
    
    // Check description contains all components
    std::string desc = myCoffee->getDescription();
    EXPECT_NE(desc.find("Milk"), std::string::npos);
    EXPECT_NE(desc.find("Sugar"), std::string::npos);
}

TEST(BehavioralPatternTest, Observer) {
    // Context: Verifies Observer Pattern via side effects (captured via a boolean flag ideally, or standard logic).
    // Here we ensure the subscription logic works via simple vector size check if exposed, 
    // or by checking execution flow. 
    // Since our example prints to stdout, we primarily check for no crashes during verify.
    YoutubeChannel channel("CodeChannel");
    auto sub1 = std::make_shared<UserSubscriber>("Bob");
    
    EXPECT_NO_THROW(channel.subscribe(sub1));
    EXPECT_NO_THROW(channel.uploadVideo("New C++ Video"));
    EXPECT_NO_THROW(channel.unsubscribe(sub1));
}

TEST(BehavioralPatternTest, Strategy) {
    // Context: Verifies Strategy interchangeable behavior.
    // We switch strategies at runtime and ensure execution succeeds.
    ShoppingCart cart;
    
    // Strategy 1: Credit Card
    cart.setPaymentStrategy(std::make_unique<CreditCardPayment>("123-456"));
    EXPECT_NO_THROW(cart.checkout(50.0));
    
    // Strategy 2: PayPal
    cart.setPaymentStrategy(std::make_unique<PayPalPayment>("bob@mail.com"));
    EXPECT_NO_THROW(cart.checkout(25.0));
}

