#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor = 10;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  pinMode(sensor, INPUT);
}

void loop() {
  int estado;
  estado = digitalRead(sensor);
  if (estado == 0) {
    lcd.print("Objeto Detectado");
    delay(100);
    lcd.clear();
  } else {
    lcd.print("Objeto Longe");
    delay(100);
    lcd.clear();
  }
}