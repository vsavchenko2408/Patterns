#include <iostream>

class Weapon //interface for weapons
{
    public:
    virtual void Attack() = 0;
    virtual ~Weapon() = default;
};

class Sword: public Weapon //strategy 1
{
    public:
    void Attack() override
    {
        std::cout << "Sword attack!" << std::endl;
    }
};

class Bow: public Weapon //strategy 2
{
    public:
    void Attack() override
    {
        std::cout << "Bow attack!" << std::endl;
    }
};

class Staff: public Weapon //strategy 3
{
    public:
    void Attack() override
    {
        std::cout << "Fireball!" << std::endl;
    }
};

class Character
{
    Weapon* _weapon;
    public:
    Character(Weapon* weapon): _weapon(weapon) {}
    void SetWeapon(Weapon* weapon) //change weapon
    {
        _weapon = weapon;
    }
    void PerformAttack() //use weapon
    {
        if(_weapon)
        {
            _weapon -> Attack();
        }
        else
        {
            std::cerr << "You need a weapon for attack!" << std::endl;
        }
    }
};

int main()
{
    Sword sword;
    Bow bow;
    Staff staff;

    Character c(&sword);
    c.PerformAttack();
    c.SetWeapon(&bow);
    c.PerformAttack();
    c.SetWeapon(&staff);
    c.PerformAttack();
}