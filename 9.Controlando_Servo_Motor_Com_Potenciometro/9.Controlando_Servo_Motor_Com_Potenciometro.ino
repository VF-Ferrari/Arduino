#include <Servo.h>

Servo meuServo;
int pinoPot = A0;
int valorPot;

void setup() {
  meuServo.attach(9);   //Conectar o servo na porta 9
}

void loop() {
  valorPot = analogRead(pinoPot);
  valorPot = map(valorPot, 0, 1023, 0, 180);  // mapeia os valores do potenciometro (entre 0 e 1023) para os valores do servo (entre 0 e 180)
  meuServo.write(valorPot);                   // manda o valor para o servo
  delay(15);
}