#include "HAL.h"

namespace HAL {


    void initCSPins() {
    }

    void initSensorHAL() {
        sensorSPI = new SPIClass(HSPI);
        sensorSPI->begin(HSCK_PIN, HMISO_PIN, HMOSI_PIN);
    }   


}