#define mlb 8  // motor esquerda para trás 
#define mlf 9  // motor esquerda para frente
#define mrb 10 // motor direita para trás
#define mrf 11 // motor direita para frente
char in_byte;
void setup() {
  Serial.begin(9600);
  pinMode(mlb, OUTPUT);
  pinMode(mlf, OUTPUT);
  pinMode(mrb, OUTPUT);
  pinMode(mrf, OUTPUT);
}

void loop() {
  in_byte = Serial.read();
  if (in_byte == 'f'){
    digitalWrite(mlb, LOW);
    digitalWrite(mlf, HIGH);
    digitalWrite(mrb, LOW);
    digitalWrite(mrf, HIGH);
  }
  if (in_byte == 'l'){
    digitalWrite(mlb, LOW);
    digitalWrite(mlf, HIGH);
    digitalWrite(mrb, LOW);
    digitalWrite(mrf, LOW);
  }
  if (in_byte == 'r'){
    digitalWrite(mlb, LOW);
    digitalWrite(mlf, LOW);
    digitalWrite(mrb, LOW);
    digitalWrite(mrf, HIGH);
  }
  if (in_byte == 'b'){
    digitalWrite(mlb, HIGH);
    digitalWrite(mlf, LOW);
    digitalWrite(mrb, HIGH);
    digitalWrite(mrf, LOW);
  }
  if (in_byte == '0'){
    digitalWrite(mlb, LOW);
    digitalWrite(mlf, LOW);
    digitalWrite(mrb, LOW);
    digitalWrite(mrf, LOW);
  }  
 }
