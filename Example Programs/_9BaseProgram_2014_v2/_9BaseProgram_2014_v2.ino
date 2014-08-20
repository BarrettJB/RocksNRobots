/* You might already have an idea of what a variable 
 is in math. In programming, a variable is a word with 
 just use the number 0, instead.
 */
// ******* Different naming conventions between analog to digital signals
// ******* Investigate variables being defined as const vs int
// ******* should the declarations be in void setup or above?

const int led = 3;
const int motor1 = 0;      // motor1 connected to analog pin 7?
const int motor2 = 1;      // motor1 connected to analog pin 8?
int ALTIMETER_PIN = 1;  //Downsensor pin location
int FRONT_SENSOR_PIN = 2;  //Frontsensor pin location
int GYRO_SENSOR_PIN = 0;  // Input signal for gyro value
int altimeter_val = 0;  //Declare variable: measured altimeter value in code.  Initialized at 0
int front_sensor_val = 0; //Declare variable: measured front sensor value in code.  Initialized at 0
int gyro_sensor_val = 0; //Declare variable: measured gyro value in code.  Initialized at 0
int basespeed = 165;  //#Declare variable: Startup Power setting. Using value from ***Motor Test Experiment
int helispeed = 135; 
int helispeed7 = 135;
int helispeed8 = 135;
int normhelispeed7 = 135;
int normhelispeed8 = 135;
long VCCmV = 3500; //Declare variable: Initial value set 3500 as close to fully charge battery
int rudder = 0;  //Declare variable: 
int trim = 15;//#Set by user: smaller is CCW. make sure both props spin freely. 
int yaw_rate = 0; 
int AltGoal = 100; //#Set by user: roughly in cm to determine free flight height off ground 
int AltErr = -18; //Declared: Difference between current altimeter_val and AltGoal
int scan = 0;  //Declared: Used for RH_LH Scan of Front Sensor
int scanDir = 1; //Declared: Used for RH_LH Scan of Front Sensor
int scan2 = 0; //Declared: Used for RH_LH Scan of Front Sensor
int scan2Dir = 1; //Declared: Used for RH_LH Scan of Front Sensor
int fadeAmount = 5;    // how many points to fade the LED by??????????????????????
int counter = 0; //Declared: Used for looping exercises within the code



void setup()  { 
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);    // sets the pin as output as RED led out
  pinMode(motor1, OUTPUT);   // sets the pin as output 
  pinMode(motor2, OUTPUT);   // sets the pin as output
  pinMode(ALTIMETER_PIN, INPUT); //sets the pin as input for downward sensor
  pinMode(FRONT_SENSOR_PIN, INPUT); //sets the pin as input for front sensor
  pinMode(GYRO_SENSOR_PIN, INPUT); //sets the pin as input for onboard gyro sensor
} 

void loop()  { 
  /* Obtaining initial gyro input value under full electrical load conditions. Soley for purposes of getting 
  initial gyro value.  USE SPIN TEST ON STUDENTS TO DEMONSTRATE THE GYRO*/
  
  digitalWrite(led, LOW); 
  delay(500);  
  analogWrite(motor1, 255); 
  analogWrite(motor2, 255); 
  delay(200); 
  //digitalWrite(led, HIGH);
  int base_gyro_val = analogRead(GYRO_SENSOR_PIN);
  delay(100);
  //analogWrite(motor1, 0); 
  //analogWrite(motor2, 0);
  //digitalWrite(led, LOW);
  //delay(100);
  
  while(1){
    VCCmV = ((VCCmV*99)/100); 
    VCCmV = (VCCmV + (readVcc()/100));

    int altimeter_val = 23000/(55 +analogRead(ALTIMETER_PIN));
    int front_sensor_val = 7800/(1+analogRead(FRONT_SENSOR_PIN));
    int gyro_sensor_val = analogRead(GYRO_SENSOR_PIN);
    
     AltErr = (AltGoal - altimeter_val)*3;
     
     if (AltErr > 30){       
     AltErr = 30;}
     if (AltErr < -20){       
     AltErr = -20;}   
     
     helispeed = basespeed + AltErr;
     
     if (front_sensor_val < 80)
     {
     // digitalWrite(5, HIGH);
     rudder = rudder - 1 ;
     } 
     else
     {
     // digitalWrite(5, LOW);
     if (rudder <= 0){
     rudder = rudder + 2;
     }
     }
     
     
     scan = scan + scanDir;
     
     
     if (scan == -100 || scan == 100) {
     scanDir = -scanDir ; 
     }     
     
     
     scan2 = scan2 + scan2Dir;
     
     
     if (scan2 == -1000 || scan2 == 1000) {
     scan2Dir = -scan2Dir ; 
     }     
     
     //yaw_rate = (((base_gyro_val+rudder+scan/2) - gyro_sensor_val)); 
     yaw_rate = (((base_gyro_val+rudder+scan/2+scan2/20) - gyro_sensor_val)); 
     
    //yaw_rate =  rudder/10; 
    //helispeed = basespeed;
    helispeed7 = helispeed + (helispeed*trim/200) + (helispeed*yaw_rate/100);    
    helispeed8 = helispeed - (helispeed*trim/200) - (helispeed*yaw_rate/100); 

    normhelispeed7 =int(((long(helispeed7))*long(1330))/(VCCmV-2025));    
    normhelispeed8 =int(((long(helispeed8))*long(1330))/(VCCmV-2025)); 


    if (normhelispeed7 > normhelispeed8){
      //digitalWrite(5, HIGH);
      if (normhelispeed7 > 255){
        digitalWrite(led, LOW);       
        normhelispeed8 = int(((long(normhelispeed8)) * long(255))/(long(normhelispeed7)));            
        normhelispeed7 = 255;
      }
      else {
        digitalWrite(led, LOW);
      }
    }

    if (normhelispeed8 > normhelispeed7){
      if (normhelispeed8 > 255){
        digitalWrite(led, LOW);       
        normhelispeed7 = int(((long(normhelispeed7)) * long(255))/(long(normhelispeed8)));   
        normhelispeed8 = 255;
      }
      else {
        digitalWrite(led, LOW);
      }
    }  

    if (normhelispeed8 == normhelispeed7){
      if (normhelispeed8 > 255){
        digitalWrite(led, LOW);       
        normhelispeed8 = 255;
        normhelispeed7 = 255; 
      }
      else {
        digitalWrite(led, LOW);
      }      
    }  

    analogWrite(motor1, normhelispeed7); 
    analogWrite(motor2, normhelispeed8);   

    //    analogWrite(7, 0); 
    //    analogWrite(8, 0);       

    counter = counter +1;         
    if (counter > 10000){
      analogWrite(motor1, 0);        
      analogWrite(motor2, 0);  
      delay(10000);  
    }
    if (VCCmV < 2300){
      analogWrite(motor1, 0);        
      analogWrite(motor2, 0); 
      // digitalWrite(5, HIGH);      
      delay(10000);  
      //delay(2000); 
    }

    //delay(200);                            
  }
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

