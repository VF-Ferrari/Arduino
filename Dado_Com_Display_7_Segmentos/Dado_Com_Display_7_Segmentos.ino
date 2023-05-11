#define botao 10
#define A 3
#define B 2
#define C 7
#define D 8
#define E 9
#define F 4
#define G 5
#define ponto 6

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(ponto, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  randomSeed(analogRead(0));  //Escolher um número qualquer
}

void inicio() {
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(ponto, HIGH);
  delay(150);
  digitalWrite(ponto, LOW);
  delay(150);
  digitalWrite(ponto, HIGH);
  delay(150);
  digitalWrite(ponto, LOW);
  delay(150);
  digitalWrite(ponto, HIGH);
  delay(150);
  digitalWrite(ponto, LOW);
  delay(150);
  digitalWrite(ponto, HIGH);
  delay(150);
  digitalWrite(ponto, LOW);
}

void numero(int x) {
  switch (x) {
    case 1:
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      break;
    case 2:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
    case 3:
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 4:
      digitalWrite(B, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(F, HIGH);
      break;
    case 5:
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      break;
    case 6:
      digitalWrite(A, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      break;
  }
}

void loop() {
  if (!digitalRead(botao)) {
    inicio();
    numero(random(1, 7));  //Escolher 7 para ele sortear até o número 6 (n-1)
  }
}