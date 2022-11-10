#include <iostream>
#include "buttonmanager.h"
#include "xf/xfevent.h"

using namespace std;

void ButtonManager::initialize()
{
    pButton = nullptr;
    rootState = STATE_INITIAL;
}

void ButtonManager::initializeRelations(ToButton * p)
{
    pButton = p;
}

int ButtonManager::longPressTimeout = 1000;

ButtonManager & ButtonManager::instance()
{
    static ButtonManager bm;
    return bm;
}

ButtonManager::ButtonManager()
{}

ButtonManager::ButtonManager(ButtonManager &)
{}

void ButtonManager::operator=(ButtonManager &)
{}

ButtonManager::~ButtonManager()
{}

void ButtonManager::pressed()
{
    cout <<"Button pressed" <<endl;
    //create the pressed event
    XFEvent* ev = new XFEvent(evPressed, this);
    //fire the event
    this->pushEvent(ev);
}

void ButtonManager::released()
{
    cout <<"Button released" <<endl;
    //create the released event
    XFEvent* ev = new XFEvent(evReleased, this);
    //fire the event
    this->pushEvent(ev);
}

EventStatus ButtonManager::processEvent()
{
    // will we handle the event ?
    EventStatus result = EventStatus::Unknown;
    // get the actual event
    const IXFEvent* ev = this->getCurrentEvent();

    // save the current state
    smState lastState = rootState;

    // the transition switch
    switch (rootState)
    {
        case STATE_INITIAL:
            if (ev->getEventType() == IXFEvent::Initial)
            {
                rootState = STATE_WAIT;
            }
            break;
        case STATE_WAIT:
            //put your code here
            if((ev->getEventType() == IXFEvent::Event) && (ev->getId() == evPressed))
            {
                rootState = STATE_PRESSED;
            }

            break;
        case STATE_PRESSED:
            // if the timeout wins
            //put your code here
            if((ev->getEventType() == IXFEvent::Timeout) && (ev->getId() == tmLongPressed))
            {
                rootState = STATE_LONG;
            }

            // if the released event wins
            //put your code here
            if((ev->getEventType() == IXFEvent::Event) && (ev->getId() == evReleased))
            {
                rootState = STATE_CLICK;
            }
            break;
        case STATE_CLICK:
            //put your code here
            if(ev->getEventType() == IXFEvent::NullTransition)
            {
                rootState = STATE_WAIT;
            }
            break;
        case STATE_LONG:
           //put your code here
            if(ev->getEventType() == IXFEvent::NullTransition)
            {
                rootState = STATE_WAIT;
            }
            break;
    }

    // the action switch
    if (lastState != rootState)
    {
        result = EventStatus::Consumed;
        switch (rootState)
        {
            case STATE_INITIAL:
            break;
            case STATE_WAIT:
                cout <<"-- button manager waiting -- " <<endl;
                break;
            case STATE_PRESSED:
                cout <<"-- button manager sees a button pressed -- " <<endl;
                /* start the long pressed timeout
                 */
                getThread()->scheduleTimeout(tmLongPressed, longPressTimeout, this);
                break;
            case STATE_CLICK:
                cout <<"-- button manager sees a button clicked -- " <<endl;
                /* we must stop the long pressed timeout
                */
                //put the stop timeoutcode here
                getThread()->unscheduleTimeout(tmLongPressed, this);

                // generate a default transition to get out of here
                GEN(XFNullTransition());
                break;
            case STATE_LONG:
                cout <<"-- button manager sees a long button press -- " <<endl;
                // generate a default transition to get out of here
                //put the generate NULLTRANSITION code here
                GEN(XFNullTransition());
                break;
        }
    }
    else
    {
        result = EventStatus::NotConsumed;
    }
    return result;
}

void ButtonManager::testMe()
{
    cout << "State of button --> ";
    if (pButton->checkButtonState() == PRESSED)
    {
        cout << "pressed" <<endl;
    }
    else
    {
        cout << "released" <<endl;
    }
}

void ButtonManager::start()
{
    this->startBehavior();
}

