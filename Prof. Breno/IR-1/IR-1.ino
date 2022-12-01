#define led 13

int sensorPin = A0; 
int sensorValue = 0;
 
void setup () {
  pinMode(led, OUTPUT);
  //pinMode(sensorPin, INPUT);
}
 
void loop () {
  if(analogRead(sensorPin) <= 100){
    digitalWrite (led, HIGH); //led off
  }
  digitalWrite (led, LOW); //led on - default
}
