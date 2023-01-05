#include "multipdu.h"

using namespace desenet;

// constructor of MultiPDU class => MultiPDU is a Frame => create Frame with maximum transfer unit (MTU)
MultiPDU::MultiPDU() : Frame(Frame::Mtu) ,
    ePDUcnt(0) ,
//    currentDataByteIdx(EMPTY_DATA_LENGTH),
    EMPTY_DATA_LENGTH(2),
    MAX_DATA_LENGTH(Frame::Mtu - EMPTY_DATA_LENGTH)
{
    // set up index variable and pointer to buffer
    currentDataByteIdx = EMPTY_DATA_LENGTH;
    bufferStartAddr = buffer();

    // set up an empty default frame
    setDestination(GATEWAY_ADDRESS);                // destination is fixed to  GATEWAY_ADDRESS (constant)
    setLength(Frame::HEADER_SIZE +
              currentDataByteIdx +                  // length of data is 2 because 1st byte contains frame type and sensor ID, 2nd byte contains ePDU length = 0
              Frame::FOOTER_SIZE);
    memcpy(bufferStartAddr + Frame::HEADER_SIZE,           // Copy default sensor slot number (<=> default sensor ID) into first data byte of buffer
           &DEFAULT_DESENET_SLOT_NUMBER,
           sizeof(DEFAULT_DESENET_SLOT_NUMBER));
    setType(FrameType::MPDU);                       // AFTER having set slot number => set type to MPDU (constantly)
    updateEPDUcnt();                                // Set the ePDU counter to 0 (2nd data byte)
}

MultiPDU::~MultiPDU()
{
    // do nothing
}

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

void MultiPDU::insertEventEPDU(const SharedByteBuffer& data, uint8_t length)
{
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
           &data,
           length);
}

void MultiPDU::updateEPDUcnt()
{
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + 1, &ePDUcnt, sizeof(ePDUcnt));
}

void MultiPDU::updateHeaderLength()
{
    setLength(Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE);
}

void MultiPDU::postProcessingAdditionEPDU(uint8_t length)
{
    ePDUcnt++;
    currentDataByteIdx += length;       // update byte index with written byte length BEFORE calling updateHeaderLength()
    updateEPDUcnt();
    updateHeaderLength();
}

void MultiPDU::clear()
{
    // reset count and length variables
    ePDUcnt = 0;
    currentDataByteIdx = EMPTY_DATA_LENGTH;     // +1 because we want to start just after the empty length

    // reset the buffer
    updateHeaderLength();
    updateEPDUcnt();

    // clear all data to zero => ATTENTION: This is NOT forcingly necessary but maybe useful for debug purpose!
    uint8_t zero = 0;
    for(uint8_t byteNbr = 2; byteNbr < (Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - 2); byteNbr++)            // the -2 comes from the framye type / sensor ID frame + ePDU count byte
    {
        memcpy(bufferStartAddr + Frame::HEADER_SIZE + byteNbr + Frame::FOOTER_SIZE, &zero, sizeof(zero));
    }
}

uint8_t MultiPDU::getRemainingLength()
{
    return Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - currentDataByteIdx;
}

uint8_t* MultiPDU::getValidStart()
{
    return bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + 1 + Frame::FOOTER_SIZE;  // + 1 due to definition of position (effective start of write operation)
}
