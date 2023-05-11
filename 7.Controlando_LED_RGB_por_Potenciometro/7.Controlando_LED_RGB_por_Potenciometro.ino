int led_R = 7;  // pino LED Vermelho (R)
int led_G = 6;  // pino LED Verde (G)
int led_B = 5;  // pino LED Azul (B)
int pot = A0;
int valorPot;

void setup() {
  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_B, OUTPUT);
  apagaLed();
}

void loop() {
  valorPot = analogRead(pot);            // lê o valor do potenciômetro (de 0 a 1023)
  if (valorPot >= 0 && valorPot <= 256)  // menor que 256 apaga o LED
  {
    apagaLed();
  }
  if (valorPot > 256 && valorPot <= 512)  // entre 256 e 512, acende vermelho
  {
    acendeVermelho();
  }
  if (valorPot > 512 && valorPot <= 768)  // entre 512 e 768, acende verde
  {
    acendeVerde();
  }
  if (valorPot > 768 && valorPot <= 1023)  // entre 768 e 1023, acende azul
  {
    acendeAzul();
  }
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