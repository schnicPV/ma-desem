#include <iostream>
#include "buttonmanager.h"

using namespace std;


// Factory pattern
void ButtonManager::initialize()
{

}
void ButtonManager::initializeRelations(ToButton*)
{

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

}

// Singleton pattern
ButtonManager::ButtonManager() {}
ButtonManager::~ButtonManager() {}
ButtonManager::ButtonManager(ButtonManager&) {}
void ButtonManager::operator=(ButtonManager&) {}

// SAP pattern
void ButtonManager::pressed()
{

}

void ButtonManager::released()
{

}
