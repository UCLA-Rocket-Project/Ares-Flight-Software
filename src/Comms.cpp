#include "Comms.h"

namespace Comms {

    uint16_t packetize(Packet* pkt, uint8_t* downlink_buffer, uint16_t len) {
        
        finishPacket(pkt);
        
        // Add ID
        memcpy(downlink_buffer, &pkt->id,1);

        // Add timestamp
        memcpy(downlink_buffer + 1, &pkt->timestamp, 4);

        // Add data length
        memcpy(downlink_buffer + 5,&pkt->len,  1);

        // Add CRC
        memcpy(downlink_buffer + 6,&pkt->checksum,  2);

        // Add Data
        memcpy(downlink_buffer + 8, &pkt->data, len);

        return len + 8;
        

    }

    // https://www.ibm.com/docs/en/zos/2.4.0?topic=calculations-checksum-algorithm
    uint16_t CRC(Packet *packet)
    {

        return 0x69;
    }

    void finishPacket(Packet* pkt) {

        // Packetize timestamp
        uint32_t curr_time = millis();
        pkt->timestamp[0] = curr_time & 0xFF;
        pkt->timestamp[1] = (curr_time >> 8) & 0xFF;
        pkt->timestamp[2] = (curr_time >> 16) & 0xFF;
        pkt->timestamp[3] = (curr_time >> 24) & 0xFF;

        // Packetize CRC
        uint16_t crc = CRC(pkt);
        pkt->checksum[0] = crc & 0xFF;
        pkt->checksum[1] = (crc >> 8) & 0xFF;
    }

}