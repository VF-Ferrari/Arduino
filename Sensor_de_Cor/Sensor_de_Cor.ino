#define pinS0 0
#define pinS1 1
#define pinS2 2
#define pinS3 3
#define pinOut 4
#define pinLED 5

//Pinos dos LEDs
#define pinoLedVerm 11
#define pinoLedVerd 12
#define pinoLedAzul 13

unsigned int valorVermelho = 0;
unsigned int valorVerde = 0;
unsigned int valorAzul = 0;
unsigned int valorBranco = 0;

void detectaCor();

void setup() {
  pinMode(pinS0, OUTPUT);
  pinMode(pinS1, OUTPUT);
  pinMode(pinS2, OUTPUT);
  pinMode(pinS3, OUTPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinOut, INPUT);

  pinMode(pinoLedVerm, OUTPUT);
  pinMode(pinoLedVerd, OUTPUT);
  pinMode(pinoLedAzul, OUTPUT);

  Serial.begin(9600);
  digitalWrite(pinS0, HIGH);
  digitalWrite(pinS1, LOW);

  delay(2000);
  //Liga LED
  digitalWrite(pinLED, HIGH);
}

void loop() {
  //Detecta a cor
  detectaCor();

  //Mostra valores no serial monitor
  Serial.print("Vermelho :");
  Serial.print(valorVermelho);

  Serial.print(" Verde : ");
  Serial.print(valorVerde);

  Serial.print(" Azul : ");
  Serial.print(valorAzul);

  Serial.print(" Branco : ");
  Serial.print(valorBranco);
  Serial.println();

  //Verifica se a cor vermelha foi detectada
  if ((valorVermelho < valorAzul) && (valorVermelho < valorVerde) && (valorBranco < 100)) {
    Serial.println("Vermelho");
    digitalWrite(pinoLedVerm, HIGH);  //Acende o led vermelho
    digitalWrite(pinoLedVerd, LOW);
    digitalWrite(pinoLedAzul, LOW);

  } else if ((valorAzul < valorVermelho) &&  //Verifica se a cor azul foi detectada
             (valorAzul < valorVerde) && (valorBranco < 100)) {
    Serial.println("Azul");
    digitalWrite(pinoLedVerm, LOW);
    digitalWrite(pinoLedVerd, LOW);
    digitalWrite(pinoLedAzul, HIGH);  //Acende o led azul

  } else if ((valorVerde < valorVermelho) &&  //Verifica se a cor verde foi detectada
             (valorVerde < valorAzul) && (valorBranco < 100)) {
    Serial.println("Verde");
    digitalWrite(pinoLedVerm, LOW);
    digitalWrite(pinoLedVerd, HIGH);  //Acende o led verde
    digitalWrite(pinoLedAzul, LOW);
  }
  Serial.println();

  //Delay para apagar os leds e reiniciar o processo
  delay(50);
  digitalWrite(pinoLedVerm, LOW);
  digitalWrite(pinoLedVerd, LOW);
  digitalWrite(pinoLedAzul, LOW);
}


// *********** Função de leitura so sensor de cor ********************
void detectaCor() {
  //Vermelho
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, LOW);
  valorVermelho = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);

  //Sem filtro
  digitalWrite(pinS2, HIGH);
  valorBranco = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);

  //Azul
  digitalWrite(pinS2, LOW);
  digitalWrite(pinS3, HIGH);
  valorAzul = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);

  //Verde
  digitalWrite(pinS2, HIGH);
  valorVerde = pulseIn(pinOut, digitalRead(pinOut) == HIGH ? LOW : HIGH);
}