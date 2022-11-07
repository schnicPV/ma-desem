#include "testbench.h"

const uint32_t TestBench::TM_BUTTON_SHORT_PRESSED = 200;
const uint32_t TestBench::TM_BUTTON_LONG_PRESSED = 3000;
const uint32_t TestBench::TM_WAIT = 5000;

TestBench::TestBench()
 : _newState(STATE_INITIAL),
   _pButton(nullptr),
   _buttonPressedTimeout(TM_BUTTON_LONG_PRESSED)
{
}

TestBench::~TestBench()
{

}

void TestBench::initialize()
{

}

void TestBench::initializeRelations(Button * p)
{
    _pButton = p;
}

void TestBench::start()
{
    startBehavior();
}

EventStatus TestBench::processEvent()
{
    eEventStatus eventStatus = EventStatus::Unknown;
    const eMainState lastState = _newState;

    // Action on transition switch
    switch (lastState)
    {
    case STATE_INITIAL:
        {
            if (getCurrentEvent()->getEventType() == IXFEvent::Initial)
            {
                _newState = STATE_SIM_BUTTON_PRESSED;

                eventStatus = EventStatus::Consumed;
            }
        }
        break;
    case STATE_SIM_BUTTON_PRESSED:
        {
            if (getCurrentEvent()->getEventType() == IXFEvent::Timeout &&
                getCurrentTimeout()->getId() == Timeout_PRESSED_id)
            {
                _newState = STATE_SIM_BUTTON_RELEASED;

                eventStatus = EventStatus::Consumed;
            }
        }
        break;
    case STATE_SIM_BUTTON_RELEASED:
        {
        if (getCurrentEvent()->getEventType() == IXFEvent::Timeout &&
            getCurrentTimeout()->getId() == Timeout_WAIT_id)
        {
                _newState = STATE_SIM_BUTTON_PRESSED;

                eventStatus = EventStatus::Consumed;
            }
        }
        break;
    default:
        break;
    }

    if (lastState != _newState)
    {
        // Action on entry switch
        switch (_newState)
        {
        case STATE_SIM_BUTTON_PRESSED:
            {
                _buttonPressedTimeout = (_buttonPressedTimeout == TM_BUTTON_SHORT_PRESSED) ? TM_BUTTON_LONG_PRESSED : TM_BUTTON_SHORT_PRESSED;

                getThread()->scheduleTimeout(Timeout_PRESSED_id, _buttonPressedTimeout, this);

                printf("TestBench: Simulating button pressed\n");
                _pButton->testMe();
            }
            break;
        case STATE_SIM_BUTTON_RELEASED:
            {
                getThread()->scheduleTimeout(Timeout_WAIT_id, TM_WAIT, this);

                printf("TestBench: Simulating button released\n");
                _pButton->testMe();
            }
            break;
        default:
            break;
        }
    }

    return eventStatus;
}
