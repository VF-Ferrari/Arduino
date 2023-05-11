void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(200);              // Espera 500 Milissegundos
  digitalWrite(8, LOW);
  delay(200);              // Espera 500 Milissegundos

  digitalWrite(9, HIGH);
  delay(200);              // Espera 500 Milissegundos
  digitalWrite(9, LOW);
  delay(200);              // Espera 500 Milissegundos

  digitalWrite(10, HIGH);
  delay(200);              // Espera 500 Milissegundos
  digitalWrite(10, LOW);
  delay(200);              // Espera 500 Milissegundos

  digitalWrite(11, HIGH);
  delay(200);              // Espera 500 Milissegundos
  digitalWrite(11, LOW);
  delay(200);              // Espera 500 Milissegundos
}