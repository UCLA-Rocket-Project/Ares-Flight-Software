// #define DEBUG_MODE

#include "globals.h"
#include "HAL.h"
#include "Radio.h"
#include <Arduino.h>


int lastTransmissionTime = 0;

void radioGPS(void* param) {
  while(1) {
    Radio::transmit();
    delay(1000);
  }
  
}

void setup() {
  Serial.begin(115200);

  #ifdef DEBUG_MODE
    while(!Serial);   
  #endif

  HAL::initRadioHAL();

  Radio::setup();

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
