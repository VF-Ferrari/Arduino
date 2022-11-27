int botao = 7;
int led =12;
bool estadoLed = 0;

void setup() {
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);

 pinMode(botao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
 pinMode(led, OUTPUT);

}

void loop() {
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);

  digitalWrite(9, HIGH);
  delay(100);
  digitalWrite(9, LOW);
  delay(100);

  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);

  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);

  if(digitalRead(botao) == LOW) // Se o botão for pressionado
  {
    estadoLed = !estadoLed; // troca o estado do LED
    digitalWrite(led, estadoLed);
    while(digitalRead(botao) == LOW);
    delay(100);       
  } 

}
