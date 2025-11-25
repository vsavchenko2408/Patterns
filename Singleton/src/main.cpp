#include <iostream>

class Singleton
{
    private:
    static Singleton* object;
    Singleton()
    {
        std::cout << "Object created" << std::endl;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    public:

    static Singleton* create_obj()
    {
        if(object == nullptr)
        {
            object = new Singleton();
        }
        return object;
    }

    template<typename T>
    void some_work(T& work)
    {
        std::cout << "Some work with: " << work << std::endl;
    }
};

    Singleton* Singleton::object = nullptr;

int main()
{
    Singleton* obj = Singleton::create_obj();
    obj->some_work("some data");    
}