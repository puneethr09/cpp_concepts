#include <iostream>
#include <memory>

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