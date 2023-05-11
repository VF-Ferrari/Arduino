#define DO 262
#define DOS 279
#define RE 294
#define RES 313
#define MI 330
#define FA 349
#define FAS 373
#define SOL 392
#define SOLS 419
#define LA 440
#define LAS 471
#define SI 494
#define DO_2 523

// Tempo das Notas

#define t4 2000   // 4 tempos
#define t2 1000   // 2 tempos
#define t1 500    // 1 tempo
#define t05 250   // 1/2 tempo
#define t025 125  // 1/4 tempo

#define pausa 125  // 1/4 tempo

int buzzer = 6;

int ritmo = 1.5;

int musica[] = {
  DO, DO,
  RE, DO, FA,
  MI, DO, DO,
  RE, DO, SOL,
  FA, DO, FA,
  DO, LA, FA,
  MI, RE, LAS, LAS,
  LA, FA, SOL,
  FA
};

int duracoes[] = {
  t05, t05,
  t1, t1, t1,
  t2, t05, t05,
  t1, t1, t1,
  t2, t05, t05,
  t1, t1, t1,
  t1, t1, t05, t05,
  t1, t1, t1,
  t2
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  for (int nota = 0; nota < (sizeof(musica) / sizeof(int)); nota++) {
    int duracaoNota = duracoes[nota] / ritmo;
    tone(buzzer, musica[nota], duracaoNota);
    delay(duracaoNota * 1.3);
    noTone(buzzer);
  }
  delay(5000);
}