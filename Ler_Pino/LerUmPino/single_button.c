/****************************************************************
           ROTINA DE SCANEAMENTO DE TECLAS SIMPLES
*****************************************************************

OBSERVAÇÕES:
         1-Configurar o pino como entrada no arquivo principal
         2-O botão estará ativo em nível lógico 0
	 3-Hardware Arduino Mega 2560	

FUNÇÕES:
        short int button(int entrada) ->  DRIVE SIMPLES DE BOTÃO

ATUALIZADO: 25.10.20
*****************************************************************/

short int button(int entrada){
  static short int tmpbutton;
    if (digitalRead(entrada) == 1){
      tmpbutton = 0;	      //Soltou a tecla
      return 0;               //sai sem nenhuma pressionada
    }
    delay(20);                   //debouce
    if (digitalRead(entrada) == 1){
      tmpbutton = 0;
      return 0;               //verifica se não foi ruido.
    }
    if (digitalRead(entrada) == 0 && tmpbutton == 0){
      tmpbutton = 1;
      return 1;
    }
    else{
      return 0;
    }
}


//*****************************************************************