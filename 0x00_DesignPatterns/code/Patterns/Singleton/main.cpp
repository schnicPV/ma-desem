#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    void doSomething()
    {
        cout <<"Hello, I am " <<this <<endl;
    }

private:
    //this will prevent creation of instances
    Singleton() {}
    Singleton(const Singleton&) {}
    void operator=(const Singleton&) {}
};

int main()
{
    Singleton::getInstance().doSomething();
    Singleton::getInstance().doSomething();
    Singleton::getInstance().doSomething();

    // Singleton s;    //this will not work
    return 0;
}


