#include <Stepper.h>
int passosPorVolta=32; // Quanstos passos o motor é capaz de dar em uma volta
Stepper mp(passosPorVolta, 8, 9, 10, 11);

void setup() {
  mp.setSpeed(500);   // Velocidade do motor em RPM
}

void loop() {
  mp.step(2048);     // Passos que o motor vai dar -> Volta completa (360°)
  delay(500);        // Pausa
  mp.step(-2048);    // Passos que o motor vai dar -> Volta completa no sentido inverso
  delay(500);        // Pausa
}