#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
#include <DHT.h>
#include <MPU6050.h>
#include <SD.h>

#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
MPU6050 mpu;
Adafruit_BMP280 bmp;
File dataFile;

void setup() {
  Serial.begin(9600);
  dht.begin();
  mpu.initialize();
  bmp.begin(0x76);

  if (!SD.begin(4)) {
    Serial.println("Falha ao inicializar o cartão SD");
    return;
  }

  dataFile = SD.open("dados.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Erro ao abrir o arquivo");
    return;
  }

  dataFile.println("Iniciando a leitura dos sensores...");
  dataFile.close();
}

void loop() {
  delay(200);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  int ax, ay, az;
  int gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0;
  float altitude = bmp.readAltitude();

  dataFile = SD.open("dados.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Temperatura: ");
    dataFile.print(t);
    dataFile.print("°C");
    dataFile.print(", Umidade: ");
    dataFile.print(h);
    dataFile.print("%");

    dataFile.print(", Acelerômetro: ");
    dataFile.print("X=");
    dataFile.print(ax);
    dataFile.print(" Y=");
    dataFile.print(ay);
    dataFile.print(" Z=");
    dataFile.print(az);

    dataFile.print(", Giroscópio: ");
    dataFile.print("X=");
    dataFile.print(gx);
    dataFile.print(" Y=");
    dataFile.print(gy);
    dataFile.print(" Z=");
    dataFile.print(gz);

    dataFile.print(", Temperatura BMP280: ");
    dataFile.print(temperature);
    dataFile.print("°C");

    dataFile.print(", Pressão: ");
    dataFile.print(pressure);
    dataFile.print(" hPa");

    dataFile.print(", Altitude: ");
    dataFile.print(altitude);
    dataFile.println(" metros");

    dataFile.close();

    Serial.println("Dados gravados com sucesso no cartão SD!");

    // Exibir dados no Serial Monitor
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("°C, Umidade: ");
    Serial.print(h);
    Serial.print("%, Acelerômetro: X=");
    Serial.print(ax);
    Serial.print(" Y=");
    Serial.print(ay);
    Serial.print(" Z=");
    Serial.print(az);
    Serial.print(", Giroscópio: X=");
    Serial.print(gx);
    Serial.print(" Y=");
    Serial.print(gy);
    Serial.print(" Z=");
    Serial.print(gz);
    Serial.print(", Temperatura BMP280: ");
    Serial.print(temperature);
    Serial.print("°C, Pressão: ");
    Serial.print(pressure);
    Serial.print(" hPa, Altitude: ");
    Serial.print(altitude);
    Serial.println(" metros");
  } else {
    Serial.println("Erro ao abrir o arquivo");
  }
}