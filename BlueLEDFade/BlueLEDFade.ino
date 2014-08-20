#include "DigiKeyboard.h"
void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
   for(int z=0;z<256;z++){
    //analogWrite(1,z);
    analogWrite(2,z);
    delay(10);
    DigiKeyboard.println(z);
  }
}
