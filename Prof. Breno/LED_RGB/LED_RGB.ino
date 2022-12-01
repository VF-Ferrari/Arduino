#define B 11
#define G 10
#define R 9

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 255);
  delay(500);
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 255);
  delay(500);
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(500);
  analogWrite(R, 255);
  analogWrite(G, 255);
  analogWrite(B, 0);
  delay(500);
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 255);
  delay(500);
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 0);
  delay(500);
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
  delay(500);
}
