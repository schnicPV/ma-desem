#include <cstddef>
#include "factory.h"

Factory::Factory()
{
    pButton = NULL;
    pManager = NULL;
}

void Factory::initialize()
{
    pButton = new Button();
    pManager = &ButtonManager::instance();
}

void Factory::buildApplication()
{

}

ButtonManager* Factory::buttonManager()
{
    return pManager;
}

Button* Factory::button()
{
    return pButton;
}
