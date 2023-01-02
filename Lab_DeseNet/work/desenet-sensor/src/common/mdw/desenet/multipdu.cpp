#include "multipdu.h"

using namespace desenet;

// constructor of MultiPDU class => MultiPDU is a Frame => create Frame with maximum transfer unit (MTU)
MultiPDU::MultiPDU() : Frame(Frame::Mtu) ,
    EMPTY_DATA_LENGTH(2) ,
//    currentDataByteIdx(EMPTY_DATA_LENGTH),
    MAX_DATA_LENGTH(Frame::Mtu - EMPTY_DATA_LENGTH),
    ePDUcnt(0)
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

bool MultiPDU::addEPDU(SvGroup group, size_t byteLength)
{
    if(byteLength <= (MAX_DATA_LENGTH - currentDataByteIdx))           // fill directly into MPDU
    {
        // create ePDU
        EPDUH2Byte e2b;
        e2b.header.type = 0;                                           // always zero for SV ePDU
        e2b.header.group = group;                                      // group nbr of SV
        e2b.header.size = byteLength;                                  // length of ePDU payload

        // copy first byte (<=> e2b.byte) into MPDU
        memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
               &e2b.byte,
               sizeof(e2b.byte));
        currentDataByteIdx++;

        // copy data into MPDU
        memcpy(bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE,
               svBuffer.data(),
               byteLength);
        currentDataByteIdx++;

        // ePDU counter increment + copy new value into MPDU
        ePDUcnt++;
        updateEPDUcnt();

        // set new lengtt of MPDU (copies value to MPDU)
        setLength(Frame::HEADER_SIZE + currentDataByteIdx + Frame::FOOTER_SIZE);
        return true;
    }
    else
    {
        return false;       // if there's no place in the MPDU, then do NOT queue something because this is not a good idea in real-time application
    }
}

void MultiPDU::addEPDUheader(uint8_t type, SvGroup group, uint8_t length, uint8_t index)
{
    // create ePDU
    EPDUH2Byte e2b;
    e2b.header.size = length;                                  // length of ePDU payload
    e2b.header.group = group;                                  // group nbr of SV
    e2b.header.type = type;                                    // always zero for SV ePDU

    // copy first byte (<=> e2b.byte) into MPDU
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + index + Frame::FOOTER_SIZE,
           &e2b.byte,
           sizeof(e2b.byte));
}

void MultiPDU::addEPDU(EvId evID, SharedByteBuffer data)
{
    // tbc
}

void MultiPDU::updateEPDUcnt()
{
    memcpy(bufferStartAddr + Frame::HEADER_SIZE + 1, &ePDUcnt, sizeof(ePDUcnt));
}

void MultiPDU::updateHeaderLength(uint8_t index)
{
    setLength(Frame::HEADER_SIZE + index + Frame::FOOTER_SIZE);
}

bool MultiPDU::spaceAvailable()
{
    return !mpduFull;
}

void MultiPDU::clear()
{
    // reset count and length variables
    ePDUcnt = 0;
    currentDataByteIdx = EMPTY_DATA_LENGTH;     // +1 because we want to start just after the empty length

    // reset the buffer
    updateHeaderLength(EMPTY_DATA_LENGTH);
    updateEPDUcnt();

    // clear all data to zero => ATTENTION: This is NOT forcingly necessary but maybe useful for debug purpose!
    uint8_t zero = 0;
    for(uint8_t byteNbr = 2; byteNbr < (Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - 2); byteNbr++)            // the -2 comes from the framye type / sensor ID frame + ePDU count byte
    {
        memcpy(bufferStartAddr + Frame::HEADER_SIZE + byteNbr + Frame::FOOTER_SIZE, &zero, sizeof(zero));
    }
}

// Method which returns the index of the current bit in the MPDU Frame
uint8_t MultiPDU::currentIndex()
{
    return *bufferStartAddr;
}

uint8_t MultiPDU::getRemainingLength()
{
    return Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - currentDataByteIdx;
}

uint8_t* MultiPDU::getBufferStartAddr()
{
    return bufferStartAddr;
}

uint8_t* MultiPDU::getValidStart()
{
    return bufferStartAddr + Frame::HEADER_SIZE + currentDataByteIdx + 1 + Frame::FOOTER_SIZE;  // + 1 due to definition of position (effective start of write operation)
}
