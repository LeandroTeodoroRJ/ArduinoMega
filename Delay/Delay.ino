/*
  Delay

  Esse exemplo possui o objetivo apresentar as funções de delay do Arduino
  aproveitando o código Blink. O programa também altera o nível do sinal
  do pino 8.

  As funções de delay são utilizadas para parar o fluxo principal do pro-
  grama por um tempo determinado. São elas:
  delay(ms): onde o valor argumento representa o valor em mili-segundos de delay.
  delayMicroseconds(us): onde o argumento passado representa o valor de delay
      em micro-segundos. 

  Agora você pode alterar o delay no programa e verificar os resultados :)

*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, OUTPUT);             //Configura o pino 8 como saída
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   
  digitalWrite(8, HIGH);             //Coloca o pino 8 em nível alto
  delay(1000);                       // Delay
  digitalWrite(LED_BUILTIN, LOW);    
  digitalWrite(8, LOW);              //Coloca o pino 8 em nível baixo
  delay(1000);                       // Delay
}
