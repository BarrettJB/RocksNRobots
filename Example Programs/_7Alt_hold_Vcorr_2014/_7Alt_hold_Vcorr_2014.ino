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
long VCCmV = 3500;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the outputs.
  //pinMode(3,OUTPUT);
  //pinMode(4, INPUT);
  //pinMode(5, INPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  
   VCCmV = ((VCCmV*99)/100); 
   VCCmV = (VCCmV + (readVcc()/100));
    
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

long readVcc() {
  // Source: http://provideyourown.com/2012/secret-arduino-voltmeter-measure-battery-voltage/
  // Read 1.1V reference against AVcc
  // set the reference to Vcc and the measurement to the internal 1.1V reference
  #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    //DigiKeyboard.println(1);
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
     //DigiKeyboard.println(2);
     ADMUX = _BV(MUX5) | _BV(MUX0) ;
  #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
     //DigiKeyboard.println(3);
     ADMUX = _BV(MUX3) | _BV(MUX2);   
  #else
    //DigiKeyboard.println(4);
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #endif  
 
  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring
 
  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint8_t high = ADCH; // unlocks both
  
  long result = (high<<8) | low;
 //DigiKeyboard.println(result);8

  //result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
  result = 1211861L / result; 
  return result; // Vcc in millivolts
}
