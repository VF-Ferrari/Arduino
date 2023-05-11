int carroVermelho = 13;
int carroAmarelo = 12;
int carroVerde = 11;
int pedestreVermelho = 10;
int pedestreVerde = 9;
int botao = 2;

void setup() {
  pinMode(carroVermelho, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(pedestreVermelho, OUTPUT);
  pinMode(pedestreVerde, OUTPUT);
  pinMode(botao, INPUT);
}

void loop() {
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pedestreVermelho, HIGH);
  digitalWrite(pedestreVerde, LOW);

  if (digitalRead(botao) == HIGH) {
    digitalWrite(carroVerde, HIGH);
    digitalWrite(pedestreVermelho, HIGH);
    delay(50);
    digitalWrite(carroVerde, LOW);
    digitalWrite(carroAmarelo, HIGH);
    delay(3000);
    digitalWrite(carroAmarelo, LOW);
    digitalWrite(carroVermelho, HIGH);
    digitalWrite(pedestreVermelho, LOW);
    digitalWrite(pedestreVerde, HIGH);
    delay(5000);
    digitalWrite(pedestreVerde, LOW);
    digitalWrite(carroVermelho, HIGH);

    for (int x = 0; x < 10; x++) {
      digitalWrite(pedestreVermelho, HIGH);
      delay(500);
      digitalWrite(pedestreVermelho, LOW);
      delay(500);
    }
  }
}
