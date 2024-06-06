// #define DEBUG_MODE

#include "globals.h"
#include "HAL.h"
#include "Radio.h"
#include <Arduino.h>


int lastTransmissionTime = 0;

void radioGPS(void* param) {
  while(1) {
    int oldTime = millis();
    Radio::radio.beginPacket();
    Radio::radio.print(Radio::downlink_packet);
    Radio::radio.endPacket();
    lastTransmissionTime = millis() - oldTime;  
    DEBUGLN("transmit");
  }
}

void setup() {
  Serial.begin(9600);

  #ifdef DEBUG_MODE
    while(!Serial);   
  #endif

  HAL::initRadioHAL();

  Radio::setupRadio();

  xTaskCreatePinnedToCore (
    radioGPS,     // Function to implement the task
    "radioGPS",   // Name of the task
    10000,      // Stack size in words
    NULL,      // Task input parameter
    0,         // Priority of the task
    NULL,      // Task handle.
    0          // Core where the task should run
  );
}

void loop() {

  
}
