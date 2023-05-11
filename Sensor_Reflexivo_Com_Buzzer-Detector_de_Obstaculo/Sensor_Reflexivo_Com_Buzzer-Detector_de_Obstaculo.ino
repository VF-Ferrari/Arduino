#define pinSensor 5
#define pinBuzzer 6

unsigned long delayBuzzer;

void setup() {
  pinMode(pinSensor, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}

void loop() {
  bool sensor = digitalRead(pinSensor);

  if (!sensor) {
    if ((millis() - delayBuzzer) < 150) {
      digitalWrite(pinBuzzer, HIGH);
    } else {
      digitalWrite(pinBuzzer, LOW);
    }

    if ((millis() - delayBuzzer) > 600) {
      delayBuzzer = millis();
    }
  } else {
    digitalWrite(pinBuzzer, LOW);
  }
}