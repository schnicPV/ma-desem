#ifndef BUTTONMANAGER_H
#define BUTTONMANAGER_H

#include "xf/xfreactive.h"
#include "board/button-interface.h"
#include "board/led.h"

/**
 * @brief ButtonManager is responsible to detect button clicked and long pressed.
 */
class ButtonManager : protected XFReactive,
					  public ToButtonManager
{
    friend class Factory;

public:
    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButton * p, Led * l);
    /* Singleton Pattern */
    static ButtonManager & instance();

    /* State machine pattern */
    void start();

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

    enum evID {evPressed, evReleased};   		   // These are the event ids
    enum tmID {tmLongPressed, tmLed};              // This is the timeout id
    enum smState {STATE_INITIAL, STATE_WAIT, STATE_PRESSED,
                  STATE_CLICK, STATE_LONG}; // These are the state ids
    static int longPressTimeout;

    smState rootState;

private:
    /* SAP pattern */
    ToButton * pButton;
};
#endif // BUTTONMANAGER_H
