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

        void insertEventEPDU(const SharedByteBuffer& data, uint8_t length);
        void addEPDUheader(uint8_t type, SvGroup group, uint8_t length);
        void addEPDUheader(uint8_t type, EvId evID, uint8_t length);

        void clear();

        uint8_t* getValidStart();
        uint8_t getRemainingLength();

        void updateEPDUcnt();
        void updateHeaderLength();
        void postProcessingAdditionEPDU(uint8_t length);

    protected:
        uint8_t* bufferStartAddr;           ///< pointer to the start of the MPDU frame

    private:
        /* min and max MPDU sizes */
        size_t EMPTY_DATA_LENGTH;     ///< number of bytes of empty MPDU frame ( = 2)
        size_t MAX_DATA_LENGTH;       ///< max number of bytes to write to MPDU frame

        /* counters */
        uint8_t ePDUcnt;                    ///< the ePDU counter indicates the number of ePDUs in the data byte buffer
        uint8_t currentDataByteIdx;         ///< indicates the current position (in nbr of bytes after header) of the data byte buffer

        /* struct and union used to easily transform "bit data" into a single byte; */
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
