#include <iostream>

class Prototype
{
    private:
    int m_data;
    public:
    Prototype() : m_data(0){}
    Prototype(int data): m_data(data) {}
    int get_data(){return m_data;}
    Prototype* clone()
    {
        return new Prototype(*this);
    }
};

int main()
{
    Prototype obj1(10);
    Prototype* clone = obj1.clone();
    std::cout << "Data in clone: " << clone->get_data() << std::endl;
    delete clone;
}