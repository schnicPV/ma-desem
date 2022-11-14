#ifndef FACTORY_H
#define FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include <cassert>
#include "platform-config.h"

class ButtonManager;
class Button;
class Led;
class SimpleDisplay;

/**
 * @brief Provides access to general instances. Initializes and builds the application.
 *
 * The Factory class implements a Singleton pattern. Only one instance of the
 * Factory class is allowed. Use the instance() method to access the internally
 * created instance.
 */
class Factory
{
public:
	void buildApplication();

	static Factory & instance();

	static ButtonManager & buttonManager();
	static Button & button();
	static Led & led();

#ifdef USE_DISPLAY
	static SimpleDisplay & display();
#endif // USE_DISPLAY

protected:
    Factory() = default;
};

#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_buildApplication();                ///< C-Wrapper to Factory::buildApplication() method

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FACTORY_H
