#include "HAL.h"

#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>

namespace ICM {

    inline Adafruit_ICM20948 imu;

    inline double IMU_temp;
    inline double accel_x, accel_y, accel_z;
    inline double gyro_x, gyro_y, gyro_z;

    // inline double roll, pitch, yaw;
    inline double phi, theta;

    void setupIMU();
    
    void readIMU();

    void calcAngles();
}