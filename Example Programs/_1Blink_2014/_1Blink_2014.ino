int led = 3;     //Declares Var led to pin 3
void setup()
{
  pinMode(led, OUTPUT);    //Declares pin 3 to be an output   
}
void loop()
  digitalWrite(led, HIGH); //sets led on HIGH
  delay(500);    //waits 1 sec
  digitalWrite(led, LOW);    //sets led to LOW
  delay(500);   //waits 1 sec
}
