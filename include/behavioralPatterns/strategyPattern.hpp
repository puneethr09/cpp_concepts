#include <iostream>
#include <memory>
#include <string>

// The Strategy Pattern is a behavioral design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.
// It allows the algorithm to vary independently from clients that use it.

// below example explained:
//  PaymentStrategy is the interface for all payment methods.
//  CreditCardPayment and PayPalPayment are concrete implementations.
//  ShoppingCart uses a PaymentStrategy to process payment.
//  Example usage:
//  ShoppingCart cart;
//  cart.setPaymentStrategy(std::make_unique<CreditCardPayment>("1234-5678"));
//  cart.checkout(100.0);
//  Output: Paid 100 using Credit Card 1234-5678

// Step 1: Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Step 2: Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;
public:
    CreditCardPayment(std::string number) : cardNumber(number) {}

    void pay(double amount) override {
        std::cout << "Paid " << amount << " using Credit Card " << cardNumber << std::endl;
    }
};

class PayPalPayment : public PaymentStrategy {
private:
    std::string email;
public:
    PayPalPayment(std::string _email) : email(_email) {}

    void pay(double amount) override {
        std::cout << "Paid " << amount << " using PayPal " << email << std::endl;
    }
};

// Step 3: Context
class ShoppingCart {
private:
    std::unique_ptr<PaymentStrategy> strategy;

public:
    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> s) {
        strategy = std::move(s);
    }

    void checkout(double amount) {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "Payment method not set!" << std::endl;
        }
    }
};
