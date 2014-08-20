/*

  This example code is in the public domain.
 */
 
 #include "DigiKeyboard.h" 
 

int gyro_sensor_val = 0; 

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs.

  pinMode(1, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  int gyro_sensor_val = analogRead(0);
  DigiKeyboard.println(gyro_sensor_val);
}

