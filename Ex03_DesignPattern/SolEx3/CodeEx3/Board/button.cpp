#include <iostream>
#include "button.h"

/* Factory Pattern */
void Button::initialize()
{
    state = RELEASED;
    pManager = NULL;
}
void Button::initializeRelations()
{
    //nothing to do here
}

Button::~Button()
{

}

/* SAP Pattern */
void Button::setButtonManager(ToButtonManager* p)
{
    pManager = p;
}

BState Button::checkButtonState()
{
    return state;
}

/* White Box Test Pattern */

void Button::testMe()
{
    if (state==PRESSED)
    {
        state = RELEASED;
        pManager->released();
    }
    else
    {
        state = PRESSED;
        pManager->pressed();
    }
}
