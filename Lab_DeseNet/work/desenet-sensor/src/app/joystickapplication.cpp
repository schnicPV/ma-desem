#include "joystickapplication.h"

using namespace app;

JoystickApplication::JoystickApplication()
    : joystickEventBufferSize(1)                        // initialize buffer size
    , joystickEventBuffer(joystickEventBufferSize)      // call SharedByteBuffer constructor
{
}

void JoystickApplication::onPositionChange(IJoystick::Position position)
{
    memcpy(&joystickEventBuffer, &position, joystickEventBufferSize);
    sensor::AbstractApplication::evPublishRequest(EVID_JOYSTICK, joystickEventBuffer);
}
