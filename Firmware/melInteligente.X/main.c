/*
 * File:   main.c
 * Author: Ísis Valois Sampaio e Guilherme Paiva Peres
 *
 * Created on 12 de Novembro de 2026, 19:18
 */

#pragma config FOSC  = XT       // Cristal de 4 MHz
#pragma config WDTE  = ON       // Watchdog ligado (não pode ser desligado por software)
#pragma config PWRTE = ON       // Power-up timer
#pragma config BOREN = ON       // Brown-out reset
#pragma config LVP   = OFF      // Libera o RB3 como I/O comum
#pragma config CPD   = OFF      // Sem proteção da EEPROM de dados
#pragma config WRT   = OFF      // Sem proteção de escrita na flash
#pragma config CP    = OFF      // Sem proteção de código

#include <xc.h>
#include <stdint.h>
#include <mainFunctions.h>
#include <config.h>

void main(void) {
    TRISA = 0xFF;           // RA0-RA5 entradas (analógicas)
    TRISB = 0xFF;           // RB0, RB4, RB5 entradas
    TRISC = 0b10000001;     // RC0 (T1CKI) e RC7 (RX) entradas, resto saída
    TRISD = 0x00;           // LCD
    TRISE = 0x00;           // enables e alerta
    
    PORTC = 0;
    PORTD = 0;
    PORTE = 0;
    
    OPTION_REGbits.RBPU = 0; // ativa pull-ups
    OPTION_REGbits.INTEDG = 0; // ativa interrupção externa em borda de descida (botão pull-up)
    OPTION_REGbits.PSA = 1; // prescaler do WDT
    /*
     CONFIGURAR PRESCALER
     OPTION_REGbits.PS0
     OPTION_REGbits.PS1
     OPTION_REGbits.PS2
     */
            
    return;
}