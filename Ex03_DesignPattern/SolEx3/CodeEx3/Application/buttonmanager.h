#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "../Interfaces/tobuttonmanager.h"
#include "../Interfaces/tobutton.h"

class ButtonManager : public ToButtonManager
{
public:
    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButton* p);
    virtual ~ButtonManager();

    /* Singleton Pattern */
public:
    static ButtonManager& instance();

private:
    ButtonManager();
    ButtonManager(ButtonManager&);
    void operator=(ButtonManager&);

    /* SAP Pattern */
    void pressed();
    void released();

    /* White Box Test Pattern */
public:
    void testMe();

private:
    ToButton* pButton;
};

#endif // BUTTONMANAGER_H
