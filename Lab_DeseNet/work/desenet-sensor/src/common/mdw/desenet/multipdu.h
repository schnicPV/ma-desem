#ifndef MULTIPDU_H
#define MULTIPDU_H

#include "frame.h"
#include "platform-config.h"

namespace desenet
{
    enum frameBitSizes
    {
        Frametype = 1,
        SensorID = 7,
        ePduCnt = 8,
        ePduSingle = 8
    };

    class MultiPDU: public Frame
    {
    public:
        MultiPDU();
        ~MultiPDU();
        uint8_t dataLength();
        void addEPDU(SvGroup group, size_t length);
        void addEPDU(EvId evID, size_t length);
        bool spaceAvailable();
        void clear();

    private:
        uint8_t dataByteLength;     // indicates the length (in nbr of bytes) of the data byte buffer
        uint8_t ePDUcnt;            // the ePDU counter indicates the number of ePDUs in the data byte buffer
        bool mpduFull;
    };
}//desenet
#endif // MULTIPDU_H
