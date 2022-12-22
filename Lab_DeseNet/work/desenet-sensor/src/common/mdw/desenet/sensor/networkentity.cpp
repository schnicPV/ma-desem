#include <assert.h>
#include <array>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include "platform-config.h"
#include "board/ledcontroller.h"
#include "desenet/frame.h"
#include "desenet/beacon.h"
#include "desenet/timeslotmanager.h"
#include "abstractapplication.h"
#include "networkentity.h"

using std::array;
using std::list;
using std::map;
using std::make_pair;
using std::bind;
using std::pair;
using std::vector;

using desenet::sensor::NetworkEntity;

#define SV_EPDU_TYPE 0
#define EV_EPDU_TYPE 1

NetworkEntity * NetworkEntity::_pInstance(nullptr);		// Instantiation of static attribute

NetworkEntity::NetworkEntity()
 : _pTimeSlotManager(nullptr),
   _pTransceiver(nullptr)
{
    assert(!_pInstance);		// Only one instance allowed
    _pInstance = this;
}

NetworkEntity::~NetworkEntity()
{
}

void NetworkEntity::initialize()
{
}

void NetworkEntity::initializeRelations(ITimeSlotManager & timeSlotManager, NetworkInterfaceDriver & transceiver)
{
    _pTimeSlotManager = &timeSlotManager;
    _pTransceiver = &transceiver;

    // TODO: Add additional initialization code here
    mPDU = MultiPDU();
    timeSlotManager.initializeRelations(*this);     // initialize the TimeSlotMAnager class so that there inside the _pObserver is initialized with (*this), because NetworkEntity IS ans observer

     // Set the receive callback between transceiver and network. Bind this pointer to member function
    transceiver.setReceptionHandler(std::bind(&NetworkEntity::onReceive, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

/**
 * This method does not automatically create an instance if there is none created so far.
 * It is up the the developer to create an instance of this class prior to access the instance() method.
 */
//static
NetworkEntity & NetworkEntity::instance()
{
    assert(_pInstance);
    return *_pInstance;
}

SlotNumber NetworkEntity::slotNumber() const
{
    return timeSlotManager().slotNumber();
}

/**
 * Called by the NetworkInterfaceDriver (layer below) after reception of a new frame
 */
void NetworkEntity::onReceive(NetworkInterfaceDriver & driver, const uint32_t receptionTime, const uint8_t * const buffer, size_t length)
{
    (void)(driver);
    (void)(receptionTime);
    Frame frame = Frame::useBuffer(buffer, length);

    // TODO: Add your code here
    if(frame.type() == FrameType::Beacon)
    {
        // create new beacon
        Beacon* pBcon = new Beacon(frame);

        // start timer for time slots
        _pTimeSlotManager->onBeaconReceived(pBcon->slotDuration());

        // notify all applications
        int dummy_cnt = 0;
        for(auto list_elm = appSyncList.begin(); list_elm != appSyncList.end(); list_elm++)     // parse a list acc. to example on cplusplus.com
        {
            (*list_elm)->svSyncIndication(receptionTime);
            dummy_cnt++;
        }

        // publish request for all applications
        mPDU.clear();
        size_t writtenByteLength = 0;
        for(SvGroup idx = 0; idx < MAX_GROUP_NBR; idx++)
        {
            if(appPubArray[idx] != nullptr)
            {
                SharedByteBuffer buffer = SharedByteBuffer::proxy(mPDU.getValidStart(), mPDU.getRemainingLength());
                writtenByteLength = appPubArray[idx]->svPublishIndication(idx, buffer);
                if(writtenByteLength > 0)
                {
                    mPDU.addEPDUheader(SV_EPDU_TYPE, idx, writtenByteLength, mPDU.currentDataByteIdx);      // here the currentDataByteIndex should be 2 because of clear() above
                    mPDU.currentDataByteIdx = mPDU.currentDataByteIdx + writtenByteLength + 1;              // + 1 because the data is set 1 after ePDU header (see line above)
                    mPDU.ePDUcnt++;
                    mPDU.updateEPDUcnt();
                    mPDU.updateHeaderLength(mPDU.currentDataByteIdx);
                }
            }
        }
//        (*_pTransceiver) << mPDU;   // send MPDU to transceiver

        //destroy beacon at the end ?
//        delete(pBcon);
    }
    else if(frame.type() == FrameType::MPDU)
    {
        // do something
    }
    else
    {
        return;     // invalid frame received
    }
//    ledController().flashLed(0);    // this flashes the LED on the simulated board
}

board::LedController & NetworkEntity::ledController() const
{
    return board::LedController::instance();
}

// add new 'AbstractApplication' pointer to the (synchronisation) list
void NetworkEntity::svSyncRequest(AbstractApplication* pAbsApp)
{
    appSyncList.push_back(pAbsApp);
}

// add new 'AbstractApplication' pointer to the publisher list, only if the SV Group is free
bool NetworkEntity::svPublishRequest(AbstractApplication* pAbsApp, SvGroup group)
{
    if((group < MAX_GROUP_NBR) && (appPubArray[group] == nullptr))
    {
        appPubArray[group] = pAbsApp;
        return true;
    }
    else
    {
        return false;
    }
}

void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal)
{
    if(signal == ITimeSlotManager::OWN_SLOT_START)
    {
        (*_pTransceiver) << mPDU;   // send MPDU to transceiver
    }
}
