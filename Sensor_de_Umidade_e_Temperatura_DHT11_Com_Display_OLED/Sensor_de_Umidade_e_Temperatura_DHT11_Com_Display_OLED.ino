#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  //Largura da Tela
#define SCREEN_HEIGHT 64  //Altura da Tela

// On an arduino UNO: A4(SDA), A5(SCL)
#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C  //Endereço da Tela
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

DHT dht(13, DHT11);  //O sensor de DHT11 está conectado na porta 13

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  dht.begin();
}

void loop() {
  double H = dht.readHumidity();
  double T = dht.readTemperature();

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("T: ");
  display.print(T, 1);  // ,1 para mostrar apenas uma casa decimal do valor lido
  display.println(" C");
  display.println();
  display.print("U: ");
  display.print(H, 1);  // ,1 para mostrar apenas uma casa decimal do valor lido
  display.println(" %");
  display.display();
  delay(2000);
}
