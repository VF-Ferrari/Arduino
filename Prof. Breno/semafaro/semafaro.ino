#define red 11
#define yel 12
#define gre 13

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  digitalWrite(yel, LOW);
  digitalWrite(gre, LOW);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(yel, LOW);
  digitalWrite(gre, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  digitalWrite(yel, HIGH);
  digitalWrite(gre, LOW);
  delay(200);
}
