#ifndef HAL_H
#define HAL_H

#include <Arduino.h>
#include "Globals.h"

#include <HardwareSerial.h>
#include "Libraries/Firmware/SPI/SPI.h"
#include "Libraries/Firmware/I2C/Wire.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                            Variables                                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace HAL { 

    // HSPI
    const uint8_t HSCK_PIN = 14;
    const uint8_t HMISO_PIN = 36;
    const uint8_t HMOSI_PIN = 13;
    inline SPIClass* sensorSPI;


    const uint8_t W5500_CS = 26;


    // IMU
    const uint8_t IMU_CS = 33;

    // SD/Flash
    const uint8_t SD_CS = 32;

    void initCSPins();

    void initSensorHAL();

}

#endif