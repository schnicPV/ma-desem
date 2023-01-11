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

    // check that received frame is a Beacon
    if(frame.type() == FrameType::Beacon)
    {
        /******************************/
        /* STEP 1 : create new beacon */
        /******************************/
        Beacon* pBcon = new Beacon(frame);

        /***************************************/
        /* STEP 2 : start timer for time slots */
        /***************************************/
        _pTimeSlotManager->onBeaconReceived(pBcon->slotDuration());

        /************************************/
        /* STEP 3 : notify all applications */
        /************************************/
        for(auto list_elm = appSyncList.begin(); list_elm != appSyncList.end(); list_elm++)     // parse a list acc. to example on cplusplus.com
        {
            (*list_elm)->svSyncIndication(receptionTime);
        }

        /*************************************************/
        /* STEP 4 : publish request for all applications */
        /*************************************************/
        mPDU.clear();
        size_t writtenByteLength = 0;
        for(SvGroup idx = 0; idx < MAX_GROUP_NBR; idx++)
        {
            if((appPubArray[idx] != nullptr) && pBcon->svGroupMask()[idx])              // check if groupNbr (idx) is not a nullpointer and if Beacon wants to receive data from this group (idx)
            {
                SharedByteBuffer buffer = SharedByteBuffer::proxy(mPDU.getValidStart(), mPDU.getRemainingLength());     // this buffer uses the remaining part of the MPDU frame
                writtenByteLength = appPubArray[idx]->svPublishIndication(idx, buffer);                                 // returns the written byte length (if not succesful: returns 0)
                if(writtenByteLength > 0)
                {
                    mPDU.addEPDUheader(SV_EPDU_TYPE, idx, writtenByteLength);           // here the currentDataByteIndex is 2 because of clear() above
                    mPDU.postProcessingAdditionEPDU(writtenByteLength);                 // update all counters and data byte index with written byte length
                }
            }
        }

        /*******************************************/
        /* STEP 5 : try to insert events into MPDU */
        /*******************************************/
        uint8_t addedElmCnt = 0;
        for(auto list_elm = evList.begin(); list_elm != evList.end(); list_elm++)   // parse the event buffer
        {
            uint8_t evSize = (list_elm->data).length();
            if((evSize <= mPDU.getRemainingLength() - 1) && (evSize > 0))           // -1 due to EPDU header
            {
                mPDU.addEPDUheader(EV_EPDU_TYPE, list_elm->id, evSize);
                mPDU.insertEventEPDU(list_elm->data, evSize);
                mPDU.postProcessingAdditionEPDU(evSize);                            // update all counters and data byte index with written byte length
                addedElmCnt++;
            }
            else break;         // avoid unnessecary for loop iterations
        }
        if(addedElmCnt > 0)
        {
            evList_pop_front_multi(addedElmCnt);    // remove the added elements from the event list
        }
    }

    ledController().flashLed(0);    // this flashes the LED on the simulated board
}

board::LedController & NetworkEntity::ledController() const
{
    return board::LedController::instance();
}

/**
 * @brief   stores a new 'AbstractApplication' pointer in the 'appSyncList' (called in 'AbstractApplication' after sync. request)
 *
 * @param   pAbsApp     the pointer to the AbstractApplication
 *
 * @return  void
 */
void NetworkEntity::svSyncRequest(AbstractApplication* pAbsApp)
{
    appSyncList.push_back(pAbsApp);
}

/**
 * @brief   stores a new 'AbstractApplication' pointer and the corresponding Group Nbr in the 'appPubArray' (called in 'AbstractApplication' after sync. request)
 *
 * @param   pAbsApp
 * @param   group
 *
 * @return  true if the publish request was succesful, false otherwise
 */
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

/**
 * @brief   publish request for an event, i.e. this method is called at the rise of an event and adds this event element to the event list (if possible)
 *
 * @param   id          the event ID
 * @param   evData      the reference to the buffer containing the event data
 *
 * @return  void
 */
void NetworkEntity::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
    EventElement evElm = EventElement(id, evData);      // create new EventElement
    evList.push_back(evElm);                            // add EventElement to end of list
    if(evList.size() > MAX_EVELM_NBR)
    {
        evList_pop_front_multi(CUTOFF_EVELM_NBR);              // remove oldest CUTOFF_EVELM_NBR elements
    }
}

/**
 * @brief   method which is called on timeout events from the TimeSlotManager (virtual in Observer class => necessary to implement!)
 *
 * @param   timeSlotManager     the time slot manager
 * @param   signal              the signal received from the time slot manager
 *
 * @return  void
 */
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal)
{
    if(signal == ITimeSlotManager::OWN_SLOT_START)
    {
        (*_pTransceiver) << mPDU;   // send MPDU to transceiver
    }
}

/**
 * @brief   delete a specific number of elements from the front of the evList
 *
 * @param   elmNbr      the desired number of elements to erase at the front
 *
 * @return  void
 */
void NetworkEntity::evList_pop_front_multi(uint8_t elmNbr)
{
    auto cutoff_idx = evList.begin();
    std::advance(cutoff_idx, elmNbr);           // go to desired index
    evList.erase(evList.begin(),cutoff_idx);    // erase all elements from start to desired index
}
