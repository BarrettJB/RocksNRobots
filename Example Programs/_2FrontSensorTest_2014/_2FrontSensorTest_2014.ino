//This example code is in the public domain.
 
#include "DigiKeyboard.h" 
 
int front_sensor_val = 0; 


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs or inputs.
  pinMode(3,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {

  int front_sensor_val = analogRead(2);  //sets val of front sensor val to pin 2 values.
  
  if (front_sensor_val > 500)  //while te val of the front sensor is greater then 500 do,
  {    
    digitalWrite(3,HIGH);   //sets pin 3 to HIGH
    delay(100);  //waits .1sec
    digitalWrite(3,LOW);  //sets pin to LOW
    delay(100); //waits .1 sec
  }
  else{     //if it is < 500 do,
    digitalWrite(3,LOW);}    //sets pin 3 to LOW
  
  //DigiKeyboard.println(down_sensor_val);    //prints values from var down sensor
  //DigiKeyboard.println(front_sensor_val);   //prints values from var front sensor
}
