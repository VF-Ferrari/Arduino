#include <IRremote.h>

#define rec 11
#define mr1 10
#define mr2 9
#define ml1 6
#define ml2 5

IRrecv recIR(rec);
decode_results resultado;

void setup(){
  pinMode(mr1, OUTPUT);
  pinMode(mr2, OUTPUT);
  pinMode(ml1, OUTPUT);
  pinMode(ml2, OUTPUT);
  recIR.enableIRIn();
}

void loop(){
  if(recIR.decode(&resultado)){
    switch(resultado.value){
      case 0XE0E006F9:
        digitalWrite(mr1, 1);
        digitalWrite(mr2, 0);
        digitalWrite(ml1, 1);
        digitalWrite(ml2, 0);
      break;
      case 0xE0E08679:
        digitalWrite(mr1, 0);
        digitalWrite(mr2, 1);
        digitalWrite(ml1, 0);
        digitalWrite(ml2, 1);
      break;
      case 0XE0E046B9:
        digitalWrite(mr1, 1);
        digitalWrite(mr2, 0);
        digitalWrite(ml1, 0);
        digitalWrite(ml2, 0);
      break;
      case 0xE0E0A659:
        digitalWrite(mr1, 0);
        digitalWrite(mr2, 0);
        digitalWrite(ml1, 1);
        digitalWrite(ml2, 0);
      break;
      case 0xE0E016E9:
        digitalWrite(mr1, 0);
        digitalWrite(mr2, 0);
        digitalWrite(ml1, 0);
        digitalWrite(ml2, 0);
      break;
    }
    recIR.resume();
  }
}
