/*
 * Description: Other utils fictions
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 30.06.26
 * Dependences: 
 *   -- lcd.h
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
 * 
 */

// #include <pic16f877a.h>

#define ENABLE 1
#define DISABLE 0

void debug_message(void){
    lcd_clear();
    lcd_goto(0, 0);
    lcd_string("DEBUG MESSAGE");
    __delay_ms(3000);
}

void glbal_interrupts(_Bool value){
    INTCONbits.GIE = value;
}