/*
 * File:   lcd.h
 * Author: 
 * 
 * LCD driver for HD44780 compatible displays (16x2 / 20x4)
 * Interface: 4-bit mode
 * Microcontroller: PIC16F877A
 * Compiler: Microchip XC8
 *
 * Connections (see connections.csv):
 *   PIC pin  ->  LCD pin
 *   RD0      ->  D4
 *   RD1      ->  D5
 *   RD2      ->  D6
 *   RD3      ->  D7
 *   RD4      ->  RS
 *   RD5      ->  ENABLE
 *   RW       ->  GND (write only)
 */

#ifndef LCD_H
#define LCD_H

#include <xc.h>

/* ================================================================
 * LCD Pin Definitions
 * Modify the lines below to change the pin connections.
 * The naming follows the connections.csv columns:
 *   <PIC pin>,<LCD pin>
 * ================================================================ */

/* Data bus lines (LCD D4-D7 connected to PORTD bits 0-3) */
#define LCD_D4  PORTDbits.RD0
#define LCD_D5  PORTDbits.RD1
#define LCD_D6  PORTDbits.RD2
#define LCD_D7  PORTDbits.RD3

/* Control lines */
#define LCD_RS  PORTDbits.RD4
#define LCD_EN  PORTDbits.RD5

/* TRIS bits for data direction */
#define LCD_D4_TRIS  TRISDbits.TRISD0
#define LCD_D5_TRIS  TRISDbits.TRISD1
#define LCD_D6_TRIS  TRISDbits.TRISD2
#define LCD_D7_TRIS  TRISDbits.TRISD3
#define LCD_RS_TRIS  TRISDbits.TRISD4
#define LCD_EN_TRIS  TRISDbits.TRISD5

/* LCD dimensions (supports 16x2 and 20x4) */
#define LCD_COLS  16
#define LCD_LINES 2

/* HD44780 command macros */
#define LCD_CLEAR        0x01
#define LCD_HOME         0x02
#define LCD_ENTRY_MODE   0x06
#define LCD_DISPLAY_ON   0x0C
#define LCD_FUNC_SET     0x28   /* 4-bit, 2 lines, 5x8 font */

/* DDRAM addresses for each line */
#define LCD_LINE1_ADDR  0x00
#define LCD_LINE2_ADDR  0x40

/* ================================================================
 * Function prototypes
 * ================================================================ */

/**
 * Initializes the LCD in 4-bit mode.
 * Must be called once before using any other LCD functions.
 */
void lcd_init(void);

/**
 * Sends a command byte to the LCD (RS = 0).
 * @param cmd  Command byte (e.g. LCD_CLEAR, LCD_HOME)
 */
void lcd_command(unsigned char cmd);

/**
 * Sends a data byte to the LCD (RS = 1).
 * @param data  Character or data byte to write
 */
void lcd_data(unsigned char data);

/**
 * Writes a null-terminated string to the LCD at the current cursor position.
 * @param str  Pointer to the string
 */
void lcd_string(const char *str);

/**
 * Clears the entire LCD display and returns the cursor to home (row 0, col 0).
 */
void lcd_clear(void);

/**
 * Moves the cursor to the specified row and column.
 * @param row  Line number (0-based)
 * @param col  Column number (0-based)
 */
void lcd_goto(unsigned char row, unsigned char col);

/**
 * Writes a float value to the LCD with the specified number of decimal places.
 * @param value     Float value to display
 * @param decimals  Number of decimal places (0-9)
 */
void lcd_write_float(float value, unsigned char decimals);

/**
 * Writes an integer value to the LCD.
 * @param value  Integer value to display
 */
void lcd_write_int(int value);

/* ================================================================
 * LCD driver implementation
 * ================================================================ */

/**
 * Generates a delay in milliseconds.
 * Requires _XTAL_FREQ to be defined before including this header.
 */
static void lcd_delay_ms(unsigned int ms)
{
    while (ms--) {
        __delay_ms(1);
    }
}

/**
 * Sends a 4-bit nibble to the LCD and pulses the Enable line.
 * @param nibble  Lower 4 bits contain the value to send
 */
static void lcd_send_nibble(unsigned char nibble)
{
    /* Write the nibble to the data lines */
    LCD_D4 = (nibble >> 0) & 0x01;
    LCD_D5 = (nibble >> 1) & 0x01;
    LCD_D6 = (nibble >> 2) & 0x01;
    LCD_D7 = (nibble >> 3) & 0x01;

    /* Pulse Enable */
    LCD_EN = 1;
    __delay_us(2);   /* Enable pulse width >= 450 ns */
    LCD_EN = 0;
    __delay_us(100); /* Execution time >= 37 us */
}

/**
 * Sends a full command byte to the LCD (RS = 0, data or command).
 * The byte is transmitted as two nibbles: high nibble first, then low nibble.
 */
void lcd_command(unsigned char cmd)
{
    LCD_RS = 0;                    /* Command mode */
    lcd_send_nibble(cmd >> 4);     /* High nibble */
    lcd_send_nibble(cmd & 0x0F);  /* Low nibble  */
}

/**
 * Sends a data byte to the LCD (RS = 1, character data).
 */
void lcd_data(unsigned char data)
{
    LCD_RS = 1;                    /* Data mode */
    lcd_send_nibble(data >> 4);    /* High nibble */
    lcd_send_nibble(data & 0x0F); /* Low nibble  */
}

/**
 * Initialises the LCD in 4-bit mode according to the HD44780 datasheet.
 */
void lcd_init(void)
{
    /* Wait at least 15 ms after power-up for the LCD to be ready */
    lcd_delay_ms(20);

    /* ---- Initialisation sequence (4-bit mode) ---- */

    LCD_RS = 0;   /* Command mode */
    LCD_EN = 0;   /* Enable low (idle) */

    /* Step 1: Send 0x03 three times (8-bit mode, required for init) */
    lcd_send_nibble(0x03);
    lcd_delay_ms(5);
    lcd_send_nibble(0x03);
    __delay_us(150);
    lcd_send_nibble(0x03);
    __delay_us(150);

    /* Step 2: Send 0x02 to switch to 4-bit mode */
    lcd_send_nibble(0x02);
    __delay_us(150);

    /* Step 3: Configure function set (4-bit, 2 lines, 5x8 font) */
    lcd_command(LCD_FUNC_SET);
    __delay_us(150);

    /* Step 4: Display ON, cursor OFF, blink OFF */
    lcd_command(LCD_DISPLAY_ON);
    __delay_us(150);

    /* Step 5: Clear display */
    lcd_command(LCD_CLEAR);
    lcd_delay_ms(2);

    /* Step 6: Entry mode – increment address, no display shift */
    lcd_command(LCD_ENTRY_MODE);
    __delay_us(150);
}

/**
 * Clears the display and returns the cursor to the home position.
 */
void lcd_clear(void)
{
    lcd_command(LCD_CLEAR);
    lcd_delay_ms(2);  /* Clear command requires > 1.52 ms */
}

/**
 * Moves the cursor to the specified row and column (0-based).
 * Supports 16x2 and 20x4 displays.
 */
void lcd_goto(unsigned char row, unsigned char col)
{
    unsigned char address;

    switch (row) {
        case 0:
            address = LCD_LINE1_ADDR + col;
            break;
        case 1:
            address = LCD_LINE2_ADDR + col;
            break;
        case 2:
            /* Third line on 20x4: 0x14 (20 chars after line 1) */
            address = LCD_LINE1_ADDR + 0x14 + col;
            break;
        case 3:
            /* Fourth line on 20x4: 0x54 (20 chars after line 2) */
            address = LCD_LINE2_ADDR + 0x14 + col;
            break;
        default:
            address = LCD_LINE1_ADDR + col;
            break;
    }

    lcd_command(0x80 | address);
}

/**
 * Writes a null-terminated string to the LCD at the current cursor position.
 */
void lcd_string(const char *str)
{
    while (*str != '\0') {
        lcd_data(*str++);
    }
}

/**
 * Writes an integer value to the LCD (handles negative numbers).
 */
void lcd_write_int(int value)
{
    char buffer[6];
    unsigned char i = 0;
    unsigned char j;

    /* Handle negative numbers */
    if (value < 0) {
        lcd_data('-');
        value = -value;
    }

    /* Extract digits (least significant first) */
    do {
        buffer[i++] = (char)('0' + (value % 10));
        value /= 10;
    } while (value > 0);

    /* Print digits in correct order */
    for (j = i; j > 0; j--) {
        lcd_data(buffer[j - 1]);
    }
}

/**
 * Writes a float value to the LCD with the specified number of decimal places.
 */
void lcd_write_float(float value, unsigned char decimals)
{
    int int_part;
    float frac_part;
    unsigned char i;
    int digit;

    /* Extract integer part */
    int_part = (int)value;
    lcd_write_int(int_part);

    /* Decimal point */
    lcd_data('.');

    /* Extract fractional part */
    frac_part = value - (float)int_part;
    if (frac_part < 0.0F) {
        frac_part = -frac_part;
    }

    /* Print each decimal digit */
    for (i = 0; i < decimals; i++) {
        frac_part *= 10.0F;
        digit = (int)frac_part;
        lcd_data((unsigned char)('0' + digit));
        frac_part -= (float)digit;
    }
}

#endif /* LCD_H */
