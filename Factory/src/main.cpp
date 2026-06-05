#include <iostream>

class Enemy
{
    public:
    virtual void Attack(){}
};

class Warrior: public Enemy
{
    public:
    void Attack() override
    {
        std::cout << "Warrior attack!" << std::endl;
    }
};

class Mage: public Enemy
{
    public:
    void Attack() override
    {
        std::cout << "Mage attack!" << std::endl;        
    }
};
class Factory
{
    public:
    Enemy* CreateEnemy(int enemy_type)
    {
        switch(enemy_type)
        {
            case 1:
            return new Warrior;

            case 2:
            return new Mage;

            default:
            return nullptr;
        }
    }
};

int main()
{
    Factory spawner;
    auto war = spawner.CreateEnemy(1);
    auto mage = spawner.CreateEnemy(2);

    war->Attack();
    mage->Attack();
    
    delete war;
    delete mage;



return 0;
}
