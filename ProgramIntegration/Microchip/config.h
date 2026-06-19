/*
 * File:   config.h
 * Author: 
 * 
 * Configuration bits and oscillator definition for PIC16F877A.
 * Include this file before lcd.h so that _XTAL_FREQ is available
 * for the __delay_us() / __delay_ms() macros used by the LCD driver.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* ================================================================
 * Configuration bits for PIC16F877A
 * ================================================================ */

#pragma config FOSC = HS       /* High-speed crystal oscillator */
#pragma config WDTE = OFF      /* Watchdog Timer disabled */
#pragma config PWRTE = ON     /* Power-up Timer disabled */
#pragma config BOREN = ON      /* Brown-out Reset enabled */
#pragma config LVP = OFF       /* Low-Voltage Programming disabled */
#pragma config CPD = OFF       /* Data EEPROM code protection off */
#pragma config WRT = OFF       /* Flash program write protection off */
#pragma config CP = OFF        /* Flash code protection off */

/* Oscillator frequency for __delay_ms() and __delay_us() */
#define _XTAL_FREQ 20000000UL /* 20 MHz */

#endif /* CONFIG_H */
