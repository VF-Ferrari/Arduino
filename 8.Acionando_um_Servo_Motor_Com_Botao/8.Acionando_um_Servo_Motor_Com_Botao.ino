#include <Servo.h>

Servo meuServo;
int botao = 7;

void setup() {
  pinMode(botao, INPUT_PULLUP);  // define o botão como saidas
}

void loop() {
  meuServo.attach(9);
  if (digitalRead(botao) == LOW) {
    for (int angulo = 0; angulo <= 180; angulo++)  // aumenta o angulo do servo ate chegar em 180 graus
    {
      meuServo.write(angulo);
      delay(10);
    }
    for (int angulo = 180; angulo >= 0; angulo--)  // diminui o angulo do servo
    {
      meuServo.write(angulo);
      delay(10);
    }
  }
  meuServo.detach();
}