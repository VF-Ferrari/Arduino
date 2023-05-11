#define in1 6 // Entrada do motor 1
#define in2 5 // Entrada do motor 1
#define in3 11 // Entrada do motor 2
#define in4 10 // Entrada do motor 2


int dataIn[5] {0,0,0,0}; // Vetor dos dados completos que receberemos do aplicativo
int in_byte = 0; // A informação em bytes que estamos recebendo a cada momento do aplicativo
int array_index = 0; // Indice do vetor 
int X, Y, button, velMotor; // As coordenadas em X, Y, o botão (que não estamos usando ainda) e a variavel de velocidade
unsigned long time1; // Variavel auxiliar para guardar tempo

void setup() {
Serial.begin(9600);  
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(2, OUTPUT); // Definindo o pino do led
}

void loop() {
  if (Serial.available() > 0) { // Verificando se há dados para receber do bluetooth.
    time1 = millis(); // A variavel time1 salva o tempo em que o bluetooth enviou dados da ultima vez
    digitalWrite(2, HIGH); // ativa o led de indicação que a conexão está ativa
    in_byte = Serial.read();  // Recebendo um byte do app
    if (in_byte == (255))  // Verifica se é o byte de encerramento do dado
      array_index = 0;
    dataIn[array_index] = in_byte;   //Salvando o dado no vetor de indices
    array_index = array_index +1; 
  }
  else{
    if((millis() - time1)>500) // Compara se passaram mais que 0,5s desde a ultima vez que o bluetooth estava disponivel
      digitalWrite(2, LOW); // Se passou, significa que a conexão foi perdida, e o LED desliga
  }
    

    
  X = dataIn[2]-124; // Calculando o valor do eixo X do Joystick
  Y = 124-dataIn[3]; //Calculando o valor do eixo X do Joystick
  button = dataIn[1]; // Recebe o estado do botão, mas não usaremos
  
  velMotor = Y*2; // Calculo da velocidade do motor para fazer o acionamento PWM
  
  //----------- Para frente ---------------//

  if((Y>1)){ // Carrinho para frente
    analogWrite(in1, velMotor); 
    digitalWrite(in2, LOW);
    analogWrite(in3, velMotor);
    digitalWrite(in4, LOW);
  }
  //--------------------------------------//
  
  //----------- Para tras ---------------//

  else if (Y<(-1)){ // Carrinho para trás
    analogWrite(in2, -1*velMotor);
    digitalWrite(in1, LOW);
    analogWrite(in4, -1*velMotor);
    digitalWrite(in3, LOW);
  }
 //-------------------------------------------//

// ------------ Carrinho parado -------------//

  else {
    digitalWrite(in1, LOW); 
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  //---------------------------------------//
  
  //------------- Para os lados --------------//
  if(X < -34 ){ // Limite para começar a virar para a esquerda
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }
  else if (X > 34){ // Limite para começar a virar para a direita.
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
}
