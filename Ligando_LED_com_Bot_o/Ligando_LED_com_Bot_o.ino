int botao = 7;
int led =12;
bool estadoLed = 0;

void setup()
{
  pinMode(botao, INPUT_PULLUP); // define o pino do botao como entrada "INPUT"
  pinMode(led, OUTPUT);
}

void loop()
{
  if(digitalRead(botao) == LOW) // Se o botão for pressionado
  {
    estadoLed = !estadoLed; // troca o estado do LED
    digitalWrite(led, estadoLed);
    while(digitalRead(botao) == LOW);
    delay(100);       
  } 
}
