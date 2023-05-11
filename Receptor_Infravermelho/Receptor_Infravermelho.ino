//Usar a biblioteca na versão 2.7.0

#include <IRremote.h>
#define receptor 11

IRrecv recIR(receptor);
decode_results resultado;

void setup() {
  Serial.begin(9600);  // inicializa o mostrador da IDE do arduino
  recIR.enableIRIn();  // Inicializa recpetor IR
  recIR.blink13(true);
}

void loop() {
  if (recIR.decode(&resultado)) {
    Serial.print("Valor: ");
    Serial.println(resultado.value, HEX);
    recIR.resume();
  }
}