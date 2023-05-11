#define DO 1000
#define RE 2000
#define MI 4000
#define FA 6000

int tons[4] = { DO, RE, MI, FA };  //vetor que guarda as notas.
int sequencia[100] = {};           //vetor vazio - vai guardar as sequencias (que serão geradas aleatóriamente).
int rodada_atual = 0;
int passo_atual_na_sequencia = 0;

int pinosLeds[4] = { 2, 4, 6, 8 };
int pinosBotoes[4] = { 3, 5, 7, 9 };

int botao_pressionado = 0;
int perdeu_o_jogo = false;

void setup() {
  //pinMode(pinosLeds[0], OUTPUT);          //Dá para fazer das duas formas... linha por linha ou com o laço for.
  //pinMode(pinosLeds[1], OUTPUT);
  //pinMode(pinosLeds[2], OUTPUT);
  //pinMode(pinosLeds[3], OUTPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(pinosLeds[i], OUTPUT);
  }

  //pinMode(pinosBotoes[0], INPUT_PULLUP);   //Dá para fazer das duas formas... linha por linha ou com o laço for.
  //pinMode(pinosBotoes[1], INPUT_PULLUP);
  //pinMode(pinosBotoes[2], INPUT_PULLUP);
  //pinMode(pinosBotoes[3], INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {
    pinMode(pinosBotoes[i], INPUT_PULLUP);
  }

  pinMode(12, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  if (perdeu_o_jogo) {
    sequencia[100] = {};
    rodada_atual = 0;
    passo_atual_na_sequencia = 0;
    perdeu_o_jogo = false;
  }

  if (rodada_atual == 0) {
    TocarSomDeInicio();
    delay(500);
  }

  proximaRodada();
  reproduzirSequencia();
  aguardarJogador();
  delay(1000);
}

void TocarSomDeInicio() {
  tone(12, tons[0]);
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(pinosLeds[i], HIGH);
    }
    delay(200);
    for (int i = 0; i < 4; i++) {
      digitalWrite(pinosLeds[i], LOW);
    }
    delay(200);
  }
  noTone(12);
}

void proximaRodada() {
  int numero_sorteado = random(0, 4);
  sequencia[rodada_atual++] = numero_sorteado;
}

void reproduzirSequencia() {
  for (int i = 0; i < rodada_atual; i++) {
    tone(12, tons[sequencia[i]]);
    digitalWrite(pinosLeds[sequencia[i]], HIGH);
    delay(500);
    noTone(12);
    digitalWrite(pinosLeds[sequencia[i]], LOW);
    delay(100);
  }
}

void aguardarJogador() {
  for (int i = 0; i < rodada_atual; i++) {
    aguardarJogada();
    if (sequencia[passo_atual_na_sequencia] != botao_pressionado) {
      gameOver();
    }
    if (perdeu_o_jogo) {
      break;  //Quebra o laço "for" se perdeu_o_jogo for verdadeiro
    }
    passo_atual_na_sequencia++;
  }
  passo_atual_na_sequencia = 0;
}

void aguardarJogada() {
  boolean jogada_efetuada = false;
  while (!jogada_efetuada) {
    for (int i = 0; i < 4; i++) {
      if (!digitalRead(pinosBotoes[i])) {
        botao_pressionado = i;
        tone(12, tons[i]);
        digitalWrite(pinosLeds[i], HIGH);
        delay(500);
        noTone(12);
        digitalWrite(pinosLeds[i], LOW);
        jogada_efetuada = true;
      }
    }
    delay(10);
  }
}

void gameOver() {
  for (int i = 0; i < 4; i++) {
    tone(12, tons[i]);
    digitalWrite(pinosLeds[i], HIGH);
    delay(100);
    noTone(12);
    digitalWrite(pinosLeds[i], LOW);
  }
  perdeu_o_jogo = true;
}