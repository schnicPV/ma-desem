#ifndef MULTIPDU_H
#define MULTIPDU_H

#include "frame.h"
#include "platform-config.h"

namespace desenet
{
    class MultiPDU: public Frame
    {
    public:
        MultiPDU();
        ~MultiPDU();

        uint8_t ePDUcnt;            // the ePDU counter indicates the number of ePDUs in the data byte buffer
        uint8_t currentDataByteIdx; // indicates the length (in nbr of bytes) of the data byte buffer

//        bool addEPDU(SvGroup group, size_t byteLength); //unused!
        void insertEventEPDU(const SharedByteBuffer& data, uint8_t length, uint8_t index);
        void addEPDUheader(uint8_t type, SvGroup group, uint8_t length, uint8_t index);
        void addEPDUheader(uint8_t type, EvId evID, uint8_t length, uint8_t index);

        void clear();
        SharedByteBuffer svBuffer;

        uint8_t* getValidStart();
        uint8_t getRemainingLength();

        void updateEPDUcnt();
        void updateHeaderLength();
        void postProcessingAdditionEPDU();

    protected:
        uint8_t* bufferStartAddr;

    private:
        // const parameters
        size_t EMPTY_DATA_LENGTH;
        size_t MAX_DATA_LENGTH;

        // struct and union used to easily transform "bit data" into a single byte;
        struct EPDUH
        {
            unsigned size : 3;
            unsigned group : 4;
            unsigned type : 1;
        };
        union EPDUH2Byte
        {
            EPDUH header;
            uint8_t byte;
        };
    };
}//desenet
#endif // MULTIPDU_H
