//Rotina para calcular a velocidade de
//um tubo pitot e sensor diferencial de pressão MPXV7002DP

float V_0 = 5.0;    // tensão de alimentação do sensor de pressão
float rho = 1.204;  // densidade do ar

// parâmetros para cálculo de média e deslocamento
int offset = 0;
int offset_size = 10;
int veloc_mean_size = 20;
int zero_span = 2;

// configura e calcula o deslocamento
void setup() {
  Serial.begin(9600);
  for (int ii = 0; ii < offset_size; ii++) {
    offset += analogRead(A0) - (1023 / 2);
  }
  offset /= offset_size;
}

void loop() {
  float adc_avg = 0;
  float veloc = 0.0;

  // calcula a média de algumas leituras do ADC para estabilidade
  for (int ii = 0; ii < veloc_mean_size; ii++) {
    adc_avg += analogRead(A0) - offset;
  }
  adc_avg /= veloc_mean_size;

  // certifique-se de que a leitura do ADC esteja abaixo de 512, então a igualamos a uma velocidade negativa
  if (adc_avg > 512 - zero_span and adc_avg < 512 + zero_span) {
  } else {
    if (adc_avg < 512) {
      veloc = -sqrt((-10000.0 * ((adc_avg / 1023.0) - 0.5)) / rho);
    } else {
      veloc = sqrt((10000.0 * ((adc_avg / 1023.0) - 0.5)) / rho);
    }
  }
  Serial.println(veloc);  // imprime o valor da velocidade
  delay(10);              // atraso para estabilidade
}