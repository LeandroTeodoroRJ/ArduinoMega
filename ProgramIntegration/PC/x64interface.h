
/* Implementation section */

#include <stdio.h>

/*
Description:
The keypad is 4x4 model, so the keypad range is 0 to 16.
If the function return a number greather then 20 it is a error.
*/
int8_t read_key_from_file(void){
    FILE *file = fopen("keyboard.input", "r");
    if (file == NULL) {
        return 20;      //ERROR
    }
    int value;
    if (fscanf(file, "%d", &value) != 1) {
        fclose(file);
        return 20;      //ERROR
    }
    fclose(file);
    return (int8_t)value;
}

boolean scan_main_input(void){
    //Wait program mode
/*
    char tmp;
    scanf("%1c", &tmp);
    key_pressed_value = (int8_t)(tmp - '0');
    return 1;
*/

    //Simulation keyboard as file
    int8_t kvalue = read_key_from_file();
    old_key_pressed_value = key_pressed_value;
    if (old_key_pressed_value == kvalue){
        return 0;
    }
    else{
        key_pressed_value = kvalue;
        return 1;
    }
}

void exit_actions(void){

}

void system_boot(void){
    key_pressed_value = 0;
    old_key_pressed_value = 0;
}

void display_update(void){
    printf("%s\n", line1);
    printf("%s\n", line2);
}


void led_turn_on(void){
    printf("Led is turn ON.\n");
}

void led_turn_off(void){
    printf("Led is turn OFF.\n");
}


