/*

  This example code is in the public domain.
  Display the altitude in cm.
  
  Digikeyboard cannot be used if you are using the pin 3 LED.
 */
 
 

int down_sensor_val = 0; // Variable to keep track of the down facing sensor
int altimeter_val = 0;
int AltErr = -0;
int AltGoal = 80;
int LastAlt = 80; // The goal altitude, in centimeters. You can mess with this.
int counter = 0;
int trim = 12;
int yaw_rate;
int scan = 0;  //Declared: Used for RH_LH Scan of Front Sensor
int scanDir = 1; //Declared: Used for RH_LH Scan of Front Sensor
int scan2 = 0; //Declared: Used for RH_LH Scan of Front Sensor
int scan2Dir = 1; //Declared: Used for RH_LH Scan of Front Sensor
long VCCmV = 3500;
const int led = 3;
const int motor1 = 0;      // motor1 connected to analog pin 7
const int motor2 = 1;      // motor1 connected to analog pin 8
int ALTIMETER_PIN = 1;  //Downsensor pin location
int FRONT_SENSOR_PIN = 2;  //Frontsensor pin location
int GYRO_SENSOR_PIN = 0;  // Input signal for gyro value
int basespeed = 190;
int motor1basespeed = 170; // these numbers will need to be tweaked for your
int motor2basespeed = 135; // specific heli - the default value is 135 for both.
int normmotor1speed;
int normmotor2speed;
int base_gyro_val;
int rudder;

/*Take note that motor1 is the bottom rotor, and motor2 is the upper rotor.
  having the upper rotor (motor2) moving faster than the other will cause
  the helo to spin counterclockwise. Likewise, having the bottom rotor, 
  operated by motor1 moving faster, will make the heli spin clockwise.


// the setup routine runs once when you press reset: */
void setup() 
{                
  // initialize the outputs.
  pinMode(4, INPUT);
  pinMode(5, INPUT);  
  pinMode(led, OUTPUT);      // sets the pin as output
  pinMode(motor1, OUTPUT);   // sets the pin as output
  pinMode(motor2, OUTPUT);   // sets the pin as output 

  analogWrite(motor1, 255); 
  analogWrite(motor2, 255); 
  delay(200); 
  //digitalWrite(led, HIGH);
  int base_gyro_val = analogRead(GYRO_SENSOR_PIN);
  delay(100);
}  
// the loop routine runs over and over again forever:
void loop() 
{
  for(int counter = 0; counter < 1000; counter++)
  {
     VCCmV = ((VCCmV*95)/100); 
     VCCmV = (VCCmV + (readVcc()/100)*5);
     
     int altimeter_val = 23000/(55 +analogRead(ALTIMETER_PIN));
     int front_sensor_val = 7800/(1+analogRead(FRONT_SENSOR_PIN));
     int gyro_sensor_val = analogRead(GYRO_SENSOR_PIN); 
     
     AltErr = (2*(AltGoal - altimeter_val) + 6*(LastAlt - altimeter_val));
     if (AltErr > 80){AltErr = 80;}
     if (AltErr < -50){AltErr = -50;}    
           
     LastAlt = altimeter_val;       
     
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
     //yaw_rate = 0; 
     //yaw_rate = (base_gyro_val - gyro_sensor_val);      
     yaw_rate = (((base_gyro_val+rudder) - gyro_sensor_val));     
     //yaw_rate = (((base_gyro_val+rudder+scan/2) - gyro_sensor_val)); 
     //yaw_rate = (((base_gyro_val+rudder+scan/2+scan2/20) - gyro_sensor_val)); 
     
   motor1basespeed = basespeed + ((basespeed*trim)/200) + ((basespeed*yaw_rate)/100);    
   motor2basespeed = basespeed - ((basespeed*trim)/200) - ((basespeed*yaw_rate)/100); 
 
   //motor1basespeed = basespeed + ((basespeed*trim)/200);    
   //motor2basespeed = basespeed - ((basespeed*trim)/200); 
   
    normmotor1speed =int(((long(motor1basespeed))*long(1330))/(VCCmV-2025));    
    normmotor2speed =int(((long(motor2basespeed))*long(1330))/(VCCmV-2025)); 
      
    analogWrite(motor1, normmotor1speed + AltErr); 
    analogWrite(motor2, normmotor2speed + AltErr);      
        
    delay(10);
  }  
  for(int counter = normmotor1speed; counter <= 180; counter = counter -1)
  {
    analogWrite(motor1, counter);  // gradually slows motors, keeping heli from plummeting,
    analogWrite(motor2, counter);  // which you just hate to see it do every time
    delay(10);
  }
  analogWrite(motor1, 0);  // shuts off motors
  analogWrite(motor2, 0);  
  
  delay(10000);  // waits for 10 seconds before starting again
}

long readVcc() 
{
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

