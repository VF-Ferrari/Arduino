#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  //Definição do MAC Address da Ethernet Shield
IPAddress ip(192, 168, 0, 134);                       // Definição do endereço IP que a Ethernet Shield terá na rede onde estiver conectada. Verifique a Máscara-de-subrede e todos os equipamentos conectados na rede para achar um IP compatível e livre.
EthernetServer server(80);                            // Porta em que a Ethernet Shield irá receber as requisições das páginas (o padrão WEB é a porta 80)

String HTTP_req;
String URLValue;

void processaPorta(byte porta, byte posicao, EthernetClient cl);
String getURLRequest(String *requisicao);
bool mainPageRequest(String *requisicao);

const byte qtdePinosDigitais = 11;
byte pinosDigitais[qtdePinosDigitais] = { 2, 3, 5, 6, 7, 8, 9, A2, A3, A4, A5 };
byte modoPinos[qtdePinosDigitais] = { INPUT_PULLUP, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT, OUTPUT };

const byte qtdePinosAnalogicos = 2;
byte pinosAnalogicos[qtdePinosAnalogicos] = { A0, A1 };

void setup() {
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);

  for (int nL = 0; nL < qtdePinosDigitais; nL++) {
    pinMode(pinosDigitais[nL], modoPinos[nL]);
  }
}

void loop() {
  EthernetClient client = server.available();

  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        HTTP_req += c;

        if (c == '\n' && currentLineIsBlank) {

          if (mainPageRequest(&HTTP_req)) {
            URLValue = getURLRequest(&HTTP_req);

            client.println("HTTP/1.1 200 OK");
            client.println("Content-Type: text/html");
            client.println("Connection: close");
            client.println();

            //Conteudo da Página HTML
            client.println("<!DOCTYPE html>");
            client.println("<html>");
            client.println("<head>");
            client.println("<title>Arduino via WEB</title>");
            client.println("</head>");
            client.println("<body>");
            client.println("<h1>PORTAS EM FUN&Ccedil;&Atilde;O ANAL&Oacute;GICA</h1>");

            for (int nL = 0; nL < qtdePinosAnalogicos; nL++) {
              client.print("Porta A");
              client.print(pinosAnalogicos[nL] - 14);
              client.print(" - Valor: ");
              client.println(analogRead(pinosAnalogicos[nL]));
              client.println("<br/>");
            }

            client.println("<br/>");
            client.println("<h1>PORTAS EM FUN&Ccedil;&Atilde;O DIGITAL</h1>");
            client.println("<form method=\"get\">");

            for (int nL = 0; nL < qtdePinosDigitais; nL++) {
              processaPorta(pinosDigitais[nL], nL, client);
              client.println("<br/>");
            }

            client.println("<br/>");
            client.println("<button type=\"submit\">Envia para o Arduino</button>");
            client.println("</form>");

            //Específico para Exemplificar
            client.println("<br/>");
            client.println("<br/>");

            client.print("Porta A0: ");
            client.print(map(analogRead(A0), 0, 1023, 0, 179));
            client.println(" graus");
            client.println("<br/>");

            client.print("Porta A1: ");
            float voltagem = analogRead(A1) * 5.0 / 1024.0;
            client.print((voltagem - 0.5) * 10);
            client.println(" graus cent&iacute;grados");
            client.println("<br/>");

            client.println("<br/>");


            client.println("</body>");
            client.println("</html>");

          } else {
            client.println("HTTP/1.1 200 OK");
          }
          HTTP_req = "";
          break;
        }

        if (c == '\n') {
          currentLineIsBlank = true;
        } else if (c != '\r') {
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
  }
}


void processaPorta(byte porta, byte posicao, EthernetClient cl) {
  static boolean LED_status = 0;
  String cHTML;

  cHTML = "P";
  cHTML += porta;
  cHTML += "=";
  cHTML += porta;

  if (modoPinos[posicao] == OUTPUT) {

    if (URLValue.indexOf(cHTML) > -1) {
      LED_status = HIGH;
    } else {
      LED_status = LOW;
    }
    digitalWrite(porta, LED_status);
  } else {

    LED_status = digitalRead(porta);
  }

  cHTML = "<input type=\"checkbox\" name=\"P";
  cHTML += porta;
  cHTML += "\" value=\"";
  cHTML += porta;

  cHTML += "\"";
  //cHTML += "\" onclick=\"submit();\"";

  if (LED_status) {
    cHTML += " checked ";
  }

  if (modoPinos[posicao] != OUTPUT) {
    cHTML += " disabled ";
  }

  cHTML += ">Porta ";

  if (porta <= 13) {
    cHTML += porta;
  } else {
    cHTML += "A";
    cHTML += porta - 14;
  }
  cl.println(cHTML);
}


String getURLRequest(String *requisicao) {
  int inicio, fim;
  String retorno;

  inicio = requisicao->indexOf("GET") + 3;
  fim = requisicao->indexOf("HTTP/") - 1;
  retorno = requisicao->substring(inicio, fim);
  retorno.trim();

  return retorno;
}

bool mainPageRequest(String *requisicao) {
  String valor;
  bool retorno = false;

  valor = getURLRequest(requisicao);
  valor.toLowerCase();

  if (valor == "/") {
    retorno = true;
  }

  if (valor.substring(0, 2) == "/?") {
    retorno = true;
  }

  if (valor.substring(0, 10) == "/index.htm") {
    retorno = true;
  }

  return retorno;
}