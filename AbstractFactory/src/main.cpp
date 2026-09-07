#include <iostream>

class Enemy
{
    public: 
    virtual void Attack() = 0;
    virtual ~Enemy() = default;
};

class Weapon
{
    public:
    virtual void Use() = 0;
    virtual ~Weapon() = default;
};

class Mage: public Enemy
{
    public:
    void Attack() override
    {
        std::cout << "Fireball!" << std::endl;
    }
};

class Warrior: public Enemy
{
    public:
    void Attack() override
    {
        std::cout << "Sword!" << std::endl;
    }
};

class Archer: public Enemy
{
    public:
    void Attack() override
    {
        std::cout << "Arrow!" << std::endl;
    }
};

class Sword: public Weapon
{
    public:
    void Use() override
    {
        std::cout << "Sword" << std::endl;
    }
};

class Staff: public Weapon
{
    public:
    void Use() override
    {
        std::cout << "Staff" << std::endl;
    }
};

class Bow: public Weapon
{
    public:
    void Use() override
    {
        std::cout << "Bow" << std::endl;
    }
};

class EnemyFactory //Abstract Factory
{
    public:
    virtual Enemy* CreateEnemy() = 0;
    virtual Weapon* CreateWeapon() = 0;
    virtual ~EnemyFactory() = default;
};

class MageFactory : public EnemyFactory
{
    public:
    Enemy* CreateEnemy() override
    {
        return new Mage();
    }
    Weapon* CreateWeapon() override
    {
        return new Staff();
    }
};

class WarriorFactory: public EnemyFactory
{
    public:
    Enemy* CreateEnemy() override
    {
        return new Warrior();
    }
    Weapon* CreateWeapon() override
    {
        return new Sword();
    }
};

class ArcherFactory: public EnemyFactory
{
    public:
    Enemy* CreateEnemy() override
    {
        return new Archer();
    }
    Weapon* CreateWeapon() override
    {
        return new Bow();
    }
};

void SpawnAndAttack(EnemyFactory* factory)
{
    Enemy* enemy = factory->CreateEnemy();
    Weapon* weapon = factory->CreateWeapon();
    enemy->Attack();
    weapon->Use();
    delete enemy;
    delete weapon;
}
int main()
{
    EnemyFactory* factory = new MageFactory();
    SpawnAndAttack(factory);

    factory = new WarriorFactory();
    SpawnAndAttack(factory);

    factory = new ArcherFactory();
    SpawnAndAttack(factory);

    delete factory;
}