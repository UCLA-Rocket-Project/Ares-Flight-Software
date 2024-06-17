


// ACTUAL CODE

#include <Arduino.h>
#include "HAL.h"
#include "../../Libraries/Ethernet/Ethernet.h"

int count;
EthernetUDP Udp;
// EthernetClass lol;

byte default_mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x99};
IPAddress mac_IP(10, 0, 0, 11);
IPAddress windows_IP(169, 254, 43, 105);
IPAddress ip(10, 0, 0, 99);
IPAddress dns(169, 254, 43, 1);
IPAddress gateway(169, 254, 43, 2);
IPAddress subnet(255, 255, 0, 0);

int port = 42069;

char ReplyBuffer[] = "acknowledged";  
char packetBuffer[255]; //buffer to hold incoming packet

char ipBuffer[255]; 

void setup()
{
  Serial.begin(115200);

  HAL::initSensorHAL();
  Ethernet.init(HAL::W5500_CS, HAL::sensorSPI);
  // Ethernet.begin((uint8_t *)default_mac, ip, dns, gateway, subnet);
   Ethernet.begin(default_mac, ip);
  // DEBUGLN(Ethernet.hardwareStatus() == EthernetW5500);
  

  if (Ethernet.linkStatus() == LinkOFF) {
    DEBUGLN("Ethernet cable is not connected.");
  }

  Udp.begin(port);

  // if (W5100.getChip() == 55)
  //   DEBUGLN("w5500");
  // Serial.println(w5500.getIPAddress());
  // Udp.beginPacket(mac_IP, port);
}

// void loop()
// {
//   // if (Ethernet.) {
//   // if (Udp.parsePacket()) {
//   //   long bruh = micros();
//   //   Udp.read(packetBuffer, sizeof(Comms::Packet));
//   //   Serial.printf("Recieved: %s delta: %ld \n", packetBuffer, micros() -  bruh);
//   // }
//   Udp.beginPacket(windows_IP, port);
//   Udp.write(ReplyBuffer);
//   Udp.endPacket();

//   // Serial.println("Sent");
//   // Udp.parsePacket();
//   // int len = Udp.read(packetBuffer, 255);

//   // if (len > 0) {

//   //   packetBuffer[len] = 0;

//   // }

//   // Serial.println("Contents:");

//   // Serial.println(packetBuffer);


//   delay(1000);
// }

void loop() {
  // if there's data available, read a packet
  Serial.println("Sending...");
  int status = Udp.beginPacket(windows_IP, port);
  Serial.println(status);
  Udp.write("HELLO???",8);
  Udp.endPacket();
  // int packetSize = Udp.parsePacket();
  // if (packetSize) {
  //   Serial.print("Received packet of size ");
  //   Serial.println(packetSize);
  //   Serial.print("From ");
  //   IPAddress remote = Udp.remoteIP();
  //   for (int i=0; i < 4; i++) {
  //     Serial.print(remote[i], DEC);
  //     if (i < 3) {
  //       Serial.print(".");
  //     }
  //   }
  //   Serial.print(", port ");
  //   Serial.println(Udp.remotePort());

  //   // read the packet into packetBuffer
  //   Udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
  //   Serial.println("Contents:");
  //   Serial.println(packetBuffer);

  //   // send a reply to the IP address and port that sent us the packet we received
  //   Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
  //   Udp.write(ReplyBuffer);
  //   Udp.endPacket();
  // }
  delay(1000);
}






















// // #include "../../Libraries/Ethernet/utility/w5100.h"
// // #include <Arduino.h>
// // #include "HAL.h"

// // W5100Class chip;
// // uint8_t ver;


// // void setup() {
// //   Serial.begin(115200);

// //   HAL::initSensorHAL();

// //   chip.init(HAL::W5500_CS, HAL::sensorSPI);
// //   if (chip.getChip() == 55)
// //     DEBUGLN("w5500");

// // }

// // void loop() {
// //     // Serial.println(ver);
// //     delay(1000);  
// // }

