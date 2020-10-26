/*
  Blink

  Baixe e instale a IDE do Arduino em:
  https://www.arduino.cc/en/Main/Software

  Esse exemplo possui o objetivo de realizar o primeiro contato da placa Arduino com o 
  programador.

  O presente curso é baseado na placa Arduino Mega.

  Objetivo do programa: 
  Acende um LED por um segundo e depois apaga por um segundo, repetidamente.

  A maioria dos Arduinos tem um LED integrado que você pode controlar. No UNO, MEGA e ZERO
  ele está conectado ao pino digital 13, no MKR1000 no pino 6. LED_BUILTIN é definido como
  o pino de LED correto, independente de qual placa é usada.
  Se você quiser saber a qual pino o LED on-board está conectado em seu Arduino
  modelo, verifique as especificações técnicas da sua placa em:
  https://www.arduino.cc/en/Main/Products

  Observe que há duas funções básicas no programa: void setup() e void loop(). 
  A primeira será utilizada para instruções de configurações da placa e é executada
  uma única vez quando a placa é ligada.
  Já a segunda é um loop infinito, essa substitui uma instrução while(1){...}. 

  Veja também como já foi exposto que pinMode(LED_BUILTIN, OUTPUT) configura o 
  pino 13 como saída. Veja que LED_BUILTIN é uma definição interna do compilador
  já que não é definido no código.

  A função digitalWrite(PINO, NIVEL) coloca o PINO em duas condições digitais
  de NIVEL, podendo ser HIGH ou LOW.  

  Para gravar selecionar: 
  * Selecionar a placa utilizada em TOOLS -> BOARD -> ARDUINO AVR BOARDS
  * A porta de conexão do Arduíno em TOOLS -> PORTS
  * Clicar em '->' Upload na barra de ferramentas.  

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
