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

int segundos = 0;
int instanteUltimoManejo = 0;

void __interrupt() relogio(void)
{
    if (PIR1bits.TMR1IF) {          // se foi o Timer 1
        PIR1bits.TMR1IF = 0;        // limpa flag
        segundos += 2;              // se passaram 2 segundos
    }
}

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
     configurar prescaler do watchdog timer
     OPTION_REGbits.PS0
     OPTION_REGbits.PS1
     OPTION_REGbits.PS2
     */
    
    // configurando o Timer 1 e interrupções
    
    T1CONbits.TMR1CS = 1;   // clock externo
    T1CONbits.T1SYNC = 1;   // assíncrono
    PIE1bits.TMR1IE = 1;    // habilito interrupção do timer 1
    INTCONbits.PEIE = 1;    // habilita periféricos (timer 1)
    
    T1CONbits.T1CKPS0 = 0;  // prescaler 1:1
    T1CONbits.T1CKPS1 = 0;
    
    INTCONbits.GIE = 1;     // habilita a interrupção global
    T1CONbits.ON = 1;       // liga timer 1
    
    // medição
    if(segundos - instanteUltimoManejo >= INTERVALO_MEDICAO_S){
        /*
         * lê temperaturas, bateria e peso;
         * decidir se liga ou não o aquecedor;
         * decidir se liga o alerta;
         */
    }
        
    return;
}