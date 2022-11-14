#include "mcu/mcu.h"
#include "trace/trace.h"
#include "main.h"
#include "button.h"

Button::Button()
 : pManager(nullptr),
   state(RELEASED),
   rootState(STATE_INITIAL)
{
}

Button::~Button()
{
}

void Button::initialize()
{
	// Initialize hardware
	initializeHardware();

	// Read actual button state (GPIO state)
	// (It may be pressed already at start up!)
	state = checkButtonState();

	// state machine state
	rootState = STATE_INITIAL;
}

void Button::initializeHardware()
{
	// The blue button of the Nucleo board is on MCU pin PC13.

    // Note: GPIO configuration code is generated by STM32CubeIDE
    //       and is located in the 'Core/Src/main.c' file.
    //
    //       Double-click on the hal-project.ioc file for more details.
    //
    // This means that in this method no additional hardware initialization
    // code must be called. It is already implemented in the MX_GPIO_Init()
    // function in the 'Core/Src/main.c' file and also called in the main()
    // function!
}

void Button::initializeRelations(ToButtonManager * p)
{
	setButtonManager(p);
}

int Button::pollInterval = 20;	// [ms]

void Button::setButtonManager(ToButtonManager * p)
{
	pManager = p;
}

void Button::start()
{
	startBehavior();	// Start state machine
}

BState Button::checkButtonState()
{
	// TODO: Implement method accordingly.
	bool state_released = readGpio();
	if(state_released)
	{
		return RELEASED;
	}
	else
	{
		return PRESSED;
	}
}

bool Button::readGpio()
{
    // TODO: Call HAL_GPIO_ReadPin(...) function to get actual GPIO level of the button.
	GPIO_PinState current_state = HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
	switch(current_state)
	{
	case GPIO_PIN_RESET:
		return false;
	case GPIO_PIN_SET:
		return true;
	default:
		Trace::outln("[ERROR] undefined GPIO Pin read!");
		return false;
	}
}

EventStatus Button::processEvent()
{
    // Do we handle the event?
    EventStatus result = EventStatus::Unknown;

    // TODO: Implement state-machine here.
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
			if (ev->getEventType() == IXFEvent::Timeout &&
				ev->getId() == tmPollButton)
			{
				rootState = STATE_GET_BSTATE;
			}
			break;
		case STATE_GET_BSTATE:
			// if the timeout wins
			if (ev->getEventType() == IXFEvent::NullTransition)
			{
				rootState = STATE_SEND_MANAGER;
			}
			break;
		case STATE_SEND_MANAGER:
			if (ev->getEventType() == IXFEvent::NullTransition)
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
				Trace::outln("-- button start poll timeout -- ");
				getThread()->scheduleTimeout(tmPollButton, pollInterval, this);
				break;
			case STATE_GET_BSTATE:
				Trace::outln("-- button get button state -- ");
				state = checkButtonState();								// check the button state adn store it into 'state'
				getThread()->unscheduleTimeout(tmPollButton, this);		// stop the poll timeout
				GEN(XFNullTransition()); 								// generate a default transition to get out of here
				break;
			case STATE_SEND_MANAGER:
				Trace::outln("-- button send state to manager -- ");
				// send states to button manager
				if(state == PRESSED)
				{
					pManager->pressed();
				}
				if(state == RELEASED)
				{
					pManager->released();
				}
				// generate a default transition to get out of here
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
