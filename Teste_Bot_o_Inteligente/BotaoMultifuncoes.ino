#define PORT_BUTTON 9
boolean flagPressed = false;
boolean flagLongPressed = false;
boolean flagActionFunction = false;

#define MODE_DEFAULT    0
#define MODE_CLICK      1
#define MODE_FUNCTION   2

byte currentMode = MODE_DEFAULT;
byte quantityFunction = 3;             //Quantidade de funções que terá o para serem selecionadas
byte functionSelected = 1;             //Qual função foi selecionada

unsigned long updateTime = 0;          
unsigned long limitTime = 2000;                //Tempo limite para executar a função "Pressed"

unsigned long updatetimeModeFunction = 0;
unsigned long limitTimeModeFunction = 3000;    //Tempo limite para executar a ação após selecionar a função

void prepareButtonMultFuction(){
  pinMode(PORT_BUTTON, INPUT_PULLUP);
  }

unsigned long getLimitTime(){
  return limitTime;  
  }

void setFunctionSelected(){
  functionSelected++;
  if(functionSelected > quantityFunction){
    functionSelected = 1;
    }
  }

byte getFunctionSelected(){
  return functionSelected;
  }

void monitoringButtonMultiFuction(){
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
                    
          } else if(digitalRead(PORT_BUTTON) == HIGH && flagPressed == true){
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
  
void actionMode(){
  switch (currentMode){
    case MODE_CLICK:
      Serial.println("Clicou Modo Normal");
      currentMode = MODE_DEFAULT;
    break;
    case MODE_FUNCTION:
      if(flagActionFunction){
        Serial.print("Funcao Selecioada : [");
        Serial.print(getFunctionSelected());
        Serial.println("]");
        flagActionFunction = false;
        }
    break;
    }
  }

void actionFunctionSelect(){
  Serial.println("Executando Funcao:");
  switch(getFunctionSelected()){
    case 1: 
      Serial.println("Temperatura e Umidade");
    break;
    case 2: 
      Serial.println("Luminosidade");
    break;
    case 3: 
      Serial.println("Vibração");
    break;
    default:
      Serial.println("Escolha uma Funcao");
    }
  }
