#include <Servo.h>
/* Prototipo da funcao */
int calcDistancia();
/* Pinos utilizados */
const int trigPin = 11;
const int echoPin = 10;

uint32_t tempo;
int distancia;

Servo servo;
/**
 * @brief Setup
 */
void setup(void) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servo.attach(9);
}
/**
 * @brief Loop
 */
void loop(void) {
  for (int i = 15; i <= 165; i++) {
    servo.write(i);
    delay(30);
    distancia = calcDistancia();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }

  for (int i = 165; i > 15; i--) {
    servo.write(i);
    delay(30);
    distancia = calcDistancia();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distancia);
    Serial.print(".");
  }
}
/**
 * @brief Emite um sinal sonoro e calcular a distancia
 * @return int distancia
 */
int calcDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  tempo = pulseIn(echoPin, HIGH);

  distancia = tempo * 0.034 / 2;
  return distancia;
}