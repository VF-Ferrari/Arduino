void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite (13, HIGH);
  delay (250);                         // Wait for 500 millisecond(s)
  digitalWrite (13, LOW);
  delay (250);                         // Wait for 500 millisecond(s)
}
