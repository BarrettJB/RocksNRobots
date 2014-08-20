  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
*/

/* This is where we declare the variables to be used in the program as well as setting their initial state */

int led = 3;

/* The setup routine runs once when the program starts.  This is where we define the input and output pins to be used in the program */

void setup() {                
  // initialize the digital pin as an output, which means we are sending information from the microprocessor to the LED
  pinMode(led, OUTPUT);     
}

/* the loop routine runs over and over again forever */

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level).  Remember: LED is really pin 3 and is an output
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

// Please note that the setup and loop need { and } to encase all of the code

