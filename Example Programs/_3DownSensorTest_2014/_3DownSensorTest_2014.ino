//This example code is in the public domain.

//If it doesn't work, take off the front sensor.
//If that sensor sees you it will mess up the whole thing.
 

 #include "DigiKeyboard.h" 
 

int down_sensor_val = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs.
  pinMode(3,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  int down_sensor_val = analogRead(1);    //sets value of down sensor to pin 1
//  DigiKeyboard.println(down_sensor_val);   //reads and writes values of var down sensor
  
  if (down_sensor_val > 500)    //while var down sensor is > 500 then do,
  {  
    digitalWrite(3,HIGH);   //sets pin 3 to HIGH
    delay(100);   //waits .1sec
    digitalWrite(3,LOW);   //sets pin 3 to HIGH
    delay(100);  //waits pin .1sec
  }
  else     //if var down sensor is < 500 then do,
  {    
    digitalWrite(3,LOW);    //sets pin 3 to LOW
  }
  

  //DigiKeyboard.println(front_sensor_val);
}
