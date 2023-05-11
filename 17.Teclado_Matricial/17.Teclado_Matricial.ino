#include <avr/io.h>        //Definiçőes de todos os registradores do ATMega328p
#include <util/delay.h>    //Biblioteca onde estão implementadas as rotinas _delay_ms() e _delay_us()
#include <avr/pgmspace.h>  //Biblioteca de uso do PROGMEM, que permite gravaçăo de dados constantes na memória flash

//Definiçőes de macros para o trabalho com bits
#define BitSet (arg, bit)((arg) |= (1 << bit))
#define BitClr (arg, bit)((arg) &= ~(1 << bit))
#define BitTst (arg, bit)((arg) & (1 << bit)) >> bit
#define BitFlp (arg, bit)((arg) ^= (1 << bit))

//----------------------------------------------------------------------------------------------------------------------------
// Definições de hardware (Teclado 4x4 requer uma porta com 8 bits)
//----------------------------------------------------------------------------------------------------------------------------

#define LINHA PIND    // Registrador para leitura das linhas
#define COLUNA PORTD  // Registrador para escrita das colunas

const unsigned char teclado[4][4] PROGMEM = {  //Mapa do teclado na memória Flash (de programa)

  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

//----------------------------------------------------------------------------------------------------------------------------
// Sub-rotina de inicialização do teclado
//----------------------------------------------------------------------------------------------------------------------------

void iniciar_teclado() {
  DDRD = 0x0F;   //Definição das entradas (linhas) e saídas (colunas) do teclado
  PORTD = 0xFF;  //Habilitação dos pull-ups do PORTD. Também coloca colunas em 1
}

//----------------------------------------------------------------------------------------------------------------------------
// Sub-rotina de leitura de tecla:
// a) Devolve 0xFF se não há pressão de uma tecla
// b) Devolve o valor da tecla pressionada apenas 1 vez
// c) Devolve 0xFF se há pressão contínua de tecla
//----------------------------------------------------------------------------------------------------------------------------

unsigned char ler_tecla() {
  unsigned char tecla = 0xFF, i, j, linha_4bits;
  static unsigned char teclaAnt = 0;

  for (j = 0; j < 4; j++) {
    BitClr(COLUNA, j);                                               //Limpa o bit, habilitando a coluna j (lógica invertida)
    _delay_ms(1);                                                    //Atrasa varredura. Também elimina o ruído da tecla
    linha_4bits = LINHA >> 4;                                        //Desloca 4 MSBs à direita (bits que representam as linhas)
    for (i = 0; i < 4; i++) {                                        //Varredura de linhas i
      if (BitTst(linha_4bits, i) == 0) {                             //Se botão foi pressionada na linha i
        tecla = pgm_read_byte &teclado[3 - i][3 - j]);               //Decodifica botão a partir de i,j
      }
    }
    BitSet(COLUNA, j);  //Seta o bit j, desabilitando a coluna (lógica invertida)
  }

  static unsigned char estado = 0;  //Máquina que controla pressão contínua de tecla
  switch (estado) {
    case 0:  //Estado (a): Sem tecla pressionada. Devolve 0xFF
      if (tecla != 0xFF) {
        estado = 1;
      }
      return 0xFF;
      break;
    case 1:  //Estado (b): Devolve a tecla pressionada apenas uma vez
      estado = 2;
      teclaAnt = tecla;
      return tecla;
      break;
    case 2:  //Estado (c): Tecla pressionada continuamente. Devolve 0xFF
      if (tecla != teclaAnt) {
        estado = 0;
        teclaAnt = 0;
      }
      return 0xFF;
      break;
  }
}

//----------------------------------------------------------------------------------------------------------------------------
// Definições de hardware - Considera R/W aterrado (nível 0)
//----------------------------------------------------------------------------------------------------------------------------

#define DADOS_LCD PORTC  //Porta contendo os 4 bits de dados do LCD
#define CONTR_LCD PORTC  //Porta onde estarão os pinos de controle RS e E do LCD
#define E PC5            //Pino de habilitação do LCD (enable)
#define RS PC4           //Pino seletor (dado ou instrução)
#define pulso_enable() \
  _delay_us(1); \
  BitSet(CONTR_LCD, E); \
  _delay_us(1); \
  BitClr(CONTR_LCD, E); \
  _delay_us(45)

//----------------------------------------------------------------------------------------------------------------------------
// Sub-rotina de envio de caracteres ou comandos ao LCD
//----------------------------------------------------------------------------------------------------------------------------

void cmd_LCD(unsigned char c, char cd) {
  // c é o dado e cd indica se é instrução ou caractere
  if (cd == 0)  //Instrução
    BitClr(CONTR_LCD, RS);
  else  // Caractere
    BitSet(CONTR_LCD, RS);

  //Primeiro nibble de dados – 4 MSBs (Operação binária atribui os 4 MSBs de c à porta
  DADOS_LCD)
  DADOS_LCD = (DADOS_LCD & 0xF0) | (c >> 4);
  pulso_enable();

  //Segundo nibble de dados - 4 LSBs (Operação binária atribui os 4 LSBs de c à porta
  DADOS_LCD)
  DADOS_LCD = (DADOS_LCD & 0xF0) | (0x0F & c);
  pulso_enable();

  if ((cd == 0) && (c < 4))  //Para instrução de retorno ou limpeza aguarda o LCD estar pronto
    _delay_ms(2);
}
//----------------------------------------------------------------------------------------------------------------------------
// Sub-rotina para inicialização do LCD com via de dados de 4 bits
//----------------------------------------------------------------------------------------------------------------------------

void iniciar_LCD_4bits() {  //Sequência de inicialização (obtida via datasheet)
  DDRC = 0xFF;              //Inicializa porta C para LCD (Considerando dados e controle na mesma porta)

  _delay_ms(10);  //Tempo de estabilização de Vcc do LCD ao ligar o hardware (>10ms)

  cmd_LCD(0x02, 0);  //Comando de sincronização
  cmd_LCD(0x28, 0);  //Comando de configuração da interface de 4 bits com 2 linhas (ver datasheet)
  cmd_LCD(0x06, 0);  //Direção do cursor -->
  cmd_LCD(0x0C, 0);  //Cursor inativo
  cmd_LCD(0x01, 0);  //Limpa display
  cmd_LCD(0x80, 0);  //Inicia cursor na primeira posição da esquerda da primeira linha
}

//----------------------------------------------------------------------------------------------------------------------------
//Sub-rotina de escrita de Strings no LCD
//----------------------------------------------------------------------------------------------------------------------------

void escreve_LCD(char *c) {
  while (*c) {
    cmd_LCD(*c, 1);
    *c++;
  }
}

//----------------------------------------------------------------------------------------------------------------------------
//Programa principal
//----------------------------------------------------------------------------------------------------------------------------

int main() {
  iniciar_LCD_4bits();              //Inicializa o LCD
  iniciar_teclado();                //Configura hardware do teclado
  escreve_LCD("Pressione Teclas");  //Envia String
  cmd_LCD(0xC0, 0);                 //Desloca cursor para posição 0xC0 (início da segunda linha)

  while (1) {
    unsigned char c = ler_tecla();  //Lê tecla
    if (c != 0xFF) {
      cmd_LCD(c, 1);
    }
  }
}