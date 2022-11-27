/*
 *  COMPONENT BOTÃO DE MULTI FUNÇÕES 
*/

#define PORT_BUTTON                       9
boolean flagPressed                       = false;
boolean flagLongPressed                   = false;
boolean flagActionFunction                = false;

#define MODE_DEFAULT                      0
#define MODE_CLICK                        1
#define MODE_FUNCTION                     2

byte currentMode                          = MODE_DEFAULT;
byte quantityFunction                     = 10;    // Quantidade de funções 
byte functionSelected                     = 1;     // Qual a função foi selecionada

unsigned long updateTime                  = 0;
unsigned long limitTime                   = 2000;  // Tempo limite para Modo Pressed

unsigned long updatetimeModeFunction      = 0;
unsigned long limitTimeModeFunction       = 3000;  // Tempo limite para executar ação após selecionar a função



/*
 * Preparando a porta de entrada do botão
*/
void prepareButtonMultiFuction(){
    pinMode(PORT_BUTTON,INPUT_PULLUP);
}


/*
 * Retorna o valor do tempo limite para o modo Pressed
*/
unsigned long getLimitTime(){
  return limitTime;
}


/*
 * Incrementa para a próxima função selecionada
*/
void setFunctionSelected(){
  functionSelected++;
  if(functionSelected > quantityFunction){
    functionSelected = 1;
  }
}


/*
 *  Retorna qual função foi selecionada
*/
byte getFunctionSelected(){
  return functionSelected;
}


/*
 * Monitora o clique no botão, longPressed e navegação
*/
void monitoringButtonMultiFunction(){
    if(digitalRead(PORT_BUTTON) == LOW && flagPressed == false){
      delay(50);
      if(digitalRead(PORT_BUTTON) == LOW){
        updateTime = millis();
        flagPressed = true;
        
        if(flagLongPressed){
            updatetimeModeFunction = millis() + limitTimeModeFunction;
            flagActionFunction = true;
            setFunctionSelected();
        }
        
      }
    }else{
       if(flagLongPressed == false && flagPressed == true && longPressed(updateTime)){
          currentMode = MODE_FUNCTION;
          flagLongPressed = true;
          flagActionFunction = true;
          updatetimeModeFunction = millis() + limitTimeModeFunction;
          
       }else if(digitalRead(PORT_BUTTON) == HIGH && flagPressed == true){
          if(flagLongPressed == false){
            currentMode = MODE_CLICK;
          }
          flagPressed = false;
          updateTime = 0;
       }

        if(flagLongPressed && timing(updatetimeModeFunction)){
            actionFunctionSelect();
            flagLongPressed = false;
            updatetimeModeFunction = 0;
            functionSelected = 1;
            currentMode = MODE_DEFAULT;
        }
    }
}


/*
 * Define as ações a serem executadas com o clique
*/
void actionMode(){
    switch(currentMode){
      case MODE_CLICK:
           Serial.println("Clicou Modo Normal");
           currentMode = MODE_DEFAULT;
      break;
      case MODE_FUNCTION:
           if(flagActionFunction){
              Serial.print("Funcao Selecionada :[");
              Serial.print(getFunctionSelected());
              Serial.println("]");
              flagActionFunction = false;
           }
      break;
    }
}


/*
 * Define as ações a serem executadas no modo function
 * após o tempo limite excedido
*/
void actionFunctionSelect(){
     Serial.print("Executando funcao : ");
     switch(getFunctionSelected()){
      case 1:
              Serial.print("MODE 1");
      break;
      case 2:
              Serial.print("MODE 2");
      break;
      case 3:
              Serial.print("MODE 3");
      break;
      case 4:
              Serial.print("MODE 4");
      break;
      case 5:
              Serial.print("MODE 5");
      break;
      case 6:
              Serial.print("MODE 6");
      break;
      case 7:
              Serial.print("MODE 7");
      break;
      case 8:
              Serial.print("MODE 8");
      break;
      case 9:
              Serial.print("MODE 9");
      break;
      case 10:
              Serial.print("MODE 10");
      break;
      default:
            Serial.print("<< Nao Definida >>");
    }
    Serial.println();
}
