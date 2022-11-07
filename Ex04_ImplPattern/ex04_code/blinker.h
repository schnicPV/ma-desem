#ifndef BLINKER_H
#define BLINKER_H

#include "stdint.h"
#include "xf/xfreactive.h"

/**
 * @brief Blinker outputs regularly a message to the output window.
 *
 * State machine diagram: uml/sm-blinker.uxf
 */
class Blinker : public XFReactive
{
public:
	Blinker();
	virtual ~Blinker();

	void initialize(uint32_t blinkInterval = 1000);
	void start();

	// XFReactive overrides
protected:
	virtual EventStatus processEvent();		///< Implements the state machine.

	// State machine declarations
protected:
	/**
	 * @brief Timeout identifier(s) for this state machine.
	 */
	typedef enum
	{
		Timeout_BLINK_id = 1	///< Timeout id for BLINK state
	} eTimeoutId;

	/**
	 * @brief Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_UNKOWN = 0,		///< Unknown state
		STATE_INITIAL = 1,		///< Initial state
		STATE_WAIT = 2,			///< WAIT state
		STATE_BLINK = 3			///< BLINK state
	} eMainState;

	eMainState _newState;		///< Attribute indicating currently active state

protected:
	uint32_t _blinkInterval;
};

#endif // BLINKER_H
