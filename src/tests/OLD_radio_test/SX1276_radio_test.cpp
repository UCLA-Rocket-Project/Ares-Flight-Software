#include <Arduino.h>
#include "globals.h"
#include <SPI.h>
// #include "../lib/Radio/src/RadioLib.h"
#include <RadioLib.h>

const uint8_t VSCK_PIN = 18;
const uint8_t VMISO_PIN = 19;
const uint8_t VMOSI_PIN = 23;
SPIClass* radioSPI;

const uint8_t TRANSMITTER_RST = 27;
const uint8_t TRANSMITTER_CS = 5;
const uint8_t TRANSMITTER_D0 = 2;
const uint8_t TRANSMITTER_D1 = 4;
const uint8_t TRANSMITTER_TX_EN = 25;
const uint8_t TRANSMITTER_RX_EN = 26;

SX1276 radio = new Module(TRANSMITTER_CS, TRANSMITTER_D0, TRANSMITTER_RST, TRANSMITTER_D1);

int counter = 0;

void setup() {

  #ifdef DEBUG_MODE
    Serial.begin(115200);
  #endif

  radioSPI = new SPIClass(VSPI);
  radioSPI->begin(VSCK_PIN, VMISO_PIN, VMOSI_PIN);

  DEBUG(F("[SX1276] Initializing ... "));
  //int state = radio.begin(); //-121dBm
  //int state = radio.begin(868.0); //-20dBm
  int state = radio.begin(915.0,500.0,12,5,RADIOLIB_SX127X_SYNC_WORD,20,6,0); //-23dBm
  if (state == RADIOLIB_ERR_NONE) {
    DEBUGLN(F("init success!"));
  } else {
    DEBUG(F("failed, code "));
    DEBUGLN(state);
    while (true);
  }

  radio.setRfSwitchPins(TRANSMITTER_RX_EN, TRANSMITTER_TX_EN);


}

void loop() {
  DEBUG(F("[SX1276] Transmitting packet ... "));

  // you can transmit C-string or Arduino string up to
  // 256 characters long
  // NOTE: transmit() is a blocking method!
  //       See example SX127x_Transmit_Interrupt for details
  //       on non-blocking transmission method.

  char output[50];
  sprintf(output, "Counter: %d", counter++);

  int state = radio.transmit(output);

  // you can also transmit byte array up to 256 bytes long
  /*
    byte byteArr[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF};
    int state = radio.transmit(byteArr, 8);
  */

  if (state == RADIOLIB_ERR_NONE) {
    // the packet was successfully transmitted
    DEBUGLN(F(" success!"));

    // print measured data rate
    DEBUG(F("[SX1276] Datarate:\t"));
    DEBUG(radio.getDataRate());
    DEBUGLN(F(" bps"));

  } else if (state == RADIOLIB_ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 256 bytes
    DEBUGLN(F("too long!"));

  } else if (state == RADIOLIB_ERR_TX_TIMEOUT) {
    // timeout occurred while transmitting packet
    DEBUGLN(F("timeout!"));

  } else {
    // some other error occurred
    DEBUG(F("failed, code "));
    DEBUGLN(state);
  }

  // wait for a second before transmitting again
  delay(1000);
}
