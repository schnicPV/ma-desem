#include "joystickapplication.h"

using namespace app;


/**
 * @brief constructor creates the event buffer with the initial size
 */
JoystickApplication::JoystickApplication()
    : joystickEventBufferSize(1)                        // initialize buffer size
    , joystickEventBuffer(joystickEventBufferSize)      // call SharedByteBuffer constructor
{
}


/**
 * @brief destructor (unused)
 */
JoystickApplication::~JoystickApplication() {}

/**
 * @brief   virtual method which is called when the joystick position has changed
 *          (must be implemented due to definition in IJoystickObserver)
 * @param   position    the recorded position change
 *                      from IJoystick :    Invalid	= 0x00
 *                                          Center 	= 0x01
 *                                          Left 	= 0x02
 *                                          Right	= 0x04
 *                                          Up		= 0x08
 *                                          Down	= 0x10
 *                                          Pressed = 0x20
 * @return  void
*/
void JoystickApplication::onPositionChange(IJoystick::Position position)
{
    memcpy(&joystickEventBuffer, &position, joystickEventBufferSize);
    sensor::AbstractApplication::evPublishRequest(EVID_JOYSTICK, joystickEventBuffer);
}
