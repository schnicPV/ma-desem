#ifndef BUTTON_H
#define BUTTON_H

#include "../Interfaces/tobutton.h"
#include "../Interfaces/bstate.h"
#include "../Interfaces/tobuttonmanager.h"

class Button : public ToButton
{
public:
    /* Factory Pattern */
    void initialize();
    void initializeRelations();
    virtual ~Button();

    /* SAP Pattern */
public:
    void setButtonManager(ToButtonManager* p);

private:
    BState checkButtonState();
    ToButtonManager* pManager;

    /* White Box Test Pattern */
public:
    void testMe();

private:
    BState state;
};

#endif // BUTTON_H
