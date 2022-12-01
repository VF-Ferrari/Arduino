#define pote A0

int led[6] = {13, 12, 11, 10, 9, 8};

void setup() {
  int i;
  for(i= 0; i< 6; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(pote, INPUT);
}

void acende(int x) {
  int i;
  for(i= 0; i< x; i++){
    digitalWrite(led[i], HIGH);
  }
  for(i= x; i< 6; i++){
    digitalWrite(led[i], LOW);
  }

}

void loop() {
  acende(map(analogRead(pote), 0, 1023, 0, 6));
}
