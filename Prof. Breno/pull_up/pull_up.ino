#define button 8
#define led 7
bool estado_led = 0;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  if(digitalRead(button) == LOW){
    estado_led = !estado_led;
    digitalWrite(led, estado_led);
    while(digitalRead(button) == LOW);
  }
}
