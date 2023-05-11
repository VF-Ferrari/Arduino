#include <Wire.h>
#include <DHT.h>
#include <SPI.h>
#include <Ethernet.h>
#include <ThingSpeak.h>
#include <Adafruit_BMP280.h>
Adafruit_BMP280 bmp;  //I2C

#ifdef SPARK
#include "ThingSpeak/ThingSpeak.h"
#else
#include "ThingSpeak.h"
#endif

int analog_IN = A1;  // Conexão LDR
#define LED_VERDE 13
#define WRITE_DELAY_FOR_THINGSPEAK 15000
#define DHTPIN 5  // Conexão DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xED };
IPAddress ip(192, 168, 0, 104);
EthernetClient client;

unsigned long mySensorChannelNumber = 2111250;           // Canel ID obtido pelo ThingSpeak
const char* myWriteAPIKey_sensors = "N0A2TK0120VAZTTA";  // Chave obtida pelo ThingSpeak

long lastWriteTime = 0;
long lastReadTime = 0;
float responceValue = 0;


void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  ThingSpeak.begin(client);
  dht.begin();
  pinMode(13, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(analog_IN, INPUT);
  Serial.println("Setup Completo");
  delay(1000);

  if (!bmp.begin(0x76)) { /*Definindo o endereço I2C como 0x76. Mudar, se necessário, para (0x77)*/

    //Imprime mensagem de erro no caso de endereço invalido ou não localizado. Modifique o valor
    Serial.println(F(" Não foi possível encontrar um sensor BMP280 válido, verifique a fiação ou "
                     "tente outro endereço!"));
    while (1) delay(10);
  }
}

void loop() {

  if (millis() - lastWriteTime > 20000) {

    digitalWrite(LED_VERDE, HIGH);
    delay(500);
    digitalWrite(LED_VERDE, LOW);
    delay(500);

    Serial.println("Lendo Sensores:");
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int Value = analogRead(analog_IN);
    Value = map(Value, 8, 500, 0, 100);  // Converte a leitura do LDR para porcentagem

    if (isnan(t) || isnan(h)) {
      Serial.println("Erro na Leitura do Sensor DHT11");
    } else {
      Serial.println("Temperatura" + String(t) + " °C");
      Serial.println("Umidade" + String(h) + " %");
      Serial.print("Int. Luminosa:");
      Serial.println(Value);

      Serial.print(F("Pressão = "));
      Serial.print(bmp.readPressure());
      Serial.println(" Pa");

      Serial.print(F("Altitude Aprox = "));
      Serial.print(bmp.readAltitude(1013.25)); /* Ajustar a pressão de nível do mar de acordo com o local!*/
      Serial.println(" m");

      ThingSpeak.setField(1, t);
      ThingSpeak.setField(2, h);
      ThingSpeak.setField(3, Value);
      ThingSpeak.setField(4, bmp.readPressure());
      ThingSpeak.setField(5, bmp.readAltitude(1013.25));

      ThingSpeak.writeFields(mySensorChannelNumber, myWriteAPIKey_sensors);
      lastWriteTime = millis();
    }
  }
}