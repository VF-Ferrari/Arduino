#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);

int IN1 = 7;
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int PWML = 9;
int PWMR = 10;
char comando;

void setup() {
  //Define os pinos como saida
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(PWML, OUTPUT);
  pinMode(PWMR, OUTPUT);
}

void loop() {

  while (Serial.available()) {

    comando = Serial.read();
    if (comando == 'F') {
      frente();
    } else if (comando == 'B') {
      tras();
    } else if (comando == 'L') {
      esquerda();
    } else if (comando == 'R') {
      direita();
    } else {
      parado();
    }
  }
}

void tras() {
  //Gira o Motor A e B no sentido horario
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void frente() {
  //Gira o Motor A e B no sentido anti-horario
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void esquerda() {
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {
  analogWrite(PWML, 180);
  analogWrite(PWMR, 180);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void parado() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
