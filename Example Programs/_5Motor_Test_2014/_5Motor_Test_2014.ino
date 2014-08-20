/* This program is intended to test that the motors turn on when requested.  
 This program is using digital output to activate the motors.  we will be discussing
 the difference between analog and digital output.
 
 You might already have an idea of what a variable 
 is in math. In programming, a variable is a word with 
 just use the number 0, instead.
 */

// Declarations; defines the variables and initial states
const int motor1 = 0;      // motor1 connected to analog pin 0
const int motor2 = 1;      // motor1 connected to analog pin 1
int counter = 0;

// Setup: Runs only once and defines the pins to be used
void setup()  { 
  // initialize the digital pins 0 and 1 as an output.
  pinMode(motor1, OUTPUT);   // sets the pin0 as output
  pinMode(motor2, OUTPUT);   // sets the pin1 as output
} 

// Loop: cycles through this loop over and over
void loop()  { 
  digitalWrite(0, HIGH); //Turns motors on full power 
  digitalWrite(1, HIGH); //Turns motors on full power  
  delay(1);   
  counter = counter +1;  //Loop counter.  Declared to start at 0       
  if (counter > 40){
    // When counter is >40 then it will execute code below in brackets
    // This code shuts the motor off
    digitalWrite(0, LOW); 
    digitalWrite(1, LOW); 
    delay(10000); 
  }
  else {
    // When counter is <40 then it will execute code below in brackets
    /*In digital output, the only way to control power to the motor is to turn it on
     and off quickly.  below we are running the motor at 40% since we are turning it off
     for 60ms and then turning it on for 40ms */
    digitalWrite(0, LOW); 
    digitalWrite(1, LOW);   
    delay(60);  
    digitalWrite(0, HIGH); 
    digitalWrite(1, HIGH);   
    delay(40); 
  }  
}




