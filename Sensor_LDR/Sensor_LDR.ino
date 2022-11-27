#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int analog_IN = A1;  // This is our input pin

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(analog_IN, INPUT);
  Serial.begin(9600);  
}

void loop() {

  int Value = analogRead(analog_IN);  
  Serial.print("Int. Luminosa:");Serial.println(Value);  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Int. Luminosa:");
  lcd.setCursor(3,1);
  lcd.print(Value);  
  delay(500);
}
