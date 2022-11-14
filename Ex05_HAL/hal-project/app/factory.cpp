#include "platform-config.h"
#include "board/board.h"
#include "trace/trace.h"
#include "app/buttonmanager.h"
#include "board/button.h"
//#include "board/display/simpledisplay.h"
#include "factory.h"

void Factory::buildApplication()
{
	board::initialize();	// Initialize board specific stuff

	//
	// Initialize objects
	//
	led().initialize();
	button().initialize();
	buttonManager().initialize();
#ifdef USE_DISPLAY
	display().initialize();
#endif // USE_DISPLAY

	//
	// Initialize relations
	//
	buttonManager().initializeRelations(&button(), &led());
	button().initializeRelations(&buttonManager());

#ifdef USE_DISPLAY
	// Draw title on display
	display().clear();
	display().drawText("Series", 22, 2);
	display().drawLine({1, 36}, {SimpleDisplay::X_MAX - 1, 36});
	display().drawText("HAL", 34, 5);
#endif // USE_DISPLAY

	//
	// Start state machines
	//
	buttonManager().start();
	button().start();
}

//static
Factory & Factory::instance()
{
    static Factory theInstance;
    return theInstance;
}

//static
ButtonManager & Factory::buttonManager()
{
	static ButtonManager bm;

	return bm;
}

//static
Button & Factory::button()
{
	static Button button;

	return button;
}

//static
Led & Factory::led()
{
	static Led led;

	return led;
}

#ifdef USE_DISPLAY
// static
SimpleDisplay & Factory::display()
{
	static SimpleDisplay display;

	return display;
}
#endif // USE_DISPLAY

void Factory_buildApplication()
{
    Factory::instance().buildApplication();
}
