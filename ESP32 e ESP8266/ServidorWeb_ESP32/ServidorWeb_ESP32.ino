#include <WiFi.h>
const char *ssid = "trUEM";
const char *password = "trUEM_2019";
WiFiServer server(80);
// armazena a requisição do HTTP;
String header;
int led = 2;
String ledstate = "off";// estado atual do led
int count = 0;

void setup() {
  Serial.begin(115200);  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(led, LOW); // liga o led
    delay(100);
    digitalWrite(led, HIGH); // desliga o led
    delay(100);
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // verifica se ha novos clientes

  if (client) {                             // novo cliente conectado,
    String currentLine = "";                // string de entrada de informacao do client
    while (client.connected()) {            // loop enquanto cliente conectado
      if (client.available()) {             // se o cliente enviou alguma informação
        char c = client.read();             // le a informacao
        Serial.write(c);                   
        header += c;
        if (c == '\n') {                    
          // se a informacao for uma linha vazia  
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //controle do led
            if (header.indexOf("GET /led/on") >= 0) {
              Serial.println("led on");
              ledstate = "on";
              digitalWrite(led, HIGH);
            } else if (header.indexOf("GET /led/off") >= 0) {
              Serial.println("led off");
              ledstate = "off";
              digitalWrite(led, LOW);
            }

            // HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS alterar o estilo da pagina            
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");

            // Web Page Head
            client.println("<body><h1>ESP32 Web Server</h1>");

            // botao
            client.println("<p>estado atual do led - " + ledstate + "</p>");
            if (ledstate == "off") {
              client.println("<p><a href=\"/led/on\"><button class=\"button\">ON</button></a></p>");              
            } else {
              client.println("<p><a href=\"/led/off\"><button class=\"button button2\">OFF</button></a></p>");
              count++;
            }
            client.println("contador: " + String(count) + "</p>");
            
            client.println("</body></html>");            
            client.println();
            // encerra o loop
            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;     
        }
      }
    }
    // limpa o header
    header = "";
    // encerra a conexao
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
