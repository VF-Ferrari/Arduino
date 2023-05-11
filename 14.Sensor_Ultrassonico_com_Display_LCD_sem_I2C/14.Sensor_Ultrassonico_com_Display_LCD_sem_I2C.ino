#include <LiquidCrystal.h>  // Adiciona a biblioteca "LiquidCrystal" ao projeto
#define trigger 9           // Declara que o pino de trigger estará na porta 4
#define echo 8              // Declara que o pino de echo estará na porta 5
float distancia = 0;        // Cria a variável para receber o valor da distância
float tempo = 0;

LiquidCrystal lcd(12, 13, 7, 6, 5, 4);  // Pinagem do LCD

void setup() {
  pinMode(trigger, OUTPUT);    // Configura o trigger como saída
  digitalWrite(trigger, LOW);  // Configura o trigger em nível baixo inicialmente
  pinMode(echo, INPUT);        // Configura o echo como entrada de sinal digital
  lcd.begin(16, 2);            // Configura e inicia o display como sendo de 16 colunas e 2 linhas
  lcd.clear();                 // Limpa qualquer informação armazenada em cache
  lcd.setCursor(3, 0);         // Posiciona o cursor na quarta coluna e primeira linha
  lcd.print("Medidor");        // Escreve a primeira frase no display "Sensor"
  lcd.setCursor(1, 1);         // Posiciona o cursor na segunda coluna e segunda linha
  lcd.print("Ultrassonico");   // Escreve a segunda frase no display "Ultrassonico"
  delay(2000);
}

void loop() {
  distancia = 0;
  digitalWrite(trigger, HIGH);  // Aciona o trigger por 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  tempo = pulseIn(echo, HIGH);     // Lê o tempo em que echo permanece em nivel alto, tempo dado em microsegundos
  tempo = tempo / 1000000;         // Converte o tempo para segundos
  distancia = (tempo * 340) * 50;  // Calcula a distancia com base na equação fornecida no datasheet

  lcd.clear();                    // Limpa o display
  lcd.setCursor(0, 0);            // Posiciona o cursor
  lcd.print("Distancia Medida");  // Escreve no display "Distancia Medida"
  lcd.setCursor(0, 1);            // Posiciona o cursor
  lcd.print(distancia);           // Escreve a distancia calculada em centímetros
  lcd.setCursor(7, 1);            // Posiciona o cursor
  lcd.print("cm");                // Escreve a unidade de medida da distância
  delay(500);                     // Intervalo até a próxima medida
}