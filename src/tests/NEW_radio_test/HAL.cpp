#include "HAL.h"

namespace HAL {


    void initCSPins() {
        pinMode(IMU_CS, OUTPUT);
        pinMode(ALTIMETER1_CS, OUTPUT);
        pinMode(SD_CS, OUTPUT);
        pinMode(TRANSMITTER_CS, OUTPUT);

        digitalWrite(IMU_CS, HIGH);
        digitalWrite(ALTIMETER1_CS, HIGH);
        digitalWrite(SD_CS, HIGH);
        digitalWrite(TRANSMITTER_CS, HIGH);
    }

    void initSensorHAL() {
        sensorSPI = new SPIClass(HSPI);
        sensorSPI->begin(HSCK_PIN, HMISO_PIN, HMOSI_PIN);
    }   

    void initRadioHAL() {
        
        radioSPI = new SPIClass(VSPI);
        radioSPI->begin(VSCK_PIN, VMISO_PIN, VMOSI_PIN);

        
    } 


}