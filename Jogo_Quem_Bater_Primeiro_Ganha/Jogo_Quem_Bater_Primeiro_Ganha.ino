/*******************************************************************************
*
*  Quem bater primeiro
*
*******************************************************************************/

byte led[4] = {3, 4, 5, 6}; // define os pinos Arduino para os leds
byte button[4] = {8, 9, 10, 11}; //define os pinos Arduino para os botões competição
byte resetButton = 12; // define o botão do reset

 
void setup(void) { 
  for (byte i=0;i<4;i++) {
    pinMode(button[i], INPUT_PULLUP); // define os botões como pull up interno
  }
  for (byte i=0;i<4;i++) {
    pinMode(led[i], OUTPUT); // define os leds como saída
  }
  pinMode(resetButton, INPUT_PULLUP); // define o botão reset como pull up interno
}
 
void loop(){
   
  for (byte j=0;j<4;j++) {
    if (!digitalRead(button[j])) {
      delay(100);
      acenderLeds(j); // chama a função acenderLeds() e passa o valor de j
      resetar(); // chama a função resetar() 
    }
  }
}
 
void acenderLeds(byte seletor) {
    
  //seleciona qual led irá acender
  switch (seletor) {
     
   case 0:  // jogador 1
     digitalWrite(led[seletor],HIGH); // acende o led vermelho
   break;
 
   case 1: // jogador 2
     digitalWrite(led[seletor],HIGH); // acende o led amarelo
   break;
 
   case 2: // jogador 3
     digitalWrite(led[seletor],HIGH); // acende o led verde
   break;

   case 3: // jogador 4
     digitalWrite(led[seletor],HIGH); // acende o led laranja
   break;
  }
}

void resetar() {
  // loop vazio faz com que o programa interropa o processo até sair da condição, ou seja, pressionar o botão reset
  while (digitalRead(resetButton)) {
      } 

  // apaga todos leds após pressionar o botão reset
  for (byte k=0;k<4;k++) {
    digitalWrite(led[k], LOW);
  }       
}