// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#include "Libraries/Firmware/CAN/CAN.h"
#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Sender");

  // start the CAN bus at 500 kbps (need to do double because the clock speed of this ESP is 80MHz instead of 40MHz)
  if (!CAN.begin(1000E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
  // CAN.loopback();
}

void loop() {
  // send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");
  CAN.beginPacket(0x12);
  CAN.write('h');
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);

  // send extended packet: id is 29 bits, packet can contain up to 8 bytes of data
  // Serial.print("Sending extended packet ... ");

  // CAN.beginExtendedPacket(0xabcdef);
  // CAN.write('w');
  // CAN.write('o');
  // CAN.write('r');
  // CAN.write('l');
  // CAN.write('d');
  // CAN.endPacket();

  // Serial.println("done");

  // delay(1000);
}