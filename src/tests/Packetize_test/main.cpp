#include <Arduino.h>
#include "globals.h"
#include "../../Comms.h"

Comms::Packet pkt;
uint8_t print_buffer[256];

void setup() {

  #ifdef DEBUG_MODE
    Serial.begin(115200);
  #endif

  pkt.id = 0x6;
  pkt.data[0] = 0x12;
  pkt.len = 1;
  
  
}

void loop() {
  // DEBUGLN("1");
  // delay(1000);

  uint16_t length = Comms::packetize(&pkt, print_buffer, 1);


  for (uint16_t i = 0; i < length; i++) {
    Serial.print(print_buffer[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  
  
  



  
}
