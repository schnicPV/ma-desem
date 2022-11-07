#ifndef BUTTON_H
#define BUTTON_H

#include "interface.h"

class Button : public ToButton
{
public:
    virtual ~Button();

    /* Factory Pattern */
    void initialize();
    void initializeRelations();

    /* SAP Pattern */
    void setButtonManager(ToButtonManager * p);

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
