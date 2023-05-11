#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}

void loop() {
  Serial.println("Iniciando o scaneamento: \n");
  int redes = WiFi.scanNetworks();

  Serial.print("Redes encontradas: ");
  Serial.println(redes);

  for (int i = 0; i < redes; i++) {
    Serial.print(i + 1);
    Serial.print(": ");
    Serial.println(WiFi.SSID(i));

  }
  Serial.println();
  delay(1000);
}
