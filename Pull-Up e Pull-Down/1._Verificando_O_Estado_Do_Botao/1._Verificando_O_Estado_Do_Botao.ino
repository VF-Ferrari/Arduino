#define botao 12

void setup() {
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Estado Logico do Botao = ");
  Serial.println(digitalRead(botao));
  delay(10);
}
