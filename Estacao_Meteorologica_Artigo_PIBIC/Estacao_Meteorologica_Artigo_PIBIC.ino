#include <ThingSpeak.h>
#include <stdlib.h>
#include <SoftwareSerial.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
#define SSID "xxxxx"  //Nome da Rede Wifi
#define PASS "xxxxx"  //Senha da Rede Wifi
#define IP "184.106.153.149"  // thingspeak.com
#define DHT22_PIN 2

unsigned long myChannelNumber = 1944138;
const char* myWriteAPIKey = "F29PCWCAX96VF947";

String GET = "GET /update?key=F29PCWCAX96VF947&field1=";
SoftwareSerial monitor(10, 11);  // Definição de canal serial para módulo ESP8266 (RX, TX)

dht DHT;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

//Definição de variáveis
int luminancePin = A0;
int uvPin = A1;
int dustPin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;
unsigned long delay_time = 30000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

//setup
void setup() {
  //iniciar canais seriais
  Serial.begin(9600);
  monitor.begin(9600);
  Serial.println("Inicializando...");

  //configurar pinos
  pinMode(dustPin, INPUT);

  //initicializar o sensor de pressão
  Serial.println("Detectando sensor de pressao BMP085...");
  if (!bmp.begin()) {
    /* Se ocorrer um problema na detecção do BMP085, verificar suas conexões */
    Serial.println("O BMP085 não foi detectado. Verifique suas ligações ou o I2C ADDR!");
    while (1)
      ;
  }
  Serial.println("BMP085 detectado!");

  //comunicação com o módulo wifi
  monitor.flush();
  monitor.println("AT");
  delay(2000);

  if (monitor.find("OK")) {
    Serial.println("Comunicacao com modulo ESP8266: OK");
  } else {
    Serial.println("Erro no modulo ESP8266");
  }

  //conectar com roteador
  connectWiFi();

  Serial.print("Amostrando (");
  Serial.print(sampletime_ms / 1000);
  Serial.println("s)...");

  //inicializar timer
  starttime = millis();
}

void loop() {
  //medição do material particulado
  duration = pulseIn(dustPin, LOW);
  lowpulseoccupancy = lowpulseoccupancy + duration;

  //ciclo de amostragem de 30 segundos
  if ((millis() - starttime) >= sampletime_ms)  //se oe sample time == 30s
  {
    ratio = lowpulseoccupancy / (sampletime_ms * 10.0);                              // porcentagem (de 0 a 100%)
    concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62;  // dados do datasheet
    lowpulseoccupancy = 0;

    //leitura dos sensores
    char buffer[10];
    //luminosidade
    float luminance = analogRead(luminancePin);
    //UV
    float uv = analogRead(uvPin);
    uv = uv * 0.0049;  //converter para V
    uv = uv * 307;     //converter para mW/m²
    uv = uv / 200;     //índice UV
    //temperatura e umidade
    int chk = DHT.read22(DHT22_PIN);
    float humidity = DHT.humidity;
    float temperature = DHT.temperature;
    //pressão e temperatura
    sensors_event_t event;
    bmp.getEvent(&event);
    float pressure = 0;
    float temperature1 = 0;
    if (event.pressure) {
      pressure = event.pressure;
      bmp.getTemperature(&temperature1);
    }

    //conversão dos dados lidos para strings
    String luminanceStr = dtostrf(luminance, 4, 1, buffer);
    luminanceStr.replace(" ", "");
    String uvStr = dtostrf(uv, 4, 1, buffer);
    uvStr.replace(" ", "");
    String humidityStr = dtostrf(humidity, 4, 1, buffer);
    humidityStr.replace(" ", "");
    String temperatureStr = dtostrf(temperature, 4, 1, buffer);
    temperatureStr.replace(" ", "");
    String dustStr = dtostrf(concentration, 4, 1, buffer);
    dustStr.replace(" ", "");
    String pressureStr = dtostrf(pressure, 4, 1, buffer);
    pressureStr.replace(" ", "");
    String temperature1Str = dtostrf(temperature1, 4, 1, buffer);
    temperature1Str.replace(" ", "");

    //enviar dados dos sensores para o thingspeak
    updateSensors(luminanceStr, humidityStr, temperatureStr, uvStr, dustStr, pressureStr, temperature1Str);

    //esperar até próximo ciclo de amostragem
    Serial.print("Esperar ");
    Serial.print(delay_time / 1000);
    Serial.println("s para proxima amostragem");
    Serial.println();
    delay(delay_time);

    //iniciar novo ciclo de amostragem
    Serial.println();
    Serial.print("Amostrando (");
    Serial.print(sampletime_ms / 1000);
    Serial.println("s)...");
    starttime = millis();
  }
}

//Função para envio dos dados dos sensores para o thingspeak
void updateSensors(String luminanceStr, String humidityStr, String temperatureStr, String uvStr, String dustStr, String pressureStr, String temperature1Str) {

  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  monitor.println(cmd);
  delay(2000);

  cmd = GET;
  cmd += luminanceStr;
  cmd += "&field2=";
  cmd += humidityStr;
  cmd += "&field3=";
  cmd += temperatureStr;
  cmd += "&field4=";
  cmd += uvStr;
  cmd += "&field5=";
  cmd += dustStr;
  cmd += "&field6=";
  cmd += pressureStr;
  cmd += "&field7=";
  cmd += temperature1Str;
  cmd += "\r\n";
  delay(1000);
  int strsize = cmd.length();
  monitor.println("AT+CIPSEND=" + String(strsize));
  delay(2000);

  monitor.print(cmd);
  if (monitor.find("OK")) {
    Serial.println("Dados transmitidos com sucesso");
  } else {
    Serial.println("Falha na transmissao");
  }
}

void sendDebug(String cmd) {
  Serial.print("SEND: ");
  Serial.println(cmd);
  monitor.println(cmd);
}

boolean connectWiFi() {
  Serial.println("Conectando wi-fi...");
  String cmd = "AT+CWMODE=1";
  monitor.println(cmd);
  delay(2000);
  monitor.flush();  //clear buffer
  cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  monitor.println(cmd);
  delay(5000);

  if (monitor.find("OK")) {
    Serial.println("Conectado com sucesso!");
    return true;
  } else {
    Serial.println("Falha na conexao!");
    return false;
  }
  Serial.println();
}
