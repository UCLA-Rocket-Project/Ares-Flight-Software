#ifndef COMMS_H
#define COMMS_H

#include <Arduino.h>

#include "globals.h"
#include "../lib/Ethernet/Ethernet2.h"
#include "../lib/Ethernet/EthernetUdp2.h"
#include <map>
#include <vector>

namespace Comms {

    #define PACKET_SIZE 256
    
    struct Packet
    {
        uint8_t id;
        uint8_t timestamp[4];
        uint8_t len;
        uint8_t checksum[2];
        uint8_t data[PACKET_SIZE];
    };

    uint16_t packetize(Packet* pkt, uint8_t* downlink_buffer, uint16_t len);

    uint16_t CRC(Packet *packet);

    void finishPacket(Packet *packet);
}


#endif