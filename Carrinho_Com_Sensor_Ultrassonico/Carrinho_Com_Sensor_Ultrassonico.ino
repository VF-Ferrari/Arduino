#define DF 13
#define EF 12
#define DT 11
#define ET 10
#define trigger 9
#define echo 8

double distancia;
double tempo;

void setup() {
  pinMode(DF, OUTPUT);
  pinMode(DT, OUTPUT);
  pinMode(EF, OUTPUT);
  pinMode(ET, OUTPUT);
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tempo = pulseIn(echo, HIGH);
  tempo = tempo / 1000000;
  distancia = (tempo * 340) * 100 / 2;
  digitalWrite(DF, HIGH);
  digitalWrite(EF, HIGH);
  digitalWrite(ET, LOW);
  digitalWrite(DT, LOW);
  if (distancia < 15) {
    if (random(1, 3) == 1) {
      digitalWrite(DT, HIGH);
      digitalWrite(EF, HIGH);
      digitalWrite(ET, LOW);
      digitalWrite(DF, LOW);
      delay(500);
    } else {
      digitalWrite(DF, HIGH);
      digitalWrite(ET, HIGH);
      digitalWrite(EF, LOW);
      digitalWrite(DT, LOW);
      delay(500);
    }
  }
}