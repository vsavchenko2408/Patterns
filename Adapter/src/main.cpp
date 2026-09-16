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
    MageAdapter adapter(m);
    Game game;
    game.Start(adapter);


    return 0;
}