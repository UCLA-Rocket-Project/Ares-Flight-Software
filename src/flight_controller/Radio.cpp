#include "Radio.h"

namespace Radio{
    void setup() {
        //replace the LoRa.begin(---E-) argument with your location's frequency 
        //915E6 for North America

        //setup LoRa transceiver module
        radio.setPins(HAL::TRANSMITTER_CS, HAL::TRANSMITTER_RST, HAL::TRANSMITTER_D0);
        radio.setSPI(*HAL::radioSPI);

        for (int i=0; i<300; i++) {
            if(radio.begin(transmissionFreq))
                break;    
            DEBUGLN(".");
        }

        // Change sync word to match the receiver
        radio.setSyncWord(syncWord);
        DEBUGLN("LoRa Initializing OK!");

        // Sets the output power to 17 dbm (50 mW) with TRANSMITTER_TX_EN as the boost pin
        radio.setTxPower(17,HAL::TRANSMITTER_TX_EN);
    }


    void transmit() {
        int oldTime = millis();
        radio.beginPacket();
        radio.print(test_packet);
        radio.endPacket();
        lastTransmissionTime = millis() - oldTime;  
        DEBUGLN("transmit");
        // DEBUGLN();
        // delay(100);
    }
}