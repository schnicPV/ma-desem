#ifndef BUTTON_H
#define BUTTON_H

#include "../Interfaces/to_button.h"
#include "../Interfaces/to_buttonmanager.h"

class Button : public ToButton
{
public:
    Button();

    // Factory pattern
    void initialize();
    void initializeRelations();

    // SAP pattern
    void setButtonManager(ToButtonManager* p);

    // WhiteBox test pattern
    void testMe();

private:
    // SAP pattern
    virtual BState checkButtonState();
    ToButtonManager* pManager;

    BState state;
};

#endif // BUTTON_H
