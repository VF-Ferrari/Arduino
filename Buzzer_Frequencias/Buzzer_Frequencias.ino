int buzzer = 6;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, 2500, 100);
  delay(200);

  tone(buzzer, 4000, 100);
  delay(200);

  tone(buzzer, 4500, 100);
  delay(200);

  tone(buzzer, 3000, 100);
  delay(200);

  tone(buzzer, 2000, 100);
  delay(200);

  tone(buzzer, 4300, 100);
  delay(200);

  tone(buzzer, 5500, 100);
  delay(200);

  tone(buzzer, 2700, 100);
  delay(200);

  tone(buzzer, 4000, 100);
  delay(200);
}
