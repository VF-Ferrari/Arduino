#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
dht DHT;

#define DHT11_PIN 7  // Pino 7 recebe o sinal do DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  Serial.begin(9600);
}
void loop() {
  int chk = DHT.read11(DHT11_PIN);
  float Temperatura = (DHT.temperature);  // Lendo a Temperatura
  float Umidade = (DHT.humidity);         // Lendo a Umidade

  // Mostrando o Valor da Temperatura e da Umidade no Display LCD
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  lcd.print(Temperatura);
  lcd.setCursor(0, 1);
  lcd.println("Umid         %  ");
  lcd.setCursor(6, 1);
  lcd.print(Umidade);
  delay(1000);

  //Serial.println(Temperatura);
  Serial.println(Umidade);
  delay(500);
}