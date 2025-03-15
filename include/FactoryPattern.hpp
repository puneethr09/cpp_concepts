#include <iostream>
#include <memory>

class ProductInterface
{
public:
    virtual ~ProductInterface() = default;
    virtual void print() = 0;
};

class ProductA : public ProductInterface
{
public:
    void print() override
    {
        std::cout << "ProductA" << std::endl;
    }
};

class ProductB : public ProductInterface
{
public:
    void print() override
    {
        std::cout << "ProductB" << std::endl;
    }
};

class Factory
{
public:
    virtual ~Factory() = default;
    virtual std::unique_ptr<ProductInterface> createProduct() const = 0;
};

class FactoryA : public Factory
{
public:
    std::unique_ptr<ProductInterface> createProduct() const override
    {
        return std::make_unique<ProductA>();
    };
};

class FactoryB : public Factory
{
public:
    std::unique_ptr<ProductInterface> createProduct() const override
    {
        return std::make_unique<ProductB>();
    };
};
