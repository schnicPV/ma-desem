#ifndef BUTTON_H
#define BUTTON_H

#include "to_button.h"
#include "to_buttonmanager.h"

class Button : public ToButton
{
public:
    // Factory pattern
    void initialize();
    void initializeRelations();

    // SAP pattern
    void setButtonManager(ToButtonManager*);

    // WhiteBox test pattern
    void testMe();

private:
    // SAP pattern
    virtual BState checkButtonState();
    ToButtonManager* pManager;

    BState state;
};

#endif // BUTTON_H
