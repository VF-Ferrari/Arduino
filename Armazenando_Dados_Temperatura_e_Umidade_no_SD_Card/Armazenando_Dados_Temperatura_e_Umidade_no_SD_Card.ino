/* 
 ** Vcc -  5V
 ** GND - GND
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
*/

#include <DHT.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN 7   // Pino de dados do sensor DHT11 conectado ao pino digital 2
#define DHTTYPE DHT11   // Tipo do sensor DHT11

DHT dht(DHTPIN, DHTTYPE);

const int chipSelect = 4;   // Pino do chip select do módulo SD Card

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha ao inicializar o cartão SD!");
    return;
  }
  
  Serial.println("Cartão SD inicializado com sucesso.");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler dados do sensor DHT11!");
    return;
  }
  
  String dataString = String(temperature) + "," + String(humidity);
  
  File dataFile = SD.open("data.txt", FILE_WRITE);
  
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    Serial.println("Dados salvos com sucesso.");
  } else {
    Serial.println("Erro ao abrir o arquivo para escrita.");
  }
  
  delay(2000);  // Aguarda 2 segundos antes de fazer a próxima leitura
}