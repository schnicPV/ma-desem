#ifndef BUTTON_H
#define BUTTON_H

#include "platform-config.h"
#include "xf/xfreactive.h"
#include "button-interface.h"

/**
 * @brief Button class representing blue button (USR button) on the Nucleo board.
 */
class Button : public ToButton,
			   public XFReactive
{
public:
	Button();
    virtual ~Button();

    /* Factory Pattern */
    void initialize();
    void initializeRelations(ToButtonManager * p);

    /* SAP Pattern */
    void setButtonManager(ToButtonManager * p);

    void start();							///< Starts the state-machine.

protected:
    void initializeHardware();				///< Initializes hardware needed by this class.
    virtual EventStatus processEvent(); 	///< Implements the state machine for this class.

private:
    BState checkButtonState();				///< Returns the button state based on the actual GPIO state.
    bool readGpio();						///< Returns true if the GPIO is currently set to '1', false otherwise.

private:
    ToButtonManager* pManager;			///< Pointer to button observer.
    BState state;						///< Holds the previous read button state.
};

#endif // BUTTON_H
