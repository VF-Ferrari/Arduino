#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int sensorLuz = 0;  // Pino analógico que o sensor de luz está conectado.
int valorSensorLuz = 0;   // Usada para ler o valor do sensor de luz.

void setup() {
  Serial.begin(9600);  //Inicia a comunicaçao serial (para exibir os valores lidos)
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.print("Intensidade Luz");  // Imprime um texto
  lcd.setCursor(1, 1);
  lcd.print("Vitor Ferrari");
  delay(5000);  // 5 segundos de delay
}
void loop() {
  valorSensorLuz = analogRead(sensorLuz);
  valorSensorLuz = map(valorSensorLuz, 7, 690, 100, 0);
  lcd.clear();          // Limpa o display
  lcd.setCursor(0, 0);  //posiciona o cursor na coluna 0 linha 1 do LCD.
  lcd.print("Luz: ");   //Imprime a string no display do LCD.
  lcd.print(valorSensorLuz);
  delay(1000);

  Serial.println(valorSensorLuz);
  delay(250);
}