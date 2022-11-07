#include <iostream>
using namespace std;

#include "buttonmanager.h"
#include "../Interfaces/bstate.h"

/* Factory Pattern */
void ButtonManager::initialize()
{
    pButton = NULL;
}
void ButtonManager::initializeRelations(ToButton* p)
{
    pButton = p;
}

ButtonManager::~ButtonManager()
{

}

/* Singleton Pattern */

ButtonManager& ButtonManager::instance()
{
    static ButtonManager bm;
    return bm;
}

ButtonManager::ButtonManager() {}

ButtonManager::ButtonManager(ButtonManager&) {}

void ButtonManager::operator=(ButtonManager&) {}

/* SAP Pattern */
void ButtonManager::pressed()
{
    cout <<"Button pressed" <<endl;
}

void ButtonManager::released()
{
    cout <<"Button released" <<endl;
}

/* White Box Test Pattern */
void ButtonManager::testMe()
{
    cout << "State of button --> ";
    if (pButton->checkButtonState() == PRESSED)
    {
        cout << "pressed" <<endl;
    }
    else
    {
        cout << "released" <<endl;
    }
}
