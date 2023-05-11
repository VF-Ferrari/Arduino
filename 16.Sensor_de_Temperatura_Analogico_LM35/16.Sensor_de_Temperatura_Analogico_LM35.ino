const int LM35 = A0;  // Define olpino analógico do sensor LM35
float temperatura;    // Variável que armazenará a temperatura medida
int value;            // Variável inteira para armazenar a conversão ADC
                      // Bibliotecas
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 8, 5, 4, 3, 2);  //(RS, E, D4,D5, D6, D7

void setup() {
  lcd.begin(16, 2);               // Inicia o LCD 16x02 (colunas,filas)
  lcd.home();                     // Coloca o cursor nas coordenadas (0,0)
  lcd.print("TemperaturaLocal");  // Escreve no Display LCD
  lcd.setCursor(0, 1);            // Coloca o cursor nas coordenadas (0,1)
  lcd.print("Temp: ");            // Escreve no Display LCD
}

void loop() {
  //value=analogRead(LM35);                              // Armazena o valor inteiro.
  //Conveierte el valor entero en Temperatura
  //temperatura=(value*5.0/1023.0) / 0.01;               // Leitura do Pino A0 (ADC)


  temperatura = (float(analogRead(LM35)) * 5.0 / 1023.0 - 0.5) / 0.01;  //TMP36

  lcd.setCursor(7, 1);     // Coloca o cursor nas coordenadas (7,1)
  lcd.print(temperatura);  // Escreve no Display LCD
  lcd.setCursor(14, 1);
  lcd.print("C    ");
  delay(1000);
}
