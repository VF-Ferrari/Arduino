#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define Buzzer 10
#define MQ6_Analog 0
#define MQ6_Digital 2
#define SensorLevel 500

int digital_read = 0;
int analog_read = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(MQ6_Digital, INPUT);
  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.setBacklight(HIGH);
}

void loop() {
  digital_read = digitalRead(MQ6_Digital);
  analog_read = analogRead(MQ6_Analog);

  //apresenta as leituras na porta serial
  Serial.println("Saida Digital:");
  Serial.println(digital_read);
  Serial.println(" Saida Analogica:");
  Serial.println(analog_read);
  
  if (analog_read > SensorLevel) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ar contaminado!");
    // Aciona o Buzzer
    digitalWrite(Buzzer, HIGH);
  } else {
    // Apresenta os dados no LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ar normal");
    // Desliga o buzzer e o led vermelho
    digitalWrite(Buzzer, LOW);
  }
  delay(2000);
}