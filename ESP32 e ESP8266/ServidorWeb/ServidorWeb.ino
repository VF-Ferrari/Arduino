#include <ESP8266WiFi.h>

const char* ssid = "ALHN-40A0";
const char* password = "h3A3Js.XPw";
unsigned char status_led = 0;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

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

  server.begin();
  Serial.println("Server iniciado.");
}

void loop() {
  WiFiClient client = server.available();

  // verifica se o cliente conectou
  if (!client) {
    return;
  }

  // aguarda informacao do cliente
  Serial.println("novo cliente");
  while (! client.available())
  {
    delay (1);
  }

  // le a primeira linha da mensagem
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush(); // limpa o buffer

  // verifica a mensagem

  if (req.indexOf("/ledoff") != -1)  {
    status_led = 0;
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED OFF");
  }
  else if (req.indexOf("/ledon") != -1)
  {
    status_led = 1;
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED ON");
  }

  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println("");

  client.println("<!DOCTYPE HTML>");
  client.println("<HTML>");
  client.println("<H1> LED </H1>");
  client.println("<br />");

  client.println("<a href=\"/ledon\"\"> <button style='FONT-SIZE: 50px;background-color: #00fa00; HEIGHT: 200px;WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED ON </button> </a>");
  client.println("<a href=\"/ledoff\"\"> <button style='FONT-SIZE: 50px;background-color: #fa0000; HEIGHT: 200px; WIDTH: 300px; 126px; Z-INDEX: 0; TOP: 200px;'> LED OFF </button> </a>");
  client.println("</html>");

  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");

}
