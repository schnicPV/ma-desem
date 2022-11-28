#ifndef FACTORY_H
#define FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include <cassert>
#include "platform-config.h"
#include "desenet/sensor/net.h"
#include "board/interfaces/imonochromedisplay.h"
#include "app/accelerometerapplication.h"
#include "board/accel/accelerometer.h"
#include "clockwork/clockwork.h"

using desenet::sensor::Net;

#ifdef TC_MESHSIM
    class MeshSimBoard;		// Class making the Olimex board view of the simulator

    extern desenet::SlotNumber __SLOT_NUMBER;
    extern QString __RESOURCE_PATH;
#endif // TC_MESHSIM
class SimpleDisplay;

// Forward declaration of class(es) in namespace board
namespace board {
    class LedController;
}

namespace app {

/**
 * @brief Provides access to general instances. Initializes and builds the application.
 */
class Factory
{
public:
    Factory(int argc, char ** argv);

    void buildApplication();

    static Factory & instance() { assert(_pInstance); return *_pInstance; }

#ifdef TC_MESHSIM
    MeshSimBoard & meshSimBoard() const;
#endif // TC_MESHSIM

    app::AccelerometerApplication & accelerometerApplication() const;
    board::Accelerometer & accelerometer() const;

    Net & net() const;
    Clockwork & clockwork() const;
    board::LedController & ledController() const;

#ifdef USE_DISPLAY
    SimpleDisplay & display();
#endif // USE_DISPLAY

protected:
    static Factory * _pInstance;
};

} // namespace app
#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_init(int argc, char ** argv);      ///< C-Wrapper to Factory::init() method
void Factory_buildApplication();                ///< C-Wrapper to Factory::buildApplication() method

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // FACTORY_H
