#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define pino_sinal_analogico A0
#define pino_led_vermelho 4
#define pino_led_amarelo 5
#define pino_led_verde 6

int valor_analogico;
int umidade;

void setup() {
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.print("Umidade de Solo");
  lcd.setCursor(0, 1);
  lcd.print("Vitor Ferrari");
  delay(4000);
  lcd.clear();
}

void loop() {
  valor_analogico = analogRead(pino_sinal_analogico);
  umidade = analogRead(A0);
  umidade = map(umidade, 1023, 0, 0, 100);

  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400) {
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print(" Solo Molhado");
    lcd.setCursor(0, 1);
    lcd.print("Umidade em: ");
    lcd.print(umidade);
    lcd.print(" %");
    digitalWrite(pino_led_verde, HIGH);
  } else {
    digitalWrite(pino_led_verde, LOW);
  }

  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800) {
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print(" Solo Umido        ");
    digitalWrite(pino_led_amarelo, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Umidade em: ");
    lcd.print(umidade);
    lcd.print(" %");
  } else {
    digitalWrite(pino_led_amarelo, LOW);
  }

  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024) {
    lcd.setBacklight(HIGH);
    lcd.setCursor(0, 0);
    lcd.print(" Solo Seco         ");
    digitalWrite(pino_led_vermelho, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Umidade em: ");
    lcd.print(umidade);
    lcd.print("  %");
  } else {
    digitalWrite(pino_led_vermelho, LOW);
  }
}