#define botao 13                       //Porta em que o botão está sendo lido
#define ledVerde 10                    //Porta em que o LED verde está conectado
#define ledAmarelo 9                   //Porta em que o LED amarelo está conectado
#define ledVermelho 8                  //Porta em que o LED Vermelho está conectado

int statusBotao;                       //Variável que irá receber o status do botão: 1 = Pressionado e 0 = Desacionado
int ultimoStatusBotao = LOW;           //Variável Backup que salvará o último status do botão:  1 (HIGH) = Pressionado e 0 (LOW) = Desacionado. Inicialmente ela começa como LOW = 0 Desacionado
int contador = 0;                      //Variável que armazenará quantas vezes o botão foi pressionado

unsigned long tempoUltimoDebounce = 0; //Variável que armazenará o tempo do último Debounce
unsigned long tempoDebounce = 50;      //Tempo (em milissegundos)que é necessário manter o botão pressionado para ter a certeza de que ele foi pressionado de fato.

void setup() {
  pinMode(botao, INPUT);               //Declara o pino do botão como entrada
  pinMode(ledVerde, OUTPUT);           //Declara o pino do led verde como saída
  pinMode(ledAmarelo, OUTPUT);         //Declara o pino do led amarelo como saída
  pinMode(ledVermelho, OUTPUT);        //Declara o pino do led vermelho como saída
}

//Função principal
void loop() {

  debounceBotao();                     //Chama a função responsável pelo Debounce
  contagem();                          //Chama a função responsável por realizar as ações dependendo da quantidade de vezes que o botão foi pressionado

}

//Função responsável por fazer o Debounce
void debounceBotao() {

  int leitura = digitalRead(botao);                       //A variável leitura recebe a leitura do pino do botão: HIGH (pressionado) ou LOW (Desacionado)

  if (leitura != ultimoStatusBotao) {                     //Se a leitura atual for diferente da leitura anterior
    tempoUltimoDebounce = millis();                       //Reseta a variável tempoUltimoDebounce atribuindo o tempo atual para uma nova contagem
  }

  if ((millis() - tempoUltimoDebounce) > tempoDebounce) { //Se o resultado de (tempo atual - tempoUltimoDebounce) for maior que o tempo que determinamos (tempoDebounce), ou seja, já passou os 50 milissegundos que é o tempo que o botão precisa ficar pressionado para ter a certeza de que ele realmente foi pressionado? Se sim faça:
    if (leitura != statusBotao) {                         //Verifica se a leitura do botão mudou, ou seja, se é diferente do status que o botão tinha da última vez. Se sim, faça:
      statusBotao = leitura;                              //statusBotao recebe o que foi lido na variável leitura (pressionado = 1 e não pressionado = 0)
      if (statusBotao == HIGH) {                          //Se o statusBotao é igual a HIGH significa que o botão foi pressionado, então faça:
        contador++;                                       //Incrementa +1 na variável contador. (contador++ é o mesmo que: contador = contador +1)
      }
    }
  }
  ultimoStatusBotao = leitura;                            //Atualiza a variável ultimoStatusBotao para o que foi lido na variável leitura

}


//Função responsável por realizar as ações de acender os leds de acordo com a quantidade de vezes que o botão foi pressionado
void contagem() {

  if (contador == 1) {                 //Se o contador for 1 significa que o botão foi pressionado uma única vez
    digitalWrite(ledVerde, HIGH);      //Acender o LED verde
    digitalWrite(ledAmarelo, LOW);     //Apaga o LED amarelo
    digitalWrite(ledVermelho, LOW);    //Apaga o LED vermelho
  }
  if (contador == 2) {                 //Se o contador for 2 significa que o botão foi pressionado duas vezes
    digitalWrite(ledVerde, LOW);       //Apaga o LED verde
    digitalWrite(ledAmarelo, HIGH);    //Acende o LED amarelo
    digitalWrite(ledVermelho, LOW);    //Apaga o LED vermelho
  }
  if (contador == 3) {                 //Se o contador for 3 significa que o botão foi pressionado três vezes
    digitalWrite(ledVerde, LOW);       //Apaga o LED verde
    digitalWrite(ledAmarelo, LOW);     //Apaga o LED amarelo
    digitalWrite(ledVermelho, HIGH);   //Acende o LED vermelho
  }
  if (contador >= 4) {                 //Se o contador for maior ou igual a 4 significa que o botão foi pressionado 4 vezes ou mais
    contador = 0;                      //Zeramos a variável contador
    digitalWrite(ledVerde, LOW);       //Apaga o LED verde
    digitalWrite(ledAmarelo, LOW);     //Apaga o LED amarelo
    digitalWrite(ledVermelho, LOW);    //Apaga o LED vermelho
  }

}