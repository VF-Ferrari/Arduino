// Define os pinos dos sensores infravermelho
const int sensorEsquerdoPin = A0;
const int sensorDireitoPin = A1;

// Define os pinos dos motores
const int motorEsquerdoPwmPin = 5;
const int motorEsquerdoDirPin = 6;
const int motorDireitoPwmPin = 9;
const int motorDireitoDirPin = 10;

// Define as variáveis para controle dos motores
int velocidadeBase = 150; // velocidade base dos motores (0-255)
int correcaoVelocidade = 30; // correção de velocidade para um dos motores

void setup() {
  // Define os pinos dos motores como saídas
  pinMode(motorEsquerdoPwmPin, OUTPUT);
  pinMode(motorEsquerdoDirPin, OUTPUT);
  pinMode(motorDireitoPwmPin, OUTPUT);
  pinMode(motorDireitoDirPin, OUTPUT);
  
  // Define os pinos dos sensores infravermelho como entradas
  pinMode(sensorEsquerdoPin, INPUT);
  pinMode(sensorDireitoPin, INPUT);
}

void loop() {
  // Lê os valores dos sensores infravermelho
  int sensorEsquerdoValor = analogRead(sensorEsquerdoPin);
  int sensorDireitoValor = analogRead(sensorDireitoPin);

  // Calcula a diferença entre os valores dos sensores
  int diferenca = sensorEsquerdoValor - sensorDireitoValor;

  // Define a velocidade dos motores baseado na diferença
  int velocidadeEsquerda = velocidadeBase;
  int velocidadeDireita = velocidadeBase;

  // Se o robô estiver desviando para a direita, corrige a velocidade do motor esquerdo
  if (diferenca > 0) {
    velocidadeEsquerda = velocidadeEsquerda - correcaoVelocidade;
  }
  // Se o robô estiver desviando para a esquerda, corrige a velocidade do motor direito
  else if (diferenca < 0) {
    velocidadeDireita = velocidadeDireita - correcaoVelocidade;
  }

  // Define a direção dos motores (avançar)
  digitalWrite(motorEsquerdoDirPin, HIGH);
  digitalWrite(motorDireitoDirPin, HIGH);

  // Define a velocidade dos motores usando PWM
  analogWrite(motorEsquerdoPwmPin, velocidadeEsquerda);
  analogWrite(motorDireitoPwmPin, velocidadeDireita);
}