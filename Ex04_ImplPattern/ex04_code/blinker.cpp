#include <stdlib.h>
#include "blinker.h"

Blinker::Blinker()
 : _newState(STATE_INITIAL),
   _blinkInterval(1000)
{
}

Blinker::~Blinker()
{
}

void Blinker::initialize(uint32_t blinkInterval /* = 1000 */)
{
	_blinkInterval = blinkInterval;
}

void Blinker::start()
{
	startBehavior();	// Start state machine
}

EventStatus Blinker::processEvent()
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
				_newState = STATE_WAIT;

				eventStatus = EventStatus::Consumed;
			}
		}
		break;
	case STATE_WAIT:
		{
			if (getCurrentEvent()->getEventType() == IXFEvent::Timeout &&
				getCurrentTimeout()->getId() == Timeout_BLINK_id)
			{
				_newState = STATE_BLINK;

				eventStatus = EventStatus::Consumed;
			}
		}
		break;
	case STATE_BLINK:
		{
			if (getCurrentEvent()->getEventType() == IXFEvent::NullTransition)
			{
				_newState = STATE_WAIT;

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
		case STATE_WAIT:
			{
				getThread()->scheduleTimeout(Timeout_BLINK_id, _blinkInterval, this);
			}
			break;
		case STATE_BLINK:
			{
				GEN(XFNullTransition());

				printf("blink\n");
			}
			break;
		default:
			break;
		}
	}

	return eventStatus;
}
