#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <stdint.h>
#include "xf/xfreactive.h"
#include "button.h"

/**
 * @brief TestBench testing the application by sending button events.
 *
 * State machine diagram: uml/sm-testbench.uxf
 */
class TestBench : public XFReactive
{
public:
	TestBench();
	virtual ~TestBench();

	void initialize();
	void initializeRelations(Button * p);
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
		Timeout_PRESSED_id = 1,	///< Timeout id for button pressed.
		Timeout_WAIT_id = 2		///< Timeout id for wait to next button pressed.
	} eTimeoutId;

	/**
	 * @brief Enumeration used to have a unique identifier for every
	 * state in the state machine.
	 */
	typedef enum
	{
		STATE_UNKOWN = 0,				///< Unknown state
		STATE_INITIAL = 1,				///< Initial state
		STATE_SIM_BUTTON_PRESSED = 2,	///< SIM_BUTTON_PRESSED state
		STATE_SIM_BUTTON_RELEASED = 3	///< SIM_BUTTON_RELEASED state
	} eMainState;

	eMainState _newState;		///< Attribute indicating currently active state

protected:
	const static uint32_t TM_BUTTON_SHORT_PRESSED;	///< Button pressed time for a short pressed (in milliseconds).
	const static uint32_t TM_BUTTON_LONG_PRESSED;	///< Button pressed time for a long pressed (in milliseconds).
	const static uint32_t TM_WAIT;					///< Time to wait between two button pressed (in milliseconds).

	Button * _pButton;
	uint32_t _buttonPressedTimeout;
};

#endif // TESTBENCH_H
