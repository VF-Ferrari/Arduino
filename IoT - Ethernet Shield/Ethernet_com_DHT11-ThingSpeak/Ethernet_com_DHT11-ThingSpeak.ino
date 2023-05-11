#include <DHT.h>
#include <SPI.h>
#include <Ethernet.h>
#include <ThingSpeak.h>

#ifdef SPARK
#include "ThingSpeak/ThingSpeak.h"
#else
#include "ThingSpeak.h"
#endif

#define WRITE_DELAY_FOR_THINGSPEAK 15000
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xED };      // Esse dado não se altera
IPAddress ip(192, 168, 0, 104);      // obeter esse dado via comando ipconfig dentro do cmd do windows
EthernetClient client;

unsigned long mySensorChannelNumber = 1944138;
const char* myWriteAPIKey_sensors = "F29PCWCAX96VF947";

long lastWriteTime = 0;
long lastReadTime = 0;
float responceValue = 0;

void setup() {
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  ThingSpeak.begin(client);
  dht.begin();
  pinMode(13, OUTPUT);
  Serial.println("Setup Completo");
  delay(1000);
}

void loop() {
  if (millis() - lastWriteTime > 20000) {
    Serial.println("Lendo Sensores:");
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(t) || isnan(h)) {
      Serial.println("Erro na Leitura do Sensor DHT11");
    } else {
      Serial.println("Temperatura" + String(t) + " °C");
      Serial.println("Umidade" + String(h) + " %");
      ThingSpeak.setField(1, t);
      ThingSpeak.setField(2, h);
      ThingSpeak.setField(3, responceValue);
      ThingSpeak.writeFields(mySensorChannelNumber, myWriteAPIKey_sensors);
      lastWriteTime = millis();
    }
  }

  // if(millis()-lastReadTime>15000){
  //   float value = ThingSpeak.readFloatField(myCommandsChannelNumber, 1);
  //   Serial.println("Lendo ThingSpeak no Canal de Comando/Campo 1, Ultimo valor lido foi:"+String(value));
  //   if(value==0) digitalWrite(13, LOW);
  //   else digitalWrite(13, HIGH);
  //   responceValue=value;
  //   lastReadTime=millis();
  // }
}
