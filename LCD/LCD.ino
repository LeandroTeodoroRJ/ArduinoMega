// **********************************************************************
//                   UTILIZAÇÃO DO DISPLAY LCD
// **********************************************************************

#include <LiquidCrystal.h> // Include do o display LCD 

// Constantes do LCD
const int numLinhas = 4;
const int numColu = 20;

// Saidas do LCD
// Esquema de ligação dos pinos do LCD:
// 1 - VSS - GND
// 2 - VDD - VDD
// 3 - VO  - Comum do potenciômetro de 10K
// 15 - A  - VCC
// 16 - K  - GND
// ** Não esquecer de conectar o pino 5(R/W) do LCD ao terra.
const int rs_pin = 12; 
const int enable_pin = 11;
const int d4_pin = 5;
const int d5_pin = 4;
const int d6_pin = 3;
const int d7_pin = 2;

//Função de configuração do LCD
LiquidCrystal lcd(rs_pin, enable_pin, d4_pin, d5_pin, d6_pin, d7_pin);

void setup()
{
  lcd.begin(numColu, numLinhas);  //Inicializa o LCD com a configuração de linhas e colunas
  lcd.print("Hello Word!");  // Escreve no LCD
  lcd.setCursor(0, 1);  //Posiciona o cursor do LCD (coluna, linha). A contagem começa do Zero.
  lcd.print("Arduino Mega 2560.");
  lcd.setCursor(0, 2);  
  lcd.print("Exemplo LCD");
  lcd.setCursor(2, 3);  
  lcd.print("LeandroTeodoroRJ");
}

void loop()
{
 //Loop function
}
      
    
