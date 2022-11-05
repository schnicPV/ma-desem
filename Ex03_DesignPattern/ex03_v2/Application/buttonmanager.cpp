#include <iostream>
#include "buttonmanager.h"

using namespace std;


// Factory pattern
void ButtonManager::initialize()
{
    pButton = NULL;
}
void ButtonManager::initializeRelations(ToButton* p)
{
    pButton = p;
}

// Singleton pattern
ButtonManager& ButtonManager::instance()
{
    static ButtonManager instance;
    return instance;
}

// WhiteBox test pattern
void ButtonManager::testMe()
{
    cout << "[MSGE] Start of Button Manager test" << endl;
    pButton->checkButtonState();
    cout << "[MSGE] End of Button Manager test" << endl;
}

// Singleton pattern
ButtonManager::ButtonManager() {}
ButtonManager::~ButtonManager() {}
ButtonManager::ButtonManager(ButtonManager&) {}
void ButtonManager::operator=(ButtonManager&) {}

// SAP pattern
void ButtonManager::pressed()
{
    cout << "[ACTN] Button pressed!" << endl;
}

void ButtonManager::released()
{
    cout << "[ACTN] Button released!" << endl;
}
