int led = 3;
void setup()
{
  pinMode(led, OUTPUT);     
}
for(x, x < 10, x++)
{
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
