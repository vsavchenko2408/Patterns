#include <iostream>

class Prototype
{
    private:
    int m_data;
    public:
    Prototype() : m_data(0)
    {}
    Prototype(int data) : m_data(data)
    {
    }
    int get_data()
    {
        return m_data;
    }
    Prototype* clone()
    {
        return new Prototype(*this);
    }
};

int main()
{
    Prototype obj1(15);
    Prototype* ptr = obj1.clone();
    std::cout << "Data: " << ptr->get_data() << std::endl;
    delete ptr;
}