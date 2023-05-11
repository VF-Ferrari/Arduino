#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {

 Serial.begin(9600);
 Serial.println("Inicializando...");
 
 lcd.init();
 lcd.setBacklight(HIGH);
 lcd.print("Inicializando...");
 lcd.setCursor(0, 1);
 lcd.print(" Vitor Ferrari");
 delay(3000);
 lcd.clear();

 prepareButtonMultFuction();

}

void loop() {

 monitoringButtonMultiFuction();
 actionMode();

}
