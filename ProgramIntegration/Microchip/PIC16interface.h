 /*
  2  * Description: PIC16 interface section
  3  * Stable: Yes
  4  * Version: 1.0.0
  5  * Last Uptate: 17.06.26
  6  * Dependences:
  7  *   - stdint.h
  8  * Current: Yes
  9  * Maintainer: leandroteodoro.engenharia@gmail.com
 10  * Architecture: Microchip PIC16F877A
 11  * Compile/Interpreter: Microchip XC8
 12  * Programer: No needed
 13  * Operational System: Ubuntu Mint 22
 14  * Access: Public
 15  * Changelog: No
 16  * Readme and Documents: No
 17  * Links:
 18  * Comments:
 19  * -- Multi architecture example
 20  *
 21    */


/*
Description:
Scan keyboard and save the key in int8_t key_pressed_value and return 1 if
a new key pressed.
*/
// #include "lcd.h"
boolean scan_main_input(void){
    scan_key(); 
    if (key_ready == 1){
        key_pressed_value = new_key;
        return 1;
    }
    else{
        return 0;
    }
}

/*
Description:
Executes procedures after action buttons.
*/
void exit_actions(void){
    key_ready = 0;
}

/*
Description:
Execute the system start configurations.
*/
void system_boot(void){
    keyboard_pin_config();

    /* Set PORTD pins as outputs (LCD data + control) */
    LCD_D4_TRIS = 0;
    LCD_D5_TRIS = 0;
    LCD_D6_TRIS = 0;
    LCD_D7_TRIS = 0;
    LCD_RS_TRIS = 0;
    LCD_EN_TRIS = 0;

    /* Initialise the LCD */
    lcd_init();

    /* LED Configure Pin */
    TRISCbits.TRISC0 = 0;   //Output

    glbal_interrupts(DISABLE);

    __delay_ms(1000);
}

/*
Description:
Display update 2 lines, saved in line1 and line2 char array buffer
with 20 memory position.
*/
void display_update(void){
    int i;
    lcd_clear();
    lcd_goto(0, 0);

    for (i=0; line1[i] != '\0'; i++){   //'\0' end of string char
        lcd_data(line1[i]);
    }
    lcd_goto(1, 0);
    for (i=0; line2[i] != '\0'; i++){
        lcd_data(line2[i]);
    }
    
}

/*
Description:
Active output LED pin.
*/
void led_turn_on(void){
    PORTCbits.RC0 = 1;
}

/*
Description:
Deactive output LED pin.
*/
void led_turn_off(void){
    PORTCbits.RC0 = 0;
}
