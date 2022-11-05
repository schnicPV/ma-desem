#include <cstddef>
#include "factory.h"

Factory::Factory()
{
    pButton = NULL;
    pManager = NULL;
}

void Factory::initialize()
{
    pButton = new Button();                     // create new Button
    pManager = &ButtonManager::instance();      // define ButtonManager
    pButton->initialize();
    pManager->initialize();
}

void Factory::buildApplication()
{
    pManager->initializeRelations(pButton);
    pButton->setButtonManager(pManager);
}

ButtonManager* Factory::buttonManager()
{
    return pManager;
}

Button* Factory::button()
{
    return pButton;
}
