#define mr1 10
#define mr2 9
#define ml1 6
#define ml2 5

void setup(){
  pinMode(mr1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(ml2, OUTPUT);
}

void loop(){
  delay(5000);
  analogWrite(mr1, 100);
  analogWrite(ml1, 255);
  digitalWrite(mr2, LOW);
  digitalWrite(ml2, LOW);

}
