#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigger 9     // Declara que o pino de trigger estará na porta 4
#define echo 8        // Declara que o pino de echo estará na porta 5
float distancia = 0;  // Cria a variável para receber o valor da distância
float tempo = 0;

void setup() {

  pinMode(trigger, OUTPUT);    // Configura o trigger como saída
  digitalWrite(trigger, LOW);  // Configura o trigger em nível baixo inicialmente
  pinMode(echo, INPUT);        // Configura o echo como entrada de sinal digital

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(4, 0);
  lcd.print("Medidor");
  lcd.setCursor(2, 1);
  lcd.print("Ultrassonico");
  delay(5000);
  lcd.clear();
}

void loop() {
  distancia = 0;
  digitalWrite(trigger, HIGH);  // Aciona o trigger por 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tempo = pulseIn(echo, HIGH);     // Lê o tempo em que echo permanece em nivel alto, tempo dado em microsegundos
  tempo = tempo / 1000000;         // Converte o tempo para segundos
  distancia = (tempo * 340) * 50;  // Calcula a distancia com base na equação fornecida no datasheet

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia Medida");
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  lcd.setCursor(7, 1);
  lcd.print("cm");
  delay(500);
}