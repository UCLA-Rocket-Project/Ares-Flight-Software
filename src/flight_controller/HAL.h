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

    // VSPI
    const uint8_t VSCK_PIN = 18;
    const uint8_t VMISO_PIN = 19;
    const uint8_t VMOSI_PIN = 23;
    inline SPIClass* radioSPI;

    // HSPI
    const uint8_t HSCK_PIN = 14;
    const uint8_t HMISO_PIN = 36;
    const uint8_t HMOSI_PIN = 13;
    inline SPIClass* sensorSPI;

    // I2C
    const uint8_t INA_ADDR = 0x40;
    const uint8_t INA_SDA_PIN = 21;
    const uint8_t INA_SCL_PIN = 22;

    // Serial 
    const uint8_t GPS_RX_PIN = 16;
    const uint8_t GPS_TX_PIN = 17;
    const uint8_t GPS_I2C_PORT = 2; //This is not a pin
    inline HardwareSerial gps_serial(GPS_I2C_PORT);

    /* ---------- Pinouts ---------- */
    // Transmitter
    const uint8_t TRANSMITTER_RST = 27;
    const uint8_t TRANSMITTER_CS = 5;
    const uint8_t TRANSMITTER_D0 = 2;
    const uint8_t TRANSMITTER_D1 = 4;
    const uint8_t TRANSMITTER_TX_EN = 25;
    const uint8_t TRANSMITTER_RX_EN = 26;

    // Altimeter
    const uint8_t ALTIMETER1_CS = 26;
    const uint8_t ALTIMETER2_ADDR = 0x77;


    // IMU
    const uint8_t IMU_CS = 33;

    // SD/Flash
    const uint8_t SD_CS = 32;

    void initCSPins();

    void initSensorHAL();

    void initRadioHAL();
}

#endif