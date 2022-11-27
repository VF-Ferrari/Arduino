#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define buttom1 5
#define buttom2 6

int b1 = 0, b2 = 0;                           // Testa o nível lógico de cada botão

void setup() {

  
    lcd.init();
    lcd.setBacklight(HIGH);           
    lcd.clear();
    Serial.begin(9600);

    lcd.print("Aperte um Botao");

    pinMode(buttom1,INPUT);
    pinMode(buttom2,INPUT);
}

void loop() {
  
   b1 = digitalRead(buttom1);
   b2 = digitalRead(buttom2);

  if (b1==LOW){

    lcd.setCursor(2,1);
    lcd.print("Opcao 1");
     
  }

  if (b2==LOW){

    lcd.setCursor(2,1);
    lcd.print("Opcao 2");
    
  }
  

}
