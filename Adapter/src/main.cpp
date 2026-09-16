#include <iostream>

class Mage
{
    int _damage;
    public:
    Mage(){}
    Mage(int damage):_damage(damage){}
    void OldAttack()
    {
        std::cout << "Damaged: " << _damage << " points." << std::endl;
    }
};

class Warrior
{
    int _damage;
    public:
    Warrior(){}
    Warrior(int damage):_damage(damage){}
    void NewAttack()
    {
        std::cout << "Damaged: " << _damage << " points." << std::endl;
    }
};

class Attacker
{
    public:
    virtual void Attack() = 0;
    virtual ~Attacker() = default;
};

class MageAdapter: public Attacker
{
    Mage& _mage;
    public:
    MageAdapter(Mage& mage):_mage(mage){}
    void Attack() override
    {
        _mage.OldAttack();
    }
};

class WarriorAdapter: public Attacker
{
    Warrior& _warrior;
    public:
    WarriorAdapter(Warrior& warrior):_warrior(warrior){}
    void Attack() override
    {
        _warrior.NewAttack();
    }
};

class Game
{
    public:
    Game(){}
    void Start(Attacker& a)
    {
        a.Attack();
    }
};

int main()
{

    Mage m(15);
    Warrior w(20);
    MageAdapter madapter(m);
    WarriorAdapter wadapter(w);
    Game game;
    game.Start(madapter);
    game.Start(wadapter);


    return 0;
}