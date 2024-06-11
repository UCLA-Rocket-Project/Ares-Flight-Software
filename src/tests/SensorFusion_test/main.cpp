// #define DEBUG_MODE

#include "globals.h"
#include "HAL.h"
#include <Arduino.h>
#include "IMU.h"

void setup() {
  Serial.begin(9600);

  #ifdef DEBUG_MODE
    while(!Serial);   
  #endif

  HAL::initSensorHAL();
  ICM::setupIMU();
  
  

}

void loop() {
  ICM::readIMU();
  delay(100);
}
