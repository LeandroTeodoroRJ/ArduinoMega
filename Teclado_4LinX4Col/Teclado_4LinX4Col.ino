//************************************************************************
//          EXEMPLO TECLADO 4 LINHAS POR 4 COLUNAS
//************************************************************************

/*
 * Para importtar a biblioteca keypad.zip vá em 
 * Sketch -> Include Library -> Add .ZIP Labrary -> Selecionar arquivo
 * e abrir.
 * Para saber se a biblioteca foi realmente importada para a IDE vá em
 * File -> Exemples -> e veja se os exemplos da biblioteca estão dispo-
 * níveis.
 * 
 */

#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA

const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO

//CONSTRUÇÃO DA MATRIZ DE CARACTERES
//As teclas foram alocadas como caracteres ASCII para serem
//transmitidas mais facilmente pelo terminal serial.
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Pinos de Entrada e Saída
byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {8, 9, 10,11}; //PINOS UTILIZADOS PELAS COLUNAS

//Variáveis
char tecla_pressionada;   //Variável que receberá o valor da tecla precionada

//INICIALIZAÇÃO DO TECLADO
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
}
  
void loop(){
  tecla_pressionada = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA
  if (tecla_pressionada){ //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
    Serial.print("Tecla pressionada : "); //IMPRIME O TEXTO NO MONITOR SERIAL
    Serial.println(tecla_pressionada); //IMPRIME NO MONITOR SERIAL A TECLA PRESSIONADA
  }
}
