/*

  This example code is in the public domain.
  Display the altitude in cm.
  
  pin 3 led cant be set as output if you are using DigiKeyboard
 */
 
 //#include "DigiKeyboard.h" 
 

int down_sensor_val = 0;
int altimeter_val = 0;
int AltErr = -0;
int AltGoal = 80;
int counter = 0;
const int motor1 = 0;      // motor1 connected to analog pin 7
const int motor2 = 1;      // motor1 connected to analog pin 8

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs.
  //pinMode(3,OUTPUT);
  //pinMode(4, INPUT);
  //pinMode(5, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  //int down_sensor_val = analogRead(1);
  //DigiKeyboard.println(down_sensor_val);
  int altimeter_val = 23000/(55 +analogRead(1));
  //DigiKeyboard.println(altimeter_val);
  
 
     AltErr = (AltGoal - altimeter_val)*3;
    
       if (AltErr > 30){       
           AltErr = 30;}
       if (AltErr < -20){       
           AltErr = -20;}    
           
   counter = counter +1;      
   
    if (counter > 4000){
      analogWrite(motor1, 0); 
      analogWrite(motor2, 0);   
       delay(10000); }
    else {        
      analogWrite(motor1, 135 + AltErr); 
      analogWrite(motor2, 135 + AltErr);    
    }  
  delay(10);
     
    //DigiKeyboard.println(AltErr);      
}
