/* Código para mostrar valor em dB */

const int PinoSensor = A0;  //pino Anlógico de Entrada 0
//const int PinoDigital = 0;
//int Estado = 0;
int ValorSensor = 0;
int valorMaior = 0;
float tensao = 0;
int dB = 0;
int cont = 0;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  Serial.begin(9600);
  //pinMode(0, INPUT);
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.clear();          //Limpa o LCD
  lcd.setCursor(0, 0);  //Posiciona o cursor na coluna 0, linha 0
  lcd.print("Int. Sonora: ");
  lcd.setCursor(8, 1);
  lcd.print("dB");
}
void loop() {
  lcd.setCursor(3, 1);
  while (cont < 10000) {
    ValorSensor = analogRead(PinoSensor);
    if (ValorSensor > valorMaior) {
      valorMaior = ValorSensor;
    }
    cont++;
  }
  cont = 0;
  tensao = valorMaior / 1023.0 * 4.53;
  dB = 103.1 * tensao - 115, 4;
  dB = 87.1 * tensao - 75, 4;
  if (dB < 0) {
    dB = 0;
  }
  lcd.print("");
  lcd.setCursor(3, 1);
  lcd.print(dB);
  Serial.print("Tensao: ");
  Serial.print(tensao);
  Serial.println(" V");
  Serial.print("Intensidade: ");
  Serial.print(dB);
  Serial.println(" dB");
  valorMaior = 0;
  delay(100);
}