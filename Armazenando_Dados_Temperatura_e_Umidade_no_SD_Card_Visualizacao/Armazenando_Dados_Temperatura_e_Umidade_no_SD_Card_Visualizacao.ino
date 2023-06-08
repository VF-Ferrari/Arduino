#include <DHT.h>
#include <SPI.h>
#include <SD.h>

#define DHTPIN 7   // Pino de dados do sensor DHT11 conectado ao pino digital 2
#define DHTTYPE DHT11   // Tipo do sensor DHT11

DHT dht(DHTPIN, DHTTYPE);

const int chipSelect = 4;   // Pino do chip select do módulo SD Card

File dataFile;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Falha ao inicializar o cartão SD!");
    return;
  }
  
  Serial.println("Cartão SD inicializado com sucesso.");
  
  dataFile = SD.open("data.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Erro ao abrir o arquivo para escrita.");
    return;
  }
  
  dataFile.println("Temperatura (C), Umidade (%)");
  dataFile.close();
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha ao ler dados do sensor DHT11!");
    return;
  }
  
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print("°C, Umidade: ");
  Serial.print(humidity);
  Serial.println("%");
  
  dataFile = SD.open("data.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print(temperature);
    dataFile.print(",");
    dataFile.println(humidity);
    dataFile.close();
    Serial.println("Dados salvos com sucesso.");
  } else {
    Serial.println("Erro ao abrir o arquivo para escrita.");
  }
  
  delay(2000);  // Aguarda 2 segundos antes de fazer a próxima leitura
}