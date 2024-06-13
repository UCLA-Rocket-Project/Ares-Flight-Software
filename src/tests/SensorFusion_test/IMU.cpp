#include "IMU.h"

namespace ICM {
  void setupIMU() {
    for (int i=0; i<3000; i++) {
      // if(imu.begin_SPI(HAL::IMU_CS, HAL::sensorSPI)) {
      if(imu.begin_SPI(HAL::IMU_CS, HAL::HSCK_PIN, HAL::HMISO_PIN, HAL::HMOSI_PIN)) {
        DEBUGLN("found");
        break;
      }
      DEBUGLN("Failed to find imu20948 chip");
    }


    // imu.setAccelRange(imu20948_ACCEL_RANGE_16_G);
    DEBUG("Accelerometer range set to: ");
    switch (imu.getAccelRange()) {
      case ICM20948_ACCEL_RANGE_2_G:
        DEBUGLN("+-2G");
        break;
      case ICM20948_ACCEL_RANGE_4_G:
        DEBUGLN("+-4G");
        break;
      case ICM20948_ACCEL_RANGE_8_G:
        DEBUGLN("+-8G");
        break;
      case ICM20948_ACCEL_RANGE_16_G:
        DEBUGLN("+-16G");
        break;
    }
    DEBUGLN("OK");

    // imu.setGyroRange(imu20948_GYRO_RANGE_2000_DPS);
    DEBUG("Gyro range set to: ");
    switch (imu.getGyroRange()) {
      case ICM20948_GYRO_RANGE_250_DPS:
        DEBUGLN("250 degrees/s");
        break;
      case ICM20948_GYRO_RANGE_500_DPS:
        DEBUGLN("500 degrees/s");
        break;
      case ICM20948_GYRO_RANGE_1000_DPS:
        DEBUGLN("1000 degrees/s");
        break;
      case ICM20948_GYRO_RANGE_2000_DPS:
        DEBUGLN("2000 degrees/s");
        break;
    }

    //  imu.setAccelRateDivisor(4095);
    uint16_t accel_divisor = imu.getAccelRateDivisor();
    float accel_rate = 1125 / (1.0 + accel_divisor);

    DEBUG("Accelerometer data rate divisor set to: ");
    DEBUGLN(accel_divisor);
    DEBUG("Accelerometer data rate (Hz) is approximately: ");
    DEBUGLN(accel_rate);

    //  imu.setGyroRateDivisor(255);
    uint8_t gyro_divisor = imu.getGyroRateDivisor();
    float gyro_rate = 1100 / (1.0 + gyro_divisor);

    DEBUG("Gyro data rate divisor set to: ");
    DEBUGLN(gyro_divisor);
    DEBUG("Gyro data rate (Hz) is approximately: ");
    DEBUGLN(gyro_rate);
  }

  void readIMU() {

    /* Get a new normalized sensor event */
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;
    imu.getEvent(&accel, &gyro, &temp);

    IMU_temp = temp.temperature;
    accel_x = accel.acceleration.x;
    accel_y = accel.acceleration.y;
    accel_z = accel.acceleration.z;
    gyro_x = gyro.gyro.x;
    gyro_y = gyro.gyro.y;
    gyro_z = gyro.gyro.z;

    DEBUG(accel_x);
    DEBUG(",");
    DEBUG(accel_y);
    DEBUG(",");
    DEBUG(accel_z);

    DEBUG(",");
    DEBUG(gyro_x);
    DEBUG(",");
    DEBUG(gyro_y);
    DEBUG(",");
    DEBUG(gyro_z);
    DEBUG(",");
  }

  void calcAngles() {

    phi = atan(accel_x/accel_y)*180.0/3.141592;
    theta = asin(accel_z/9.81)*180.0/3.141592;
    DEBUG(phi);
    DEBUG(",");
    DEBUGLN(theta);
  }
}