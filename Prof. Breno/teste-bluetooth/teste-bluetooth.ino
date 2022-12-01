#define mlb 6  // motor esquerda para trás 
#define mlf 5  // motor esquerda para frente
#define mrb 9  // motor direita para trás
#define mrf 10 // motor direita para frente

void setup() {
  Serial.begin(9600);
  pinMode(mlb, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mrf, OUTPUT);
}

void loop() {
  char in_byte = Serial.read();
  while(Serial.available() == 0);
  Serial.println(in_byte);
 }
