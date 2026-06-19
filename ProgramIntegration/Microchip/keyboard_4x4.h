/*
 * Description: Keyboard 4x4 Scanner
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 23.06.26
 * Dependences: 
 *   
 * Current: Yes
 * Maintainer: leandroteodoro.engenharia@gmail.com
 * Architecture: Microchip PIC16F877A
 * Compile/Interpreter: XC8 v3.10
 * Programer: PicKit 3 :: pk2cmd v1.27.03
 * Operational System: Ubuntu Mint 22 
 * Access: Public
 * Changelog: No
 * Readme and Documents: No
 * Links:
 * Comments:
 * -- PortB is fixed as keyboard.
 * 
   */

const int row1[4]={0x01,0x02,0x03,0x0a};
const int row2[4]={0x04,0x05,0x06,0x0b};
const int row3[4]={0x07,0x08,0x09,0x0c};
const int row4[4]={0x0e,0x00,0x0f,0x0d};
short int key_ready = 0;    
short int key_press = 0;  
int new_key;

/**
 * @brief  Funcion configures IO pins.
 * @details It set TRIS and Pull-Ups resistors.
 */
void keyboard_pin_config(void){
    TRISB = 0b11110000;   
    OPTION_REGbits.nRBPU = 0; //PortB Pull-Up ON 
}

void scan_key(void){  
       PORTB=0b11110000;
       if (PORTB == 0b11110000){
       key_press = 0;    //No key press
       return;
       }
   
       __delay_ms(20);                   //debouce

       if (PORTB == 0b11110000){
       key_press = 0;    //Check noise
       return;
       }

       // Key is pressed or not finished event
       if ((key_ready == 1) || (key_press == 1)){     
       return;
       }
       
       //Check the Cols
       PORTB=0b11111110;         
       if (PORTBbits.RB4 == 0) new_key=row1[0];
       if (PORTBbits.RB5 == 0) new_key=row2[0];
       if (PORTBbits.RB6 == 0) new_key=row3[0];
       if (PORTBbits.RB7 == 0) new_key=row4[0];

      PORTB=0b11111101;       
       if (PORTBbits.RB4 == 0) new_key=row1[1];
       if (PORTBbits.RB5 == 0) new_key=row2[1];
       if (PORTBbits.RB6 == 0) new_key=row3[1];
       if (PORTBbits.RB7 == 0) new_key=row4[1];

       PORTB=0b11111011;       
       if (PORTBbits.RB4 == 0) new_key=row1[2];
       if (PORTBbits.RB5 == 0) new_key=row2[2];
       if (PORTBbits.RB6 == 0) new_key=row3[2];
       if (PORTBbits.RB7 == 0) new_key=row4[2];

       PORTB=0b11110111;         //quarta coluna
       if (PORTBbits.RB4 == 0) new_key=row1[3];
       if (PORTBbits.RB5 == 0) new_key=row2[3];
       if (PORTBbits.RB6 == 0) new_key=row3[3];
       if (PORTBbits.RB7 == 0) new_key=row4[3];

       key_press = 1;
       key_ready = 1;
}

