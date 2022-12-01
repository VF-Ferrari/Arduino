#define led1 11
#define led2 10
#define led3 9

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  analogWrite(led1, random(0, 255));
  analogWrite(led2, random(0, 255));
  analogWrite(led3, random(0, 255));
  delay(random(0, 100));
}
