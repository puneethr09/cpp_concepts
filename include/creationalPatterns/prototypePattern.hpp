#include <iostream>
#include <memory>

// The Prototype Pattern is a creational design pattern that allows for the cloning of existing objects without depending on their concrete classes.
// It is useful when the cost of creating a new object is expensive or complex, and you want to create new objects by copying existing ones.
// This pattern promotes flexibility and reusability by enabling the creation of new objects through cloning rather than instantiation.

// below example explained:
//  GameCharacter is the base prototype interface with a clone() method for creating copies of objects
//  Warrior and Mage are concrete classes derived from GameCharacter implementing the clone() method for deep copying
//  Example usage:
//  std::unique_ptr<GameCharacter> originalWarrior = std::make_unique<Warrior>("Sword", 100);
//  std::unique_ptr<GameCharacter> clonedWarrior = originalWarrior->clone();
//  originalWarrior->showCharacter();
//  clonedWarrior->showCharacter();
//  Output: Warrior with 100 HP, Weapon: Sword
//          Warrior with 100 HP, Weapon: Sword
//  This demonstrates the Prototype Pattern by allowing the creation of new GameCharacter objects through cloning existing ones, ensuring that the new objects are independent copies.
//  Note: Remember to include necessary headers and use appropriate namespaces in your actual implementation.
//  This code is written in C++14 standard.

// Step 1: Base Prototype Interface
class GameCharacter
{
public:
    virtual std::unique_ptr<GameCharacter> clone() const noexcept = 0;
    virtual void showCharacter() const = 0;
    virtual ~GameCharacter() = default;
};

// Step 2: Concrete Warrior Class
class Warrior : public GameCharacter
{
    std::string weapon;
    int health;

public:
    Warrior(std::string wp, int hp) : weapon(std::move(wp)), health(hp) {}

    // Clone method (Deep Copy)
    std::unique_ptr<GameCharacter> clone() const noexcept override
    {
        return std::make_unique<Warrior>(*this);
    }

    void showCharacter() const override
    {
        std::cout << "Warrior with " << health << " HP, Weapon: " << weapon << "\n";
    }
};

// Step 3: Concrete Mage Class
class Mage : public GameCharacter
{
    std::string spell;
    int mana;

public:
    Mage(std::string sp, int mp) : spell(std::move(sp)), mana(mp) {}

    // Clone method (Deep Copy)
    std::unique_ptr<GameCharacter> clone() const noexcept override
    {
        return std::make_unique<Mage>(*this);
    }

    void showCharacter() const override
    {
        std::cout << "Mage with " << mana << " Mana, Spell: " << spell << "\n";
    }
};