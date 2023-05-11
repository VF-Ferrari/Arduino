#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define buttom1 0
#define buttom2 1
#define buttom3 2
#define buttom4 3

int b1 = 0, b2 = 0, b3 = 0, b4 = 0;  // Testa o nível lógico de cada botão

void setup() {

  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();
  Serial.begin(9600);

  lcd.print("Aperte um Botao");

  pinMode(buttom1, INPUT);
  pinMode(buttom2, INPUT);
  pinMode(buttom3, INPUT);
  pinMode(buttom4, INPUT);
}

void loop() {

  b1 = digitalRead(buttom1);
  b2 = digitalRead(buttom2);
  b3 = digitalRead(buttom3);
  b4 = digitalRead(buttom4);

  if (b1 == LOW) {
    lcd.setCursor(2, 1);  // 2 = Duas colunas para a direita. 1 = Segunda linha
    lcd.print("Botao 1");
  }

  if (b2 == LOW) {
    lcd.setCursor(2, 1);  // 2 = Duas colunas para a direita. 1 = Segunda linha
    lcd.print("Botao 2");
  }

  if (b3 == LOW) {
    lcd.setCursor(2, 1);  // 2 = Duas colunas para a direita. 1 = Segunda linha
    lcd.print("Botao 3");
  }

  if (b4 == LOW) {
    lcd.setCursor(2, 1);  // 2 = Duas colunas para a direita. 1 = Segunda linha
    lcd.print("Botao 4");
  }
}