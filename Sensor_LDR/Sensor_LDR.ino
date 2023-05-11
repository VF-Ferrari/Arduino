#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int analog_IN = A1;  // Declaração do Pino de Entrada

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(analog_IN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int Value = analogRead(analog_IN);
  Value = map(Value, 8, 500, 0, 100);  // Converte a leitura do LDR para porcentagem
  Serial.print("Int. Luminosa:");
  Serial.println(Value);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Int. Luminosa:");
  lcd.setCursor(3, 1);
  lcd.print(Value);
  delay(500);
}