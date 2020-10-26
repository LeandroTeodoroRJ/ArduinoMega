// **********************************************************************
//                   UTILIZAÇÃO DO DISPLAY LCD
// **********************************************************************

#include <LiquidCrystal.h> // Include do o display LCD 

// Constantes do LCD
const int numLinhas = 4;
const int numColu = 20;

// Saidas do LCD
// Não esquecer de conectar o pino R/W do LCD ao terra.
const int rs_pin = 12; 
const int enable_pin = 11;
const int d4_pin = 5;
const int d5_pin = 4;
const int d6_pin = 3;
const int d7_pin = 2;

//Constantes e Variáveis
int var_decimal = 255;
float var_real = 0.12345678;
char var_char = 'M';
char displayString[21] = "";  //Buffer que armazena a linha no formato string
char str_temp[10]; //Buffer temporário para conversão de float para string

//Função de configuração do LCD
LiquidCrystal lcd(rs_pin, enable_pin, d4_pin, d5_pin, d6_pin, d7_pin);

void setup()
{
  lcd.begin(numColu, numLinhas);  //Inicializa o LCD com a configuração de linhas e colunas
}

void loop()
{
 //Tela 1
  lcd.clear();  //Limpa a tela do LCD
  lcd.setCursor(0, 0);  //Posiciona o cursor do LCD (coluna, linha). A contagem começa do Zero.
  sprintf(displayString, "Num. Inteiro: %d", var_decimal);  //Converter de inteiro para string e armazena no buffer de linha
  lcd.print(displayString);
  lcd.setCursor(0, 1);  
  sprintf(displayString, "Hexadecimal: %x", var_decimal);  //Converter de inteiro para hexadecimal minúsculo e armazena no buffer de linha como string
  lcd.print(displayString);
  lcd.setCursor(0, 2);  
  sprintf(displayString, "Hexadecimal: %X", var_decimal);  //Converter de inteiro para hexadecimal maiúsculo e armazena no buffer de linha como string
  lcd.print(displayString);
  lcd.setCursor(0, 3);
  sprintf(displayString, "Imprime char: %c", var_char);  //Converter de char para string e armazena no buffer de linha
  lcd.print(displayString);
  delay(3000); //Delay

 //Tela 2
  lcd.clear();  //Limpa a tela do LCD
  lcd.setCursor(0, 0);  //Posiciona o cursor do LCD (coluna, linha). A contagem começa do Zero.
  dtostrf(var_real, 4, 2, str_temp);  // Tamanho de 4 casas incluindo o 'ponto', 2 casas de precisão. O valor float e gravado em str_temp como string
  sprintf(displayString, "Num. Float: %s", str_temp);  //Concatena a string da função com a string gravada em str_temp
  lcd.print(displayString);
  lcd.setCursor(0, 1);
  dtostrf(var_real, 6, 2, str_temp);  // Tamanho de 6 casas incluindo o 'ponto', 2 casas de precisão. O valor float e gravado em str_temp como string  
  sprintf(displayString, "Num. Float: %s", str_temp);  //Concatena a string da função com a string gravada em str_temp
  lcd.print(displayString);
  lcd.setCursor(0, 2);
  dtostrf(var_real, 6, 4, str_temp);  // Tamanho de 6 casas incluindo o 'ponto', 4 casas de precisão. O valor float e gravado em str_temp como string    
  sprintf(displayString, "Num. Float: %s", str_temp);  //Concatena a string da função com a string gravada em str_temp
  lcd.print(displayString);
  lcd.setCursor(0, 3);
  dtostre(var_real,str_temp,DTOSTR_ALWAYS_SIGN,DTOSTR_UPPERCASE);   //Converte de float para notação científica
  sprintf(displayString, "Num. Float: %s", str_temp);  //Concatena a string da função com a string gravada em str_temp
  lcd.print(displayString);
  delay(3000); //Delay

 
}
      

 /*
      EXEMPLO DE OUTROS FORMATOS:
      %s:   string
      %x:   hexadecimal com letras minúsculas
      %X:   hexadecimal com letras maiúsculas
      %L*:  Formato longo(16 ou 32 bits),
            sendo * qualquer umas das letras 
            referentes a números já tratadas
      */

// sprintf(displayString, "value:%7d.%d%d", (int)num, int(num*10)%10, int(num*100)%10);
//  sprintf(displayString, "Num. Inteiro: %d", (int)var_decimal);
