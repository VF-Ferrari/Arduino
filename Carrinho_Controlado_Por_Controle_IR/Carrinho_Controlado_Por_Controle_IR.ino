//Baixar biblioteca IRremote no gerenciador de bibliotecas

#include <IRremote.h>
#define Kleber 12  //Recpetor IR

#define frenteD 8  //Marrom
#define frenteE 9  //Amarelo
#define trasD 10   //Vermelho
#define trasE 11   //Laranja

//Mapa das Conexões da Ponte H
//Laranja - Esquerda Trás
//Vermelho - Direita Trás
//Marrom - Direita Frente
//Amarelo - Esquerda Frente

//Mapa dos Comandos do Controle Remoto
//Frente - FF18E7
//Tras - FF4AB5
//Drieita - FF5AA5
//Esquerda - FF10EF
//Parado - FF38C7

IRrecv recIR(Kleber);
decode_results resultado;

void setup() {
  pinMode(frenteD, OUTPUT);
  pinMode(frenteE, OUTPUT);
  pinMode(trasD, OUTPUT);
  pinMode(trasE, OUTPUT);
  recIR.enableIRIn();
}

void loop() {
  if (recIR.decode(&resultado)) {
    switch (resultado.value) {
      case 0XFF18E7:  //Frente
        digitalWrite(frenteD, HIGH);
        digitalWrite(frenteE, HIGH);
        digitalWrite(trasD, LOW);
        digitalWrite(trasE, LOW);
        break;

      case 0XFF4AB5:  //Tras
        digitalWrite(frenteD, LOW);
        digitalWrite(frenteE, LOW);
        digitalWrite(trasD, HIGH);
        digitalWrite(trasE, HIGH);
        break;

      case 0XFF5AA5:  //Direita
        digitalWrite(frenteD, HIGH);
        digitalWrite(frenteE, LOW);
        digitalWrite(trasD, LOW);
        digitalWrite(trasE, HIGH);
        break;

      case 0XFF10EF:  //Esquerda
        digitalWrite(frenteD, LOW);
        digitalWrite(frenteE, HIGH);
        digitalWrite(trasD, HIGH);
        digitalWrite(trasE, LOW);
        break;

      case 0XFF38C7:  //Parado
        digitalWrite(frenteD, LOW);
        digitalWrite(frenteE, LOW);
        digitalWrite(trasD, LOW);
        digitalWrite(trasE, LOW);
        break;
    }
    recIR.resume();
  }
}