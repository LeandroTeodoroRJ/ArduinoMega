/*
 * Description: Execute actions when specials numeric keys pressed
 * Stable: Yes
 * Version: 1.0.0
 * Last Uptate: 17.06.26
 * Dependences:
 *
 * Current: Yes
 * Maintainer: leandroteodoro.engenharia@gmail.com
 * Architecture: X64, Microchip PIC16F877A, Arduino Mega
 * Compile/Interpreter: GCC, XC8 v3.10, Arduino C++
 * Programer: PicKit 3 :: pk2cmd v1.27.03, Arduino IDE
 * Operational System: Ubuntu Mint 22 
 * Access: Public
 * Changelog: No
 * Readme and Documents: No
 * Links:
 * Comments:
 * -- Multi architecture example
 *
   */


#include <stdio.h>
#include <string.h>
#include <stdint.h>     //to use int8_t

#define boolean int

int8_t old_key_pressed_value;
float var = 15.3;
int8_t key_pressed_value;
char line1[20];
char line2[20];


//Prototipes
/*
Description:
Scan keyboard and save the key in int8_t key_pressed_value and return 1 if
a new key pressed.
*/
boolean scan_main_input(void);

/*
Description:
Executes procedures after action buttons.
*/
void exit_actions(void);

/*
Description:
Execute the system start configurations.
*/
void system_boot(void);

/*
Description:
Display update 2 lines, saved in line1 and line2 char array buffer
with 20 memory position.
*/
void display_update(void);

/*
Description:
Active output LED pin.
*/
void led_turn_on(void);

/*
Description:
Deactive output LED pin.
*/
void led_turn_off(void);

#include "x64interface.h"

int append_string_from_float(char *buffer, int start_point, float value, int precision, int buffer_size){
    // Validate input parameters
    if (buffer == NULL || start_point < 0 || start_point >= buffer_size)
        return 0;

    char temp[64];       // Temporary buffer for the formatted string
    int pos = 0;
    int negative = 0;

    // Normalize sign: work with positive value, track negativity
    if (value < 0) {
        negative = 1;
        value = -value;
    }

    if (precision == 0) {
        // Truncate to integer, no decimal point or fractional digits
        int truncated = (int)value;
        if (negative) truncated = -truncated;

        // Manual integer-to-string conversion
        if (truncated < 0) {
            temp[pos++] = '-';
            truncated = -truncated;
        }
        if (truncated == 0) {
            temp[pos++] = '0';
        } else {
            char rev[32];
            int rp = 0;
            while (truncated > 0) {
                rev[rp++] = '0' + (truncated % 10);
                truncated /= 10;
            }
            while (rp > 0)
                temp[pos++] = rev[--rp];
        }
    } else {
        // Compute 10^precision as scaling factor
        int mult = 1;
        for (int i = 0; i < precision; i++) mult *= 10;

        // Scale value and truncate to separate integer and fractional parts
        int total = (int)(value * (float)mult);
        if (negative) total = -total;

        int int_part = total / mult;
        int frac_part = total % mult;
        if (frac_part < 0) frac_part = -frac_part;

        // Write integer portion
        if (negative) temp[pos++] = '-';

        if (int_part < 0) int_part = -int_part;
        if (int_part == 0) {
            temp[pos++] = '0';
        } else {
            char rev[32];
            int rp = 0;
            while (int_part > 0) {
                rev[rp++] = '0' + (int_part % 10);
                int_part /= 10;
            }
            while (rp > 0)
                temp[pos++] = rev[--rp];
        }

        temp[pos++] = '.';   // Decimal separator

        // Write fractional part with leading zeros via right-to-left extraction
        char frac_rev[32];
        int fr = 0;
        for (int i = 0; i < precision; i++) {
            frac_rev[fr++] = '0' + (frac_part % 10);
            frac_part /= 10;
        }
        while (fr > 0)
            temp[pos++] = frac_rev[--fr];
    }

    temp[pos] = '\0';     // Null-terminate the temporary string

    // Check if concatenation fits within the buffer
    if (start_point + pos >= buffer_size)
        return 0;

    strcpy(buffer + start_point, temp);
    return 1;             // Success
}

void clear_lines(void){
    for (int i=0; i<20; i++){
        line1[i] = ' ';
        line2[i] = ' ';
    }
}

void concatenate_error(void){
    clear_lines();
    strcpy(line1, "CONC. ERROR");
}

void key_action(void){
    if (key_pressed_value == 5){
        clear_lines();
        strcpy(line1, "Last Val: ");
        strcpy(line2, "New Val: ");
        if (append_string_from_float(line1, 10, var, 1, sizeof(line1)) == 0) concatenate_error();
        var = var + 0.82;
        if (append_string_from_float(line2, 9, var, 2, sizeof(line2)) == 0) concatenate_error();
        display_update();
    }
    if (key_pressed_value == 1){
        led_turn_on();
    }
    if (key_pressed_value == 2){
        led_turn_off();
    }
    exit_actions();
}

void main(void){
    system_boot();
    clear_lines();
    strcpy(line1, "RUN ANYWHRE");
    display_update();
    while(1){
        if (scan_main_input() == 1){
            key_action();
        }
    }
}
