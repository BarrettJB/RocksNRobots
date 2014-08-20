/*

  This example code is in the public domain.
 */
 
 #include "DigiKeyboard.h" 
 
int front_sensor_val = 0; 


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs.
  pinMode(3,OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {

  int front_sensor_val = analogRead(2);  
  
  if (front_sensor_val > 500){
    digitalWrite(3,HIGH);
    delay(100);
    digitalWrite(3,LOW);
    delay(100);}
  else{
    digitalWrite(3,LOW);}
  
  //DigiKeyboard.println(down_sensor_val);
  //DigiKeyboard.println(front_sensor_val);
}
