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

        // // Sets the output power to 17 dbm with default mode of PA_BOOST for higher ones
        // radio.setTxPower(17);


        test_packet[0] = 0x6c;
        test_packet[1] = 0x69;
        test_packet[2] = 0x67;
        test_packet[3] = 0x6d;
        test_packet[4] = 0x61;

        test_packet_length = 5;

    }


    void transmit() {
        int oldTime = millis();

        digitalWrite(HAL::TRANSMITTER_TX_EN, HIGH);

        radio.beginPacket();
        // radio.print("Hello!");
        radio.write(test_packet,test_packet_length);
        radio.endPacket(true);

        digitalWrite(HAL::TRANSMITTER_TX_EN, LOW);
        
        lastTransmissionTime = millis() - oldTime;  
        DEBUGLN("transmit");
        // DEBUGLN();
        // delay(100);
    }
}