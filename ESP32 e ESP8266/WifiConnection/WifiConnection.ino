#include <ESP8266WiFi.h>

const char* ssid = "ALHN-40A0";
const char* password = "h3A3Js.XPw";


void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.print("Conectando à rede: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, LOW); // liga o led
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH); // desliga o led
    delay(100);
  }
  Serial.println(" ");
  Serial.println("WiFi conectado.");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
