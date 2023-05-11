// inclui bibilioteca do servomotor
#include <Servo.h>

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// nomeia os servos
Servo serv1, serv2, serv3, serv4;

// cria as variavies dos angulos de cada motor
int motor1, motor2, motor3, motor4;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 1000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600);

  // atribui pinos dos servos
  serv1.attach(pinServ1);  // Base
  serv2.attach(pinServ2);  // Esquerda
  serv3.attach(pinServ3);  // Direita
  serv4.attach(pinServ4);  // Garra
}

void loop() {

  serv1.write(75);  // Base
  serv2.write(30);  // Esquerda
  serv3.write(75);  // Direta
  serv4.write(80);  // Garra

  serv1.write(127);
  delay(300);
  serv2.write(92);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(85);

  delay(1000);

  serv1.write(171);
  delay(300);
  serv2.write(92);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(85);

  delay(1000);

  serv1.write(171);
  delay(300);
  serv2.write(92);
  delay(300);
  serv3.write(10);
  delay(300);
  serv4.write(85);

  delay(1000);

  serv1.write(171);
  delay(300);
  serv2.write(92);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(85);

  delay(1000);

  serv1.write(127);
  delay(300);
  serv2.write(170);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(85);

  delay(1000);

  serv1.write(127);
  delay(300);
  serv2.write(170);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(0);

  delay(1000);

  serv1.write(150);
  delay(300);
  serv2.write(170);
  delay(300);
  serv3.write(95);
  delay(300);
  serv4.write(0);

  delay(1000);

  serv1.write(150);
  delay(300);
  serv2.write(110);
  delay(300);
  serv3.write(10);
  delay(300);
  serv4.write(0);

  delay(2000);
}
