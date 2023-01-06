#ifndef JOYSTICKAPPLICATION_H
#define JOYSTICKAPPLICATION_H

#include "platform-config.h"
#include "desenet/sensor/abstractapplication.h"
#include "common/platform/platform-common/board/interfaces/ijoystickobserver.h"

namespace app
{
    class JoystickApplication : public IJoystickObserver
                              , public desenet::sensor::AbstractApplication
    {
    public:
        JoystickApplication();
        ~JoystickApplication();
        void onPositionChange(IJoystick::Position position);    // must be implemented due to virtual definition in IJosytickObserver

    private:
        const uint8_t joystickEventBufferSize;                  ///< the size of the event buffer
        SharedByteBuffer joystickEventBuffer;                   ///< the event buffer which stores the joystick positions
    };
}

#endif // JOYSTICKAPPLICATION_H
