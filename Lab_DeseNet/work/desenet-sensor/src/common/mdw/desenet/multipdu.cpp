#include "multipdu.h"

using namespace desenet;

#define EMPTY_DATA_LENGTH 2

// constructor of MultiPDU class => MultiPDU is a Frame => create Frame with maximum transfer unit (MTU)
MultiPDU::MultiPDU() : Frame(Frame::Mtu) ,
    dataByteLength(EMPTY_DATA_LENGTH) ,
    ePDUcnt(0)
{
    // set up an empty default frame
    setDestination(GATEWAY_ADDRESS);                // destination is fixed to  GATEWAY_ADDRESS (constant)
    setLength(Frame::HEADER_SIZE +
              dataByteLength +                      // length of data is 2 because 1st byte contains frame type and sensor ID, 2nd byte contains ePDU length = 0
              Frame::FOOTER_SIZE);
    memcpy(buffer() + Frame::HEADER_SIZE,           // Copy default sensor slot number (<=> default sensor ID) into first data byte of buffer
           &DEFAULT_DESENET_SLOT_NUMBER,
           sizeof(DEFAULT_DESENET_SLOT_NUMBER));
    setType(FrameType::MPDU);                       // AFTER having set slot number => set type to MPDU (constantly)
    memcpy(buffer() + Frame::HEADER_SIZE + 1,       // Set the ePDU counter to 0 (2nd data byte)
           &ePDUcnt,
           sizeof(ePDUcnt));
}

void MultiPDU::addEPDU(SvGroup group, size_t length)
{
    // tbc
}

void MultiPDU::addEPDU(EvId evID, size_t length)
{
    // tbc
}

bool MultiPDU::spaceAvailable()
{
    return !mpduFull;
}

void MultiPDU::clear()
{
    // reset count and length variables
    ePDUcnt = 0;
    dataByteLength = EMPTY_DATA_LENGTH;

    // reset the buffer
    setLength(Frame::HEADER_SIZE + dataByteLength + Frame::FOOTER_SIZE);
    memcpy(buffer() + Frame::HEADER_SIZE + 1, &ePDUcnt, sizeof(ePDUcnt));

    // clear all data to zero => ATTENTION: This is NOT forcingly necessary but maybe useful for debug purpose!
    uint8_t zero = 0;
    for(uint8_t byteNbr = 2; byteNbr < (Frame::Mtu - Frame::HEADER_SIZE - Frame::FOOTER_SIZE - 2); byteNbr++)            // the -2 comes from the framye type / sensor ID frame + ePDU count byte
    {
        memcpy(buffer() + Frame::HEADER_SIZE + byteNbr + Frame::FOOTER_SIZE, &zero, sizeof(zero));
    }
}

// Method which returns the index of the current bit in the MPDU Frame
uint8_t MultiPDU::dataLength()
{
    return dataByteLength;
}
