#define botao 13
#define led 10
bool estadoLed = 0;

void setup() {
  pinMode(botao, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  if (digitalRead(botao) == LOW) {
    estadoLed = !estadoLed;
    digitalWrite(led, estadoLed);
    //delay(200);         //Explicar o Bounce aqui... depois de explicar tirar o comentário
  }
}