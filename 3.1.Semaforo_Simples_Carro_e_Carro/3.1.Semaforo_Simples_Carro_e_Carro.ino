int vermelho_1 = 2;
int amarelo_1 = 3;
int verde_1 = 4;

int vermelho_2 = 5;
int amarelo_2 = 6;
int verde_2 = 7;

int intervalo_1 = 2000; 
int intervalo_2 = 5000;

void setup()
{
  pinMode (vermelho_1, OUTPUT);
  pinMode (amarelo_1, OUTPUT);
  pinMode (verde_1, OUTPUT); 
 
  pinMode (vermelho_2, OUTPUT);
  pinMode (amarelo_2, OUTPUT);
  pinMode (verde_2, OUTPUT);
}

void loop()
{
    /*digitalWrite (vermelho_1, HIGH);
    digitalWrite (amarelo_1, HIGH);
    digitalWrite (verde_1, HIGH);
    digitalWrite (vermelho_2, HIGH);
    digitalWrite (amarelo_2, HIGH);
    digitalWrite (verde_2, HIGH);
    delay (intervalo_1);*/
    
    digitalWrite (vermelho_1, HIGH);
    digitalWrite (amarelo_1, LOW);
    digitalWrite (verde_1, LOW);
    digitalWrite (vermelho_2, LOW);
    digitalWrite (amarelo_2, LOW);
    digitalWrite (verde_2, HIGH);
    delay (intervalo_2); 

    digitalWrite (vermelho_1, HIGH);
    digitalWrite (amarelo_1, LOW);
    digitalWrite (verde_1, LOW);
    digitalWrite (vermelho_2, LOW);
    digitalWrite (amarelo_2, HIGH);
    digitalWrite (verde_2, LOW);
    delay (intervalo_1); 
    
    digitalWrite (vermelho_1, LOW);
    digitalWrite (amarelo_1, LOW);
    digitalWrite (verde_1, HIGH);
    digitalWrite (vermelho_2, HIGH);
    digitalWrite (amarelo_2, LOW);
    digitalWrite (verde_2, LOW);
    delay (intervalo_2); 

    digitalWrite (vermelho_1, LOW);
    digitalWrite (amarelo_1, HIGH);
    digitalWrite (verde_1, LOW);
    digitalWrite (vermelho_2, HIGH);
    digitalWrite (amarelo_2, LOW);
    digitalWrite (verde_2, LOW);
    delay (intervalo_1);
}