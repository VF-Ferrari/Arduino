//Programa : Arduino Ethernet Shield W5100 e HC-SR04
//Baseado no programa exemplo de

#include <Wire.h>
#include <SPI.h>
#include <Ethernet.h>

#define trigger 9     // Declara que o pino de trigger estará na porta 4
#define echo 8        // Declara que o pino de echo estará na porta 5
float distancia = 0;  // Cria a variável para receber o valor da distância
float tempo = 0;

//Definicoes de IP, mascara de rede e gateway
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 134);      //Define o endereco IP
IPAddress gateway(192, 168, 1, 1);   //Define o gateway
IPAddress subnet(255, 255, 255, 0);  //Define a máscara de rede

//Inicializa o servidor web na porta 80
EthernetServer server(80);

void setup() {
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();

  pinMode(trigger, OUTPUT);    // Configura o trigger como saída
  digitalWrite(trigger, LOW);  // Configura o trigger em nível baixo inicialmente
  pinMode(echo, INPUT);        // Configura o echo como entrada de sinal digital
}

void loop() {

  distancia = 0;
  digitalWrite(trigger, HIGH);  // Aciona o trigger por 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tempo = pulseIn(echo, HIGH);     // Lê o tempo em que echo permanece em nivel alto, tempo dado em microsegundos
  tempo = tempo / 1000000;         // Converte o tempo para segundos
  distancia = (tempo * 340) * 50;  // Calcula a distancia com base na equação fornecida no datashee

  //Aguarda conexao do browser
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == 'n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 1");  //Recarrega a pagina a cada 1seg
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          //Configura o texto e imprime o titulo no browser
          client.print("<font color=#FF0000><b><u>");
          client.print("Envio de informacoes pela rede utilizando Arduino");
          client.print("</u></b></font>");
          client.println("<br />");
          client.println("<br />");
          //Mostra o estado da porta digital 3
          int porta_digital = digitalRead(3);
          client.print("Porta Digital 3 : ");
          client.print("<b>");
          client.print(porta_digital);
          client.println("</b>");
          client.print("  (0 = Desligada, 1 = Ligada)");
          client.println("<br />");
          //Mostra as informacoes lidas pelo sensor ultrasonico
          client.print("Sensor Ultrasonico : ");
          client.print("<b>");
          client.print(distancia);
          client.print(" cm");
          client.println("</b></html>");
          break;
        }
        if (c == 'n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != 'r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
}