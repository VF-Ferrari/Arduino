#define Do 528.00
#define Re 592.42
#define Mi 665.28
#define Fa 704.88
#define Fas 746.59
#define Sol 790.94
#define La 888.10
#define Si 996.86
#define DO 1056.00
#define RE 1184.80
#define MI 1330.60
#define buzzer 12
#define T1 500
#define T2 250
#define T3 1000
#define T4 2000


void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  
  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, Re); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);

  tone(buzzer, Fas); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);

  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, Re); delay(T1); noTone(buzzer);
  tone(buzzer, La); delay(T1); noTone(buzzer);

  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  tone(buzzer, Si); delay(T2); noTone(buzzer);
  tone(buzzer, Si); delay(T2); noTone(buzzer);
  
  tone(buzzer, RE); delay(T1); noTone(buzzer);
  tone(buzzer, Si); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);

  tone(buzzer, Fas); delay(T1); noTone(buzzer);
  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, DO); delay(T2); noTone(buzzer);
  tone(buzzer, DO); delay(T2); noTone(buzzer);

  tone(buzzer, Si); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);
  tone(buzzer, La); delay(T1); noTone(buzzer);
  
  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  
  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, Re); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);
  
  tone(buzzer, Fas); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T2); noTone(buzzer);

  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, Re); delay(T1); noTone(buzzer);
  tone(buzzer, La); delay(T1); noTone(buzzer);
  
  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  tone(buzzer, Si); delay(T2); noTone(buzzer);
  tone(buzzer, Si); delay(T2); noTone(buzzer);

  tone(buzzer, RE); delay(T1); noTone(buzzer);
  tone(buzzer, Si); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);

  tone(buzzer, Fas); delay(T1); noTone(buzzer);
  tone(buzzer, Mi); delay(T1); noTone(buzzer);
  tone(buzzer, DO); delay(T2); noTone(buzzer);
  tone(buzzer, DO); delay(T2); noTone(buzzer);

  tone(buzzer, Si); delay(T1); noTone(buzzer);
  tone(buzzer, Sol); delay(T1); noTone(buzzer);
  tone(buzzer, La); delay(T1); noTone(buzzer);

  tone(buzzer, Sol); delay(T3+T1); noTone(buzzer);
  
}