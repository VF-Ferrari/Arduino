int verde_carro = 7;
int amarelo_carro = 6;
int vermelho_carro = 5;
int verde_pedestre = 4;
int vermelho_pedestre = 3;
int Solicita = 2;
bool Estado_Solicita;
int intervalo_1 = 5000; 
int intervalo_2 = 10000;

void setup()
{
  pinMode (verde_carro, OUTPUT); 
  pinMode (amarelo_carro, OUTPUT); 
  pinMode (vermelho_carro, OUTPUT);
  pinMode (verde_pedestre, OUTPUT);
  pinMode (vermelho_pedestre, OUTPUT);
  pinMode (Solicita, INPUT);
}

void loop()
{
  Estado_Solicita = digitalRead(Solicita);
  if (Estado_Solicita == LOW)
  {
    digitalWrite (vermelho_pedestre, HIGH);
    digitalWrite (verde_carro, HIGH);
  }
  else
  { 
    digitalWrite (verde_carro, LOW);
    digitalWrite (amarelo_carro, HIGH);
    delay (intervalo_1); 
    digitalWrite (amarelo_carro, LOW);
    digitalWrite (vermelho_carro, HIGH);
    digitalWrite (vermelho_pedestre, LOW);
    digitalWrite (verde_pedestre, HIGH);
    delay (intervalo_2); 
    digitalWrite (verde_pedestre, LOW);
    digitalWrite (vermelho_pedestre, HIGH);
    digitalWrite (vermelho_carro, LOW);
    digitalWrite (verde_carro, HIGH);
    delay (intervalo_2); 
  }
}
