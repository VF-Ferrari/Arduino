#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.print("Colegio Absoluto");
  lcd.setCursor(0, 1);
  lcd.print("  Ensino Medio");
  delay(5000);
  lcd.clear();
}

void loop() {
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Tradicao e");
  lcd.setCursor(0, 1);
  lcd.print("     Inovacao");
  delay(5000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("63% de aprovacao");
  lcd.setCursor(0, 1);
  lcd.print("                               ");
  delay(5000);
  lcd.clear();
}