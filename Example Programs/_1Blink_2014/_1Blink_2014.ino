int led = 3;     //Declares Var led to pin 3
void setup()
{
  pinMode(led, OUTPUT);    //Declares pin 3 to be an output   
}
for(x, x < 10, x++)   //repeats while x is < 10 x goes up by a constant 1
{
  digitalWrite(led, HIGH); //sets led on HIGH
  delay(1000);    //waits 1 sec
  digitalWrite(led, LOW);    //sets led to LOW
  delay(1000);   //waits 1 sec
}
