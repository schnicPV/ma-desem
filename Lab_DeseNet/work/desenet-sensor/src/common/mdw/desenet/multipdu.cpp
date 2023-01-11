#include "multipdu.h"

using namespace desenet;

/**
 * @brief constructor of MultiPDU class, which is a Frame
 *        => create Frame with maximum transfer unit (MTU)
 */
MultiPDU::MultiPDU() : Frame(Frame::Mtu)
                     , EMPTY_DATA_LENGTH(2)
                     , MAX_DATA_LENGTH(Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - EMPTY_DATA_LENGTH)
                     , ePDUcnt(0)
{
    // set up index variable and pointer to buffer
    currentDataByteIdx = EMPTY_DATA_LENGTH;
    bufferStartAddr = buffer();

    // set up an empty default frame
    setDestination(GATEWAY_ADDRESS);                // destination is fixed to  GATEWAY_ADDRESS (constant)
    setLength(Frame::HEADER_SIZE +
              currentDataByteIdx +                  // length of data is 2 because 1st byte contains frame type and sensor ID, 2nd byte contains ePDU length = 0
              Frame::FOOTER_SIZE);
    memcpy(bufferStartAddr + Frame::HEADER_SIZE,    // Copy default sensor slot number (<=> default sensor ID) into first data byte of buffer
           &DEFAULT_DESENET_SLOT_NUMBER,
           sizeof(DEFAULT_DESENET_SLOT_NUMBER));
    setType(FrameType::MPDU);                       // AFTER having set slot number => set type to MPDU (constantly)
    updateEPDUcnt();                                // Set the ePDU counter to 0 (2nd data byte)
}

/**
 * @brief destructor (unused)
 */
MultiPDU::~MultiPDU() {}

/**
 * @brief   add the ePDU header of Sampled Value data
 *
 * @param   type        the first bit (0)
 * @param   group       the SV group
 * @param   length      the number of bytes of the ePDU frame
 *
 * @return  void
 */
void MultiPDU::addEPDUheader(uint8_t type, SvGroup group, uint8_t length)
{
    // create ePDU header
    EPDUH2Byte e2b;
    e2b.header.size = length;                                  // length of ePDU payload
    e2b.header.group = group;                                  // group nbr of SV
    e2b.header.type = type;                                    // always zero for SV ePDU

    // copy first byte (<=> e2b.byte) into MPDU
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
           &e2b.byte,
           sizeof(e2b.byte));

    // increase current data byte index to write the data after header
    currentDataByteIdx++;
}

/**
 * @brief   add ePDU header of EVent data
 *
 * @param   type        the first bit (1)
 * @param   evID        the ID of the event
 * @param   length      the number of bytes of the ePDU frame
 *
 * @return  void
 */
void MultiPDU::addEPDUheader(uint8_t type, EvId evID, uint8_t length)
{
    // create ePDU header
    EPDUH2Byte e2b;
    e2b.header.size = length;                                  // length of ePDU payload
    e2b.header.group = evID;                                   // Event ID
    e2b.header.type = type;                                    // always one for EV ePDU

    // copy first byte (<=> e2b.byte) into MPDU
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
           &e2b.byte,
           sizeof(e2b.byte));

    // increase current data byte index to write the data after header
    currentDataByteIdx++;
}
/**
 * @brief   insert a new event into the MPDU frame
 *
 * @param   data        the SharedByteBuffer reference which holds the event data
 * @param   length      the number of bytes to write
 *
 * @return  void
*/
void MultiPDU::insertEventEPDU(const SharedByteBuffer& data, uint8_t length)
{
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
           &data,
           length);
}

/**
 * @brief   update the ePDU counter byte (fixed byte after frametype / sensor ID byte)
 *
 * @param   none
 *
 * @return  void
*/
void MultiPDU::updateEPDUcnt()
{
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + 1, &ePDUcnt, sizeof(ePDUcnt));
}

/**
 * @brief   update the byte counter of the MPDU header
 *
 * @param   none
 *
 * @return  void
*/
void MultiPDU::updateHeaderLength()
{
    setLength(Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE);
}

/**
 * @brief   increase counters and update length after addition of a SINGLE ePDU (SV or EV)
 *
 * @param   length      the number of bytes written to the MPDU frame
 *
 * @return  void
*/
void MultiPDU::postProcessingAdditionEPDU(uint8_t length)
{
    ePDUcnt++;
    currentDataByteIdx += length;       // update byte index with written byte length BEFORE calling updateHeaderLength()
    updateEPDUcnt();
    updateHeaderLength();
}

/**
 * @brief   reset counters and set all bytes to zero
 *
 * @param   none
 *
 * @return  void
*/
void MultiPDU::clear()
{
    // reset count and length variables
    ePDUcnt = 0;
    currentDataByteIdx = EMPTY_DATA_LENGTH;     // +1 because we want to start just after the empty length

    // reset the buffer
    updateHeaderLength();
    updateEPDUcnt();

    // clear all data to zero (NOT FORCINGLY NECESSARY!)
    memset(bufferStartAddr + Frame::HEADER_SIZE + EMPTY_DATA_LENGTH + Frame::FOOTER_SIZE, 0, MAX_DATA_LENGTH);
}

/**
 * @brief   get the remaining length of the MPDU frame which can be written to it
 *
 * @param   none
 *
 * @return  the remaining length
*/
uint8_t MultiPDU::getRemainingLength()
{
    return Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - currentDataByteIdx;
}

/**
 * @brief   get the valid start index to write to the MPDU frame
 *
 * @param   none
 *
 * @return  the pointer to the start index
*/
uint8_t* MultiPDU::getValidStart()
{
    return bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + 1 + Frame::FOOTER_SIZE;  // + 1 due to definition of position (effective start of write operation)
}
