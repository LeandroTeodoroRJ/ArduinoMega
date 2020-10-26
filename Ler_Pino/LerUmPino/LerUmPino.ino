
//*****************************************************************
//                  LENDO UMA ENTRADA DIGITAL
//*****************************************************************
/*
 *  A chave está ligada ao pino 2 com os resistores de pull-up 
 *  ativados. A cada precionada na chave o led interno da placa
 *  muda seu status de ligado para desligado e vice versa.
 */

#include "single_button.c"

//Entradas
const int CHAVE = 2;

//Variáveis
short int liga_desliga = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if (button(CHAVE) == 1){
      digitalWrite(LED_BUILTIN, liga_desliga);   
      liga_desliga = !liga_desliga;
  }
}
