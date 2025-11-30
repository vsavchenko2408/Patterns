#include <iostream>

class Singleton
{
    private:
        Singleton()
        {
            std::cout << "Singleton Created" << std::endl;
        }
        static Singleton* object;
    public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
        static Singleton* get_object()
        {
                if(object == nullptr)
                {
                    object = new Singleton();
                }
                return object;
        }

        void some_doing()
        {
            std::cout << "I something doing!" << std::endl;
        }

};

Singleton* Singleton::object = nullptr;

int main()
{
    Singleton* obj = Singleton::get_object();
    obj->get_object();
    obj->some_doing();
    delete obj;
return 0;
}
