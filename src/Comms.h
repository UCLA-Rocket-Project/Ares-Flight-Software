#ifndef COMMS_H
#define COMMS_H

#include "globals.h"

namespace Comms {

    #define PACKET_SIZE 256
    
    struct Packet
    {
        uint8_t id;
        uint8_t len;
        uint8_t timestamp[4];
        uint8_t checksum[2];
        uint8_t data[PACKET_SIZE];
    };
}


#endif