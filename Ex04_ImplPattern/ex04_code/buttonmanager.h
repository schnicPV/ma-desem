#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "interface.h"
#include "xf/xfreactive.h"

class ButtonManager : public ToButtonManager, public XFReactive
{
    friend class Factory;

public:
    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButton * p);
    /* Singleton Pattern */
    static ButtonManager & instance();


private:
    /* Factory Pattern */
    ButtonManager();
    ButtonManager(ButtonManager &);
    void operator=(ButtonManager &);
    virtual ~ButtonManager();

    /* SAP Pattern */
    void pressed();
    void released();

    /* State machine pattern, from the XFReactive interface */
    virtual EventStatus processEvent(); // This is the state machine

    enum evID {evPressed, evReleased};      // These are the event ids
    enum tmID {tmLongPressed};              // This is the timeout id
    enum smState {STATE_INITIAL, STATE_WAIT, STATE_PRESSED,
                  STATE_CLICK, STATE_LONG}; // These are the state ids
    static int longPressTimeout;

    smState rootState;

public:
    /* White Box Test Pattern */
    void testMe();

    /* State machine pattern */
    void start();

private:
    /* SAP pattern */
    ToButton * pButton;
};
#endif // BUTTONMANAGER_H
