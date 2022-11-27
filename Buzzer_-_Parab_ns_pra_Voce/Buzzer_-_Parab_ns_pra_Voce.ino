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
#define T1 2000 
#define T2 T1/2
#define T3 T1/4
#define T4 T1/8


void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  
  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);

  tone(buzzer, Fas); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);

  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T3); noTone(buzzer);
  tone(buzzer, La); delay(T3); noTone(buzzer);

  tone(buzzer, Sol); delay(T2); noTone(buzzer);
  tone(buzzer, Si); delay(T3); noTone(buzzer);
  tone(buzzer, Si); delay(T3); noTone(buzzer);
  
  tone(buzzer, RE); delay(T3); noTone(buzzer);
  tone(buzzer, Si); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);

  tone(buzzer, Fas); delay(T3); noTone(buzzer);
  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, DO); delay(T4); noTone(buzzer);
  tone(buzzer, DO); delay(T4); noTone(buzzer);

  tone(buzzer, Si); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  tone(buzzer, La); delay(T3); noTone(buzzer);
  
  tone(buzzer, Sol); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  
  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  
  tone(buzzer, Fas); delay(T2); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);
  tone(buzzer, Re); delay(T4); noTone(buzzer);

  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, Re); delay(T3); noTone(buzzer);
  tone(buzzer, La); delay(T3); noTone(buzzer);
  
  tone(buzzer, Sol); delay(T2); noTone(buzzer);
  tone(buzzer, Si); delay(T4); noTone(buzzer);
  tone(buzzer, Si); delay(T4); noTone(buzzer);

  tone(buzzer, RE); delay(T3); noTone(buzzer);
  tone(buzzer, Si); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);

  tone(buzzer, Fas); delay(T3); noTone(buzzer);
  tone(buzzer, Mi); delay(T3); noTone(buzzer);
  tone(buzzer, DO); delay(T4); noTone(buzzer);
  tone(buzzer, DO); delay(T4); noTone(buzzer);

  tone(buzzer, Si); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T3); noTone(buzzer);
  tone(buzzer, La); delay(T3); noTone(buzzer);
  tone(buzzer, Sol); delay(T2+T3); noTone(buzzer);
  
}
