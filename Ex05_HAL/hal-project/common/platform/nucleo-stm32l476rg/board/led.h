#ifndef LED_H_
#define LED_H_

/**
 * @brief Represents the green LED on the Nucleo board.
 *
 * For a more general interface to access LEDs (project compatibility) use
 * the LedController class.
 */
class Led
{
public:
	void initialize();
	void turnOn();
	void turnOff();
};

#endif
