#include "HAL.h"
#include "Globals.h"
// #include <RadioLib.h>
#include "../lib/LoRa/LoRa.h"

namespace Radio {

    #define syncWord 0x45
    #define transmissionFreq 915E6

    LoRaClass radio;

    int lastTransmissionTime = 0;

    String downlink_packet = (String)"9980.00,23.71" + "," + (String)lastTransmissionTime + ",";


    void setupRadio();


    void transmitPacket();
    
}