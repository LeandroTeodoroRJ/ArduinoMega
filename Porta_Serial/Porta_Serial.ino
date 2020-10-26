//*****************************************************************
//                   UTILIZANDO A USART
//*****************************************************************
/*
 * Na função Serial.begin podemos ter Serial, Serial1, Serial2, Serial3, 
 * respectivamente para as portas seriais de 0 a 4. No Arduino Mega a 
 * porta serial 0 está ligada a interface USB. As configurações de 
 * baud rate podem ser: 4800, 9600, 19200 e 38400.
 * Para os testes utilizar o Serial Monitor na aba Tools.
 * 
 * Descrição das principais funções:
 * Serial.begin(speed, config) : Configura a serial
 * O argumento config seleciona a quantidade de bits, paridade e stop bits.
 * Pode ser:
    SERIAL_5N1
    SERIAL_6N1
    SERIAL_7N1
    SERIAL_8N1 (padrão)  8 bits, none(N) parity error, 1 stop bit
    SERIAL_5N2
    SERIAL_6N2
    SERIAL_7N2
    SERIAL_8N2
    SERIAL_5E1           even(E) parity error
    SERIAL_6E1
    SERIAL_7E1
    SERIAL_8E1
    SERIAL_5E2
    SERIAL_6E2
    SERIAL_7E2
    SERIAL_8E2
    SERIAL_5O1           odd(O) parity error
    SERIAL_6O1
    SERIAL_7O1
    SERIAL_8O1
    SERIAL_5O2
    SERIAL_6O2
    SERIAL_7O2
    SERIAL_8O2
 *
 * Serial.available(): Retorna o número de bytes no buffer.
 * Serial.write(byte): Escreve 1 byte na porta serial.
 */

#include "single_button.c"

//Entradas
const int CHAVE = 2;

//Variáveis
int byteRead;   //Recebe um byte do buffer da serial

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {

  if (button(CHAVE) == 1){
      Serial.println("Hello Computer"); //Envia uma cadeia de string para o computador
  }

  if (Serial.available())  //Verifica se tem dados diponível para leitura
  {
    byteRead = Serial.read(); //Lê byte mais recente no buffer da serial
    Serial.write(byteRead);   //Reenvia para o computador o dado recebido
    if (byteRead == 'H') digitalWrite(LED_BUILTIN, HIGH);  //Teste em ASCII
    if (byteRead == 'L') digitalWrite(LED_BUILTIN, LOW);
  }

}
