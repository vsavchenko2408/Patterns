#include <iostream>

class Enemy
{
    public:
    virtual void attack()
    {
        std::cout << "Attack!" << std::endl;
    }
    virtual ~Enemy()
    {
    } 
};

class Sceleton: public Enemy
{
    public:
    void attack() override
    {
         std::cout << "Sceleton Attacked!" << std::endl;       
    }
};

class Zombie: public Enemy
{
    public:
        void attack() override
    {
        std::cout << "Zombie Attacked!" << std::endl;
    }
};

class Vampire: public Enemy
{
    public:
    void attack() override
    {
        std::cout << "Vampire Attacked!" << std::endl;
    }
};


class Factory
{
    public:
    virtual Enemy* create_enemy() = 0;

    virtual ~Factory()
    {}
};

class SceletonFactory: public Factory
{
    public:
    Enemy* create_enemy() override
    {
        return new Sceleton();
    }
};

class ZombieFactory: public Factory
{
    public:
    Enemy* create_enemy() override
    {
        return new Zombie();
    }
};

class VampireFactory: public Factory
{
    public:
    Enemy* create_enemy() override
    {
        return new Vampire();
    }
};



int main()
{
    Factory* factory = new SceletonFactory();
    Enemy* sceleton = factory->create_enemy();
    sceleton->attack();
    delete sceleton;
    delete factory;

    factory = new VampireFactory();
    Enemy* vampire = factory->create_enemy();
    vampire->attack();
    delete factory;
    delete vampire;

}