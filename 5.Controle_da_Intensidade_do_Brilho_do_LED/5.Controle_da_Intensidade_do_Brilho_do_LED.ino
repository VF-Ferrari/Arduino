int pinoLed = 11;  // configura a porta 11 como pino do LED

void setup() {  // configura pino do LED como saída
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  acendeBrilho(5);
  apagaBrilho(5);
}

void acendeBrilho(int increamento) {  // muda o brilho pelo loop for
  for (byte value = 0; value < 255; value += increamento) {
    analogWrite(pinoLed, value);  // controla o brilho no pino do LED
    delay(30);
  }
}

void apagaBrilho(int decreamento) {                          // muda o brilho pelo loop for
  for (byte value = 255; value > 0; value -= decreamento) {  // controla o brilho no pino do LED
    analogWrite(pinoLed, value);
    delay(30);
  }
}