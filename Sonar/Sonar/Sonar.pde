import processing.serial.*;
import java.awt.event.KeyEvent;
import java.io.IOException;
 
Serial myPort; 
 
String angle="";
String distance="";
String data="";
String noObject;
float pixsDistance;
int iAngle, iDistance;
int index1=0;
int index2=0;
PFont orcFont;
 
void setup() {
 
  size (1366, 700);
  smooth(); // Define que todos os desenhos tenham bordas suaves
  myPort = new Serial(this, "COM20", 9600); // Habilita a porta COM8 na velocidade 9600
  myPort.bufferUntil('.'); // Buffering ate o .
}
/**
 * @brief Inicia o desenho do radar e chama as outras funções
 */
void draw() {
 
  fill(98, 245, 31); // Define a cor verde usada para desenhar o radar
 
  noStroke(); // Sem desenho na tela.
  fill(0, 4); // Define a cor preto
  rect(0, 0, width, 1010);  // Desenha um retângulo na tela
 
  fill(98, 245, 31); // Define a cor verde claro usada para desenhar o radar
 
  drawRadar(); 
  drawLine();
  drawObject();
  drawText();
}
/**
 * @brief Ler os dados vindo da serial
 */
void serialEvent (Serial myPort) { 
 
  data = myPort.readStringUntil('.'); // Ler os dados como String até o . e armazena em data
  data = data.substring(0, data.length()-1); // Quebra em substring
 
  index1 = data.indexOf(","); // Separa por ,
  angle= data.substring(0, index1); // Atribui o valor ao ângulo
  distance= data.substring(index1+1, data.length()); // Atribui o valor a distância 
 
  iAngle = int(angle); // Converte o valor em inteiro
  iDistance = int(distance); // Converte o valor em inteiro
}
/**
 * @brief Desenha o gráfico base do radar
 */
void drawRadar() {
  pushMatrix(); // Push a matriz na pilha de matrizes
  translate(683, 700); // Deslocar o radar
  noFill(); // Define sem cor
  strokeWeight(2); // Define a largura do traçado usado nas linhas
  stroke(98, 245, 31); // Define a cor verde usada para desenhar linhas
  
  // Desenha as linhas do arco
  arc(0, 0, 1300, 1300, PI, TWO_PI);
  arc(0, 0, 1000, 1000, PI, TWO_PI);
  arc(0, 0, 700, 700, PI, TWO_PI);
  arc(0, 0, 400, 400, PI, TWO_PI);
  
  // Desenha as linhas dos ângulos
  line(-700, 0, 700, 0);
  line(0, 0, -700*cos(radians(30)), -700*sin(radians(30)));
  line(0, 0, -700*cos(radians(60)), -700*sin(radians(60)));
  line(0, 0, -700*cos(radians(90)), -700*sin(radians(90)));
  line(0, 0, -700*cos(radians(120)), -700*sin(radians(120)));
  line(0, 0, -700*cos(radians(150)), -700*sin(radians(150)));
  line(-700*cos(radians(30)), 0, 700, 0);
  
  popMatrix(); // Pop a matriz na pilha de matrizes
}
 
/**
 * @brief Desenha o objeto quando detectado
 */
void drawObject() {
  pushMatrix(); // Push a matriz na pilha de matrizes
  translate(683, 700); // Deslocar o objeto
  strokeWeight(9); // Define a largura do traçado usado nas linhas
  stroke(255, 10, 10); // Define a cor vermelho usada para desenhar linhas
  pixsDistance = iDistance*22.5; 
  // Verifica se o objeto está dentro dos 40 cm, se sim desenha as linhas vermelhas
  if (iDistance<40) {
     line(pixsDistance*cos(radians(iAngle)), -pixsDistance*sin(radians(iAngle)), 700*cos(radians(iAngle)), -700*sin(radians(iAngle)));
  }
  popMatrix(); // Pop a matriz na pilha de matrizes
}
/**
 * @brief Desenha as linhas no radar
 */
void drawLine() {
  pushMatrix(); // Push a matriz na pilha de matrizes
  strokeWeight(9); // Define a largura do traçado usado nas linhas
  stroke(30, 250, 60); // Define a cor verde usada para desenhar linhas
  translate(683, 700); // Deslocar a linhas
  line(0, 0, 700*cos(radians(iAngle)), -700*sin(radians(iAngle))); // Deslocar a linhas através do arco
  popMatrix(); // Pop a matriz na pilha de matrizes
}
 /**
 * @brief Desenha os textos no radar
 */
void drawText() { 
 
  pushMatrix(); // Push a matriz na pilha de matrizes
  if (iDistance>40) {
    noObject = "Out of Range"; // Se o objeto estiver fora dos 40cm seta "Out of Range"
  } else {
    noObject = "In Range"; // Caso o contrário seta "In Range"
  }
  fill(0, 0, 0); // Define a cor preto
  noStroke(); // Sem desenho na tela.
  rect(0, 1010, width, 1080); // Desenha um retângulo na tela
  fill(98, 245, 31); // Define a cor preto
  textSize(25); // Define a tamanho do texto
  text("10cm", 800, 690);  // Imprime o texto 10cm
  text("20cm", 950, 690);  // Imprime o texto 20cm
  text("30cm", 1100, 690); // Imprime o texto 30cm
  text("40cm", 1250, 690); // Imprime o texto 40cm
  textSize(40); // Define a tamanho do texto
  text("Object: " + noObject, 240, 1050); // Impime o texto Object: ...
  text("Angle: " + iAngle +" °", 1050, 1050); // Impime o texto Angle: ...
  text("Distance: ", 1380, 1050); // Impime o texto Distance: ...
  if (iDistance<40) {
    text("        " + iDistance +" cm", 1400, 1050); // Se o objeto estiver dentro dos 40cm imprime a distância do objeto em cm
  }
  textSize(25); // Define a tamanho do texto
  fill(98, 245, 60); // Define a cor verde
  translate(390+960*cos(radians(30)), 780-960*sin(radians(30))); // Deslocar o objeto
  rotate(-radians(-60)); // Rotaciona o objeto
  text("30°", 0, 0); // Imprime 30°
  resetMatrix();  // Reseta a matriz na pilha de matrizes
  translate(490+960*cos(radians(60)), 920-960*sin(radians(60))); // Deslocar o objeto
  rotate(-radians(-30)); // Rotaciona o objeto
  text("60°", 0, 0); // Imprime 60°
  resetMatrix();  // Reseta a matriz na pilha de matrizes
  translate(630+960*cos(radians(90)), 990-960*sin(radians(90))); // Deslocar o objeto
  rotate(radians(0)); // Rotaciona o objeto
  text("90°", 0, 0); // Imprime 90°
  resetMatrix();  // Reseta a matriz na pilha de matrizes
  translate(760+960*cos(radians(120)), 1000-960*sin(radians(120))); // Deslocar o objeto
  rotate(radians(-38)); // Rotaciona o objeto
  text("120°", 0, 0); // Imprime 120°
  resetMatrix();  // Reseta a matriz na pilha de matrizes
  translate(840+900*cos(radians(150)), 920-960*sin(radians(150))); // Deslocar o objeto
  rotate(radians(-60)); // Rotaciona o objeto
  text("150°", 0, 0); // Imprime 1500°
  popMatrix(); // Pop a matriz na pilha de matrizes
}
