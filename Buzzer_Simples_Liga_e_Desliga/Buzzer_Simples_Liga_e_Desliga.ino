int buzzer = 6;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {

  digitalWrite(buzzer, HIGH);
  delay(150);
  digitalWrite(buzzer, LOW);
  delay(1000);
}