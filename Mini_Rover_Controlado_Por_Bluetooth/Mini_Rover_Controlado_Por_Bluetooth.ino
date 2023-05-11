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

int k;

void setup() {
  pinMode(3, OUTPUT);   //definicao do pino 3 como saida
  pinMode(10, OUTPUT);  //definicao do pino 4 como saida
  pinMode(5, OUTPUT);   //definicao do pino 5 como saida
  pinMode(6, OUTPUT);   //definicao do pino 6 como saida
  pinMode(7, OUTPUT);   //definicao do pino 7 como saida
  pinMode(8, OUTPUT);   //definicao do pino 8 como saida
  pinMode(9, OUTPUT);   //definicao do pino 9 como saida

  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);

  Serial.begin(9600);  //velocidade de comunicacao bluetooth
}


void loop() {

  char c = Serial.read();  //leitura do valor enviado pelo bluetooth


  if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') {

    k = c;
    delay(10);
    k = map(k, 48, 57, 50, 255);
    delay(10);
    Serial.print("PWM igual a:");
    Serial.print(k);
  }

  if (c == 'F') {
    analogWrite(3, k);  //CARRINHO PRA FRENTE
    digitalWrite(4, LOW);
    analogWrite(5, k);
    digitalWrite(6, LOW);
  }

  if (c == 'B') {
    analogWrite(3, k);  //CARRINHO PRA TRAS
    digitalWrite(4, HIGH);
    analogWrite(5, k);
    digitalWrite(6, HIGH);
  }
  if (c == 'R') {
    analogWrite(3, k);  //CARRINHO PRA ESQUERDA
    digitalWrite(4, HIGH);
    analogWrite(5, k);
    digitalWrite(6, LOW);
  }
  if (c == 'L') {
    analogWrite(3, k);  //CARRINHO PRA DIREITA
    digitalWrite(4, LOW);
    analogWrite(5, k);
    digitalWrite(6, HIGH);
  }

  if (c == 'I') {
    analogWrite(3, 0);  //CARRINHO PRA FRENTE ESQUERDA
    digitalWrite(4, LOW);
    analogWrite(5, k);
    digitalWrite(6, LOW);
  }
  if (c == 'G') {
    analogWrite(3, k);  //CARRINHO PRA FRENTE DIREITA
    digitalWrite(4, LOW);
    analogWrite(5, 0);
    digitalWrite(6, LOW);
  }

  if (c == 'J') {
    analogWrite(3, 0);  //CARRINHO PRA TRAS ESQUERDA
    digitalWrite(4, LOW);
    analogWrite(5, k);
    digitalWrite(6, HIGH);
  }
  if (c == 'H') {
    analogWrite(3, k);  //CARRINHO PRA TRAS DIREITA
    digitalWrite(4, HIGH);
    analogWrite(5, 0);
    digitalWrite(6, LOW);
  }
  if (c == 'S') {
    analogWrite(3, 0);  //CARRINHO PARADO
    digitalWrite(4, 0);
    analogWrite(5, 0);
    digitalWrite(6, 0);
  }

  if (c == 'W') {
    //              digitalWrite(7,HIGH); //liga farol frente

    serv1.write(14);
    serv2.write(75);
    serv3.write(80);
    serv4.write(69);

    delay(500);

    serv1.write(14);
    delay(300);
    serv2.write(75);
    delay(300);
    serv3.write(79);
    delay(300);
    serv4.write(134);

    delay(500);

    serv1.write(14);
    delay(300);
    serv2.write(14);
    delay(300);
    serv3.write(172);
    delay(300);
    serv4.write(133);

    delay(500);

    serv1.write(23);
    delay(300);
    serv2.write(11);
    delay(300);
    serv3.write(170);
    delay(300);
    serv4.write(54);

    delay(500);

    serv1.write(53);
    delay(300);
    serv2.write(75);
    delay(300);
    serv3.write(173);
    delay(300);
    serv4.write(57);

    delay(500);

    serv1.write(52);
    delay(300);
    serv2.write(75);
    delay(300);
    serv3.write(173);
    delay(300);
    serv4.write(56);

    delay(500);

    serv1.write(13);
    delay(300);
    serv2.write(88);
    delay(300);
    serv3.write(82);
    delay(300);
    serv4.write(120);

    delay(500);

    serv1.write(13);
    delay(300);
    serv2.write(78);
    delay(300);
    serv3.write(77);
    delay(300);
    serv4.write(119);

    delay(500);

    serv1.write(13);
    delay(300);
    serv2.write(17);
    delay(300);
    serv3.write(83);
    delay(300);
    serv4.write(118);

    delay(500);
  }
  //if (c == 'w'){
  //              digitalWrite(7,LOW);  //desliga farol frente
  //}
  //if (c == 'U'){
  //              digitalWrite(8,HIGH) ;//liga farol tras
  //}
  //if (c == 'u'){
  //              digitalWrite(8,LOW) ; //desliga farol tras
  //}
  //if (c == 'V'){
  //              digitalWrite(9,HIGH) ; //buzzer
  //}
  //if (c == 'v'){
  //              digitalWrite(9,LOW) ;  //buzzer
  //}
}