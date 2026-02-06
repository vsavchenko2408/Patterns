#include <iostream>

class Player
{
    std::string _name;
    int _hp;
    int _mana;
    int _exp;

    public:
    Player() : _name("Unknown"), _hp(0), _mana(0), _exp(0)
    {}
    Player(std::string name, int hp, int mana, int exp): _name(name), _hp(hp), _mana(mana), _exp(exp) 
    {

    } 

    void set_name(std::string name)
    {
        _name = name;
    }
    void set_hp(int hp)
    {
        _hp = hp;
    }
    void set_mana(int mana)
    {
        _mana = mana;
    }
    void set_exp(int exp)
    {
        _exp = exp;
    }
};

class Builder
{
    Player pl;
    public:

    Builder& name(std::string name)
    {
        pl.set_name(name);
        return *this;
    }
    Builder& hp(int hp)
    {
        pl.set_hp(hp);
        return *this;
    }
    Builder& mana(int mana)
    {
        pl.set_mana(mana);
        return *this;
    }
    Builder& exp(int exp)
    {
        pl.set_exp(exp);
        return *this; 
    }
    Player build()
    {
        return pl;
    }
};
int main()
{
    Player player = Builder()
    .name("Hero")
    .hp(100)
    .mana(10)
    .exp(1000)
    .build();
    

}