#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "to_button.h"
#include "to_buttonmanager.h"

class ButtonManager : public ToButtonManager
{
public:
    // Factory pattern
    void initialize();
    void initializeRelations(ToButton*);

    // Singleton pattern
    static ButtonManager& instance();

    // WhiteBox test pattern
    void testMe();

private:
    // Singleton pattern
    ButtonManager();
    ~ButtonManager();
    ButtonManager(ButtonManager&);
    void operator=(ButtonManager&);

    // SAP pattern
    void pressed();
    void released();
    ToButton* pButton;
};

#endif // BUTTONMANAGER_H
