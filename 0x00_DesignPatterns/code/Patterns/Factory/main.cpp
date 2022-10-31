#include <iostream>
using namespace std;

class Display
{
private:
    //...
public:
    Display()
    {
        cout <<"Display created" <<endl;
    }
    void initialize() {}
};

class Computer
{
private:
    Display* theDisplay;
public:
    Computer()
    {
        theDisplay = NULL;
        cout <<"Computer created" <<endl;
    }
    void initialize() {}
    void initializeRelations(Display* p)
    {
        theDisplay = p;
    }
};

class Keyboard
{
private:
    Computer* theComputer;
public:
    Keyboard()
    {
        theComputer = NULL;
        cout <<"Keyboard created" <<endl;
    }
    void initialize() {}
    void initializeRelations(Computer* p)
    {
        theComputer = p;
    }
};

class Factory
{
private:
     Keyboard* pKeyboard;
     Computer* pComputer;
     Display* pDisplay;
public:
     Factory()
     {
         pKeyboard = NULL;
         pComputer = NULL;
         pDisplay = NULL;
     }
     ~Factory()
     {
         delete pKeyboard;
         delete pComputer;
         delete pDisplay;
     }
     Keyboard* getKeyboard()
     {
         if (!pKeyboard) pKeyboard = new Keyboard();
         return pKeyboard;
     }
     Computer* getComputer()
     {
         if (!pComputer) pComputer = new Computer();
         return pComputer;
     }
     Display* getDisplay()
     {
         if (!pDisplay) pDisplay = new Display();
         return pDisplay;
     }

     void buildSystem()
     {
         cout << "Initalizing system" <<endl;
         getKeyboard()->initialize();
         getComputer()->initialize();
         getDisplay()->initialize();
         cout << "Setting relations" <<endl;
         getKeyboard()->initializeRelations(pComputer);
         getComputer()->initializeRelations(pDisplay);
         cout << "System is ready" <<endl;
     }
};

int main()
{
    Factory f;
    f.buildSystem();
    //go on
    return 0;
}



