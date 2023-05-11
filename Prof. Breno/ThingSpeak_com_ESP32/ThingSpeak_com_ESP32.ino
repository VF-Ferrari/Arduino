#include <WiFi.h>
#include <DHT.h>
#include <ThingSpeak.h>

WiFiClient cliente;
const unsigned long canal = 1976902;
const char *chaveAPI = "FI2L17HCYNXOL3EM";

#define led 2

#define DHTTYPE DHT11
#define DHTPin 5
DHT dht(DHTPin, DHTTYPE);

const char *ssid = "trUEM";
const char *password = "trUEM_2019";

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(led, LOW);  // liga o led
    delay(100);
    digitalWrite(led, HIGH);  // desliga o led
    delay(100);
  }
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(cliente);
}

void loop() {

  float temperatura = dht.readTemperature();
  Serial.print(" temperatura: ");
  Serial.print(temperatura);

  float umidade = dht.readHumidity();
  Serial.print(" humidade: ");
  Serial.println(umidade);

  ThingSpeak.writeField(canal, 1, temperatura, chaveAPI);
  ThingSpeak.writeField(canal, 2, umidade, chaveAPI);

  delay(15 * 1000);  //(min*seg*miles) Thingspeak aceita atualizacoes a cada 15 segundos
}