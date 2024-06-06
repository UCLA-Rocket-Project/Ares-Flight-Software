#include "HAL.h"
#include "Globals.h"
// #include <RadioLib.h>
#include "../lib/LoRa/LoRa.h"
// #include "Lora.h"

namespace Radio {

    #define syncWord 0x45
    #define transmissionFreq 915E6

    inline LoRaClass radio;

    inline int lastTransmissionTime = 0;

    inline String test_packet = (String)"9980.00,23.71" + "," + (String)lastTransmissionTime + ",";

    void setup();

    void transmit();
    
}