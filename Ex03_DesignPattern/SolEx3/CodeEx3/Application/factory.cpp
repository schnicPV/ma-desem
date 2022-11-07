#include <iostream>
#include "factory.h"


void Factory::initialize()
{
    pManager = NULL;
    pButton = NULL;
}

Factory::~Factory()
{
    delete pButton;
}

void Factory::buildApplication()
{
    //create
    button()->initialize();
    buttonManager()->initialize();
    //build
    button()->initializeRelations();
    buttonManager()->initializeRelations(button());
    //subscribe buttonManager to button
    button()->setButtonManager(buttonManager());
}

ButtonManager* Factory::buttonManager()
{
    if (!pManager) pManager = &ButtonManager::instance();
    return pManager;
}

Button* Factory::button()
{
    if (!pButton) pButton = new Button();
    return pButton;
}
