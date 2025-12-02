#include <iostream>

class Singleton
{
    private:
        Singleton()
        {
        std::cout << "Singleton is make!" << std::endl;
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
        void something_doing()
        {
            std::cout << "Some work!" << std::endl;
        }
};
    Singleton* Singleton::object = nullptr;
int main()
{
   Singleton* obj = Singleton::get_object(); 
   obj->something_doing();


   delete obj;
}