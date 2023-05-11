int led_R = 7;  // pino LED Vermelho (R)
int led_G = 6;  // pino LED Verde (G)
int led_B = 5;  // pino LED Azul (B)

void setup() {
  pinMode(led_R, OUTPUT);  // Definimos os pinos como saida
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  apagaLed();
}

void loop() {
  acendeVermelho();  // aqui fizemos uma pequena funcao que acende uma cor e apaga as outras
  delay(1000);
  acendeVerde();
  delay(1000);
  acendeAzul();
  delay(1000);
  apagaLed();
  delay(1000);
}

void acendeVermelho() {
  digitalWrite(led_R, HIGH);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, LOW);
}

void acendeVerde() {
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, HIGH);
  digitalWrite(led_B, LOW);
}

void acendeAzul() {
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, HIGH);
}

void apagaLed() {
  digitalWrite(led_R, LOW);
  digitalWrite(led_G, LOW);
  digitalWrite(led_B, LOW);
}