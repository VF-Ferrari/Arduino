#include <ThingSpeak.h>
#include <stdlib.h>
#include <SoftwareSerial.h>
#include <dht.h>
#include <Wire.h>
#define SSID "Vitor"
#define PASS "VitorFerrari2020"
#define IP "184.106.153.149" // thingspeak.com
#define DHT11_PIN 7

unsigned long myChannelNumber = 1944138;
const char * myWriteAPIKey = "F29PCWCAX96VF947";

String GET = "GET /update?key=F29PCWCAX96VF947&field1=";
SoftwareSerial monitor(10, 11); // Definição de canal serial para módulo ESP8266 (RX, TX)
 
dht DHT;
 
//Definição de variáveis
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;
unsigned long delay_time = 30000;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;
 

void setup()
{
  //iniciar canais seriais
  Serial.begin(9600);
  monitor.begin(9600);
  Serial.println("Inicializando...");
 
    //comunicação com o módulo wifi
    monitor.flush();
    monitor.println("AT");
    delay(2000);
    
    if(monitor.find("OK")){
      Serial.println("Comunicacao com modulo ESP8266: OK");
    }
    else {
     Serial.println("Erro no modulo ESP8266");
    }
 
  //conectar com roteador  
  connectWiFi(); 
     
  Serial.print("Amostrando (");
  Serial.print(sampletime_ms/1000);
  Serial.println("s)...");
  
  //inicializar timer
  starttime = millis();
}
 
void loop(){

  //leitura dos sensores
    char buffer[10];

  //ciclo de amostragem de 30 segundos
  if ((millis() - starttime) >= sampletime_ms) //se oe sample time == 30s
  {
     
    //temperatura e umidade
    int chk = DHT.read11(DHT11_PIN);
    float humidity = DHT.humidity;
    float temperature = DHT.temperature;

    
    //conversão dos dados lidos para strings
   
    String humidityStr = dtostrf(humidity, 4, 1, buffer);
    humidityStr.replace(" ","");
    String temperatureStr = dtostrf(temperature, 4, 1, buffer);
    temperatureStr.replace(" ","");
   
    
    //enviar dados dos sensores para o thingspeak
    updateSensors(humidityStr, temperatureStr);
  
    //esperar até próximo ciclo de amostragem
    Serial.print("Esperar ");
    Serial.print(delay_time/1000);
    Serial.println("s para proxima amostragem");
    Serial.println();
    delay(delay_time);
    
    //iniciar novo ciclo de amostragem
    Serial.println();
    Serial.print("Amostrando (");
    Serial.print(sampletime_ms/1000);
    Serial.println("s)...");
    starttime = millis();
  }
}

//Função para envio dos dados dos sensores para o thingspeak
void updateSensors( String humidityStr, String temperatureStr) {
 
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  monitor.println(cmd);
  delay(2000);
 
//  cmd = GET;
//  cmd += luminanceStr;
//  cmd += "&field2=";
  cmd += humidityStr;
  cmd += "&field2=";
  cmd += temperatureStr;
  cmd += "&field3=";
//  cmd += uvStr;
//  cmd += "&field5=";
//  cmd += dustStr;
// cmd += "&field6=";
//  cmd += pressureStr;
//  cmd += "&field7=";
//  cmd += temperature1Str;
  cmd += "\r\n";
  delay(1000);
  int strsize = cmd.length();
  monitor.println("AT+CIPSEND=" + String(strsize));
  delay(2000);
  
  monitor.print(cmd);
  if(monitor.find("OK")){
    Serial.println("Dados transmitidos com sucesso");
  }else{
    Serial.println("Falha na transmissao");
  }
}
 
void sendDebug(String cmd){
  Serial.print("SEND: ");
  Serial.println(cmd);
  monitor.println(cmd);
} 
 
boolean connectWiFi(){
  Serial.println("Conectando wi-fi...");
  String cmd ="AT+CWMODE=1";
  monitor.println(cmd);
  delay(2000);
  monitor.flush(); //clear buffer
  cmd="AT+CWJAP=\"";
  cmd+=SSID;
  cmd+="\",\"";
  cmd+=PASS;
  cmd+="\"";
  monitor.println(cmd);
  delay(5000);
  
  if(monitor.find("OK")){
    Serial.println("Conectado com sucesso!");
    return true;
  }else{
    Serial.println("Falha na conexao!");
    return false;
  }
  Serial.println();
}