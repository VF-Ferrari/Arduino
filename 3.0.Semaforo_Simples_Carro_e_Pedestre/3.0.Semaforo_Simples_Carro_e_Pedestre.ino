int pedVerde = 9;  // Define os pinos que serao utilizados
int pedVermelho = 8;
int carroVerde = 12;
int carroAmarelo = 11;
int carroVermelho = 10;

void setup()  // Define os pinos como saidas
{
  pinMode(pedVerde, OUTPUT);
  pinMode(pedVermelho, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);

  digitalWrite(carroVerde, HIGH);  // Coloca na posição inicial. Somente o verde dos carros e o vermelho dos pedestres acessos
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pedVerde, LOW);
  digitalWrite(pedVermelho, HIGH);
}

void loop() {
  digitalWrite(carroVerde, HIGH);  // acende o verde dos carros e o vermelho dos pedestres
  digitalWrite(pedVermelho, HIGH);
  delay(5000);  // aguarda 5 segundos
  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);  // apaga o verde dos carros e acende o amarelo
  delay(3000);                       // aguarda mais 3 segundos
  digitalWrite(carroAmarelo, LOW);   // apaga o amarelo dos carros e acende o vermelho
  digitalWrite(carroVermelho, HIGH);
  digitalWrite(pedVermelho, LOW);  // apaga o vermelho dos pedestres e acende o verde
  digitalWrite(pedVerde, HIGH);
  delay(5000);  // aguardar mais 5 segundos
  digitalWrite(pedVerde, LOW);
  for (int x = 0; x < 5; x++)  // pisca o vermelho dos pedestres
  {
    digitalWrite(pedVermelho, HIGH);
    delay(250);
    digitalWrite(pedVermelho, LOW);
    delay(250);
  }
  digitalWrite(carroVermelho, LOW);
}