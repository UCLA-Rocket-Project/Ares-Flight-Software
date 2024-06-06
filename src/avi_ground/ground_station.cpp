#include <Arduino.h>
// #include <RadioLib.h>
#include <LoRa.h>
#include <SPI.h>

const uint8_t SCK_PIN_A = 14;
const uint8_t MISO_PIN_A = 36;
const uint8_t MOSI_PIN_A = 13;
SPIClass* SPI_A;

const uint8_t SCK_PIN_B = 18;
const uint8_t MISO_PIN_B = 19;
const uint8_t MOSI_PIN_B = 23;
SPIClass* SPI_B;


const uint32_t CS_PIN_A = 15;
const uint8_t CS_PIN_B = 5;

const uint32_t RST_A = 16;
const uint8_t RST_B = 17;

const uint32_t D0_A = 32;
const uint8_t D1_A = 33;

const uint32_t D0_B = 25;
const uint8_t D1_B = 26;

#define syncWord 0x45
#define transmissionFreqA 915E6
#define transmissionFreqB 917E6

// SX1276* radio_A;
// SX1276* radio_B;


LoRaClass radioA;
LoRaClass radioB;

int state_A;
int state_B;

String str_A;
String str_B;


// or using RadioShield
// https://github.com/jgromes/RadioShield
//SX1278 radio_A= RadioShield.ModuleA;

void setup() {
  Serial.begin(9600);

  SPI_A = new SPIClass(HSPI);
  SPI_A->begin(SCK_PIN_A, MISO_PIN_A, MOSI_PIN_A);
  
  // SPI_B = new SPIClass(VSPI);
  // SPI_B->begin(SCK_PIN_B, MISO_PIN_B, MOSI_PIN_B);


  Serial.println("LoRa Receiver");

  radioA.setPins(CS_PIN_A, RST_A, D0_A);
  radioA.setSPI(*SPI_A);
  // radioB.setPins(CS_PIN_B, RST_B, D0_B);
  // radioB.setSPI(*SPI_B);


  
  if (!radioA.begin(transmissionFreqA)) {
    Serial.println("Starting LoRa A failed!");
  }

  radioA.setSyncWord(syncWord);
  // radioB.setSyncWord(syncWord);
  Serial.println("LoRa Initializing OK!");

}

void loop() {


  // Radio A 
  int packetSizeA = radioA.parsePacket();
  if (packetSizeA) {
    // received a packet
    Serial.print("'");

    // read packet
    while (radioA.available()) {
      Serial.print((char)radioA.read());
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.print(",");
    Serial.print(radioA.packetRssi());
    Serial.print(",");
    // print Freq Error of packet
    Serial.print(" with Error ");
    Serial.print(",");
    Serial.print(radioA.packetFrequencyError());
    Serial.print(",");
    // print SNR of packet
    Serial.print(" with SNR ");
    Serial.print(",");
    Serial.println(radioA.packetSnr());
  }

}