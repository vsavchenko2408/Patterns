#include <iostream>

class Character
{
    std::string _name;
    size_t _health;
    size_t _mana;
    size_t _armour;
    public:
    Character(): _name("unknown"), _health(0), _mana(0), _armour(0)
    {}
    void set_name(std::string name)
    {
        _name = name;
    }
    void set_health(size_t health)
    {
        _health = health;
    }
    void set_mana(size_t mana)
    {
        _mana = mana;
    }
    void set_armour(size_t armour)
    {
        _armour = armour;
    }
};

class Builder
{
    Character c;
    public:
    Builder& set_name(std::string name)
    {
        c.set_name(name);
        return *this;
    }
    Builder& set_health(size_t health)
    {
        c.set_health(health);
        return *this;
    }
    Builder& set_mana(size_t mana)
    {
        c.set_mana(mana);
        return *this;
    }
    Builder& set_armour(size_t armour)
    {
        c.set_armour(armour);
        return *this;
    }
    Character build()
    {
        return c;
    }
};


int main()
{
    Character ch = Builder()
    .set_name("MyHero")
    .set_health(100)
    .set_mana(100)
    .set_armour(100)
    .build();
    
}