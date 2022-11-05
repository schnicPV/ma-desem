#include <iostream>
#include "button.h"

using namespace std;

//constructor
Button::Button() {}

// Factory pattern
void Button::initialize()
{
    state = RELEASED;
    pManager = NULL;
}
void Button::initializeRelations()
{
    // unused
}

// SAP pattern
void Button::setButtonManager(ToButtonManager* p)
{
    pManager = p;
}

// WhiteBox test pattern
void Button::testMe()
{
    cout << "[MSGE] Start of Button test" << endl;
    if(checkButtonState() == PRESSED)
    {
        state = RELEASED;
        pManager->released();
    }
    else
    {
        state = PRESSED;
        pManager->pressed();
    }
    cout << "[INFO] New state of button is: " << enum2str(state) << endl;
    cout << "[MSGE] End of Button test" << endl;
}

// SAP pattern
BState Button::checkButtonState()
{
    cout << "[INFO] Current state of button is: " << enum2str(state) << endl;
    return state;
}
