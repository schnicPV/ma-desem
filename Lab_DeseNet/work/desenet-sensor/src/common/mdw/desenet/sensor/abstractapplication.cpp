#include "desenet/sensor/net.h"
#include "abstractapplication.h"

using desenet::sensor::AbstractApplication;

/*********************************************************************************************************
* TODO: Implement the protected methods of the AbstractApplication class here. From these you have to    *
* call the different methods on your DESENET Controller Entity implementation...                         *
*********************************************************************************************************/

// Default implementations.

void AbstractApplication::svSyncRequest()
{
    // TODO: Register application using the network entity
    NetworkEntity::instance().svSyncRequest(this);
/***Net::instance().entity().svSyncRequest(this);****/   // possible as well !
}

// limited with 16 sample slots => add new inscription to list only when this method reutrns true!
bool AbstractApplication::svPublishRequest(SvGroup group)
{
    // TODO: Register application for the provided group using the network entity
    return NetworkEntity::instance().svPublishRequest(this, group);
}

void AbstractApplication::evPublishRequest(EvId id, const SharedByteBuffer & evData)
{
    // TODO: Publish event data
    NetworkEntity::instance().evPublishRequest(id, evData);
}

/**
 * Default callback method for syncs
 */
void AbstractApplication::svSyncIndication(desenet::NetworkTime)
{
    // due to polymorphism never landing here! --> it is desired to call svSyncIndication() of Accelerometer!
}

/**
 * Default callback method for SV publishes
 */
SharedByteBuffer::sizeType AbstractApplication::svPublishIndication(SvGroup, SharedByteBuffer &)
{
    return 0;
}
