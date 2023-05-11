int pinoLed = 9;
int pinoSensor = 3;  // porta digital do sensor
int estadoSensor;

void setup() {
  pinMode(pinoSensor, INPUT);
  pinMode(pinoLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pinoSensor) == HIGH) {
    estadoSensor = digitalRead(pinoLed);
    digitalWrite(pinoLed, !estadoSensor);
    delay(200);
  }
}