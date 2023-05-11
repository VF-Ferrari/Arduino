#define botao1 13
#define botao2 12
#define led 10

void setup() {
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if (digitalRead(botao1) == LOW) {
    digitalWrite(led, HIGH);
  }
  if (digitalRead(botao2) == LOW) {
    digitalWrite(led, LOW);
  }
}
