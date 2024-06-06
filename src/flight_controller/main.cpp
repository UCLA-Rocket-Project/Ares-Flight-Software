#include <Arduino.h>
#include "globals.h"
#include "Radio.h"
// put function declarations here:
int myFunction(int, int);

void setup() {

  #ifdef DEBUG_MODE
    Serial.begin(115200);
  #endif
}

void loop() {
  DEBUGLN("1");
  delay(1000);


}
