// inclui bibilioteca do servomotor
#include <Servo.h> 

// define pinos dos servos
#define pinServ1 2
#define pinServ2 3
#define pinServ3 4
#define pinServ4 5

// nomeia os servos
Servo serv1,serv2,serv3,serv4;

// cria as variavies dos angulos de cada motor
int motor1,motor2,motor3,motor4;

unsigned long mostradorTimer = 1;
const unsigned long intervaloMostrador = 1000;

void setup() {

  //inicia o monitor serial
  Serial.begin(9600); 

  // atribui pinos dos servos
  serv1.attach(pinServ1);
  serv2.attach(pinServ2);
  serv3.attach(pinServ3);
  serv4.attach(pinServ4);
  
}

void loop(){

  serv1.write (75); // base
  serv2.write (30); // esquerda
  serv3.write (75); // direta
  serv4.write (80); // garra

  delay (1000);

  /*serv1.write (75);
  serv2.write (79);
  serv3.write (75);
  serv4.write (06);

  delay (1000);

  serv1.write (75);
  serv2.write (79);
  serv3.write (150);
  serv4.write (06);

  delay (2000);

  serv1.write (75);
  serv2.write (79);
  serv3.write (150);
  serv4.write (06);

  delay (1000);

  serv1.write (75);
  serv2.write (79);
  serv3.write (150);
  serv4.write (80);

  delay (1000);

  serv1.write (75);
  serv2.write (30);
  serv3.write (80);
  serv4.write (06);

  delay (1000);

  serv1.write (75);
  serv2.write (30);
  serv3.write (180);
  serv4.write (06);

  delay (1000);

  serv1.write (75);
  serv2.write (79);
  serv3.write (80);
  serv4.write (06);

  delay (1000);*/

}
