#define mr1 10
#define mr2 9
#define ml1 6
#define ml2 5

void setup(){
  pinMode(mr1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(ml2, OUTPUT);
  delay(5000);
}

void loop(){
  digitalWrite(mr1, HIGH);
  digitalWrite(ml1, HIGH);
  delay(500); //frente
  digitalWrite(ml1, LOW);
  delay(700); //vira
  digitalWrite(ml1, HIGH);
  delay(500); //frente
  digitalWrite(ml1, LOW);
  delay(700); //vira
  digitalWrite(ml1, HIGH);
  delay(500); //frente
  digitalWrite(ml1, LOW);
  delay(700); //vira
  digitalWrite(ml1, HIGH);
}
