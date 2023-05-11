#define pino_sinal_analogico A0
#define pino_led_vermelho 4
#define pino_led_amarelo 5
#define pino_led_verde 6

int valor_analogico;

void setup() {
  Serial.begin(9600);
  pinMode(pino_sinal_analogico, INPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_led_amarelo, OUTPUT);
  pinMode(pino_led_verde, OUTPUT);
}

void loop() {
  //Le o valor do pino A0 do sensor
  valor_analogico = analogRead(pino_sinal_analogico);

  //Mostra o valor da porta analogica no serial monitor
  Serial.print("Porta analogica: ");
  Serial.print(valor_analogico);

  //Solo umido, acende o led verde
  if (valor_analogico > 0 && valor_analogico < 400) {
    Serial.println(" Status: Solo Molhado");
    digitalWrite(pino_led_verde, HIGH);
  } else {
    digitalWrite(pino_led_verde, LOW);
  }

  //Solo com umidade moderada, acende led amarelo
  if (valor_analogico > 400 && valor_analogico < 800) {
    Serial.println(" Status: Solo Umido");
    digitalWrite(pino_led_amarelo, HIGH);
  } else {
    digitalWrite(pino_led_amarelo, LOW);
  }

  //Solo seco, acende led vermelho
  if (valor_analogico > 800 && valor_analogico < 1024) {
    Serial.println(" Status: Solo Seco");
    digitalWrite(pino_led_vermelho, HIGH);
  } else {
    digitalWrite(pino_led_vermelho, LOW);
  }
}