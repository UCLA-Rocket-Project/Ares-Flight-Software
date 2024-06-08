
// #include <Arduino.h>
// #include "HAL.h"
// #include <../lib/Ethernet/Ethernet2.h>

// int count;
// EthernetUDP Udp;
// // EthernetClass lol;
// byte default_mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x99};
// IPAddress mac_IP(10, 0, 0, 11);
// IPAddress ip(10, 0, 0, 99);
// uint8_t ha[4] = {10, 0, 0, 99};
// int port = 42069;

// char ReplyBuffer[] = "acknowledged";  
// char packetBuffer[255]; //buffer to hold incoming packet

// char ipBuffer[255]; 

// void setup()
// {
//   Serial.begin(115200);

//   HAL::initSensorHAL();
//   Ethernet.init(HAL::W5500_CS);
//   Ethernet.begin((uint8_t *)default_mac, ip, HAL::sensorSPI);
//   Udp.begin(port);
//   w5500.getGatewayIp(ipBuffer);
//   Serial.println(ipBuffer);
//   // Serial.println(w5500.getIPAddress());
//   // Udp.beginPacket(mac_IP, port);
// }

// void loop()
// {
//   // if (Ethernet.) {
//   // if (Udp.parsePacket()) {
//   //   long bruh = micros();
//   //   Udp.read(packetBuffer, sizeof(Comms::Packet));
//   //   Serial.printf("Recieved: %s delta: %ld \n", packetBuffer, micros() -  bruh);
//   // }
//   Udp.beginPacket(mac_IP, port);
//   Udp.write(ReplyBuffer);
//   Udp.endPacket();

//   Serial.println("Sent");
//   Udp.parsePacket();
//   int len = Udp.read(packetBuffer, 255);

//   if (len > 0) {

//     packetBuffer[len] = 0;

//   }

//   Serial.println("Contents:");

//   Serial.println(packetBuffer);


//   delay(1000);
// }

// // #include "../lib/Ethernet/utility/w5500.h"

// // W5500Class chip;
// // uint8_t ver;


// // void setup() {
// //   Serial.begin(115200);

// //   HAL::initSensorHAL();

// //   chip.init(HAL::W5500_CS, HAL::sensorSPI);
// //   ver = chip.readVersion();


// // }

// // void loop() {
// //     Serial.println(ver);
// //     delay(1000);  
// // }


// // #include "globals.h"
// // #include "HAL.h"
// // #include <Arduino.h>



// // void setup() {
// //   Serial.begin(115200);

// //   HAL::initSensorHAL();


// // }

// // void loop() {
// //     Serial.println("hi");
// //     delay(1000);  
// // }
