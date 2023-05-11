#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal.h>
#define PIN 5
#define LED_COUNT 12

int Ledjes = 5;
int SensorA = A0;
int sensorValor = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {

  Serial.begin(9600);
  pinMode(SensorA, INPUT);
  lcd.begin(16, 2);
}

void loop() {

  sensorValor = (analogRead(SensorA) * 0.1);
  Serial.println(sensorValor, DEC);

  lcd.setCursor(0, 0);
  lcd.print("NIVEL DE GAS:");

  lcd.setCursor(13, 0);
  lcd.print(sensorValor);

  lcd.setCursor(15, 0);
  lcd.print("%");

  if (sensorValor > 70) {
    lcd.noDisplay();
    delay(100);
    lcd.display();
    delay(100);
    lcd.setCursor(3, 1);
    lcd.print("PERIGO...");
    tone(7, 1500);

  } else {
    lcd.setCursor(3, 1);
    lcd.print("NORMAL...");
    noTone(7);
  }
}