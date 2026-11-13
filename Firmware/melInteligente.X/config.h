#define _XTAL_FREQ 4000000 

//---------------------------
#define DEMO
 
#ifdef DEMO
  #define INTERVALO_MEDICAO_S   10     // 5 min  -> 10 s
  #define INTERVALO_AQUEC_S     4      // 1 min  -> 4 s
  #define ESPERA_POS_MANEJO_S   30     // 10 min -> 30 s
  #define SEGUNDOS_POR_DIA      120    // 24 h   -> 2 min
#else
  #define INTERVALO_MEDICAO_S   300UL
  #define INTERVALO_AQUEC_S     60UL
  #define ESPERA_POS_MANEJO_S   600UL
  #define SEGUNDOS_POR_DIA      86400UL
#endif
 

#define CFG_ADCON1      0x82        // AN0-AN4 analógicos, PORTE digital, justificado à direita
#define CFG_OPTION_REG  0x0F        // Pull-ups PORTB on, INTEDG=0, prescaler no WDT 1:128 (~2,3 s)
#define CFG_T1CON       0b00000111  // Timer1: clock externo em T1CKI, assíncrono, 1:1, ligado
                                    // (hardware real com cristal: 0b00001111)
#define CFG_ADCON0_BASE 0x41        // Fosc/8 (Tad = 2 us) + ADON; canal em bits 5-3
 
 
#define CFG_TRISA       0xFF        // RA0-RA5 entradas
#define CFG_TRISB       0xFF        // RB0, RB4, RB5 entradas
#define CFG_TRISC       0b10000001  // RC0 (T1CKI) e RC7 (RX) entradas
#define CFG_TRISD       0x00        // LCD
#define CFG_TRISE       0x00        // Enables e alerta
 
/* ===================== BOTÕES (entradas digitais) ===================== */
// Pull-ups internos do PORTB ligados: solto = 1, apertado = 0
#define TAMPA           PORTBbits.RB0       // Endstop da tampa (INT)
#define TAMPA_TRIS      TRISBbits.TRISB0
#define BOTAO           PORTBbits.RB4       // Botão do display (interrupt-on-change)
#define BOTAO_TRIS      TRISBbits.TRISB4
#define BTN_TESTE_WDT   PORTBbits.RB5       // Só para demonstração
#define BTN_TESTE_TRIS  TRISBbits.TRISB5
 
/* ===================== TEMPERATURAS (LM35, analógicas) ===================== */
#define T_INT_TRIS      TRISAbits.TRISA0    // RA0/AN0 - LM35 interno
#define T_EXT_TRIS      TRISAbits.TRISA1    // RA1/AN1 - LM35 externo
#define CH_T_INT        0
#define CH_T_EXT        1
 
#define ADC_VREF        5000    // Vref = VDD
#define ADC_MAX         1023    // 10 bits
#define LM35_MV_POR_C   10      // 10 mV/°C -> T(décimos) = adc * 5000 / 1023
 
// Saídas
#define AQUECEDOR       PORTCbits.RC2
#define EN_SENSORES     PORTEbits.RE0
#define EN_LCD          PORTEbits.RE1
#define ALERTA          PORTEbits.RE2
 
// LCD (HD44780, 4 bits, RW no GND)
#define LCD_RS          PORTDbits.RD0
#define LCD_EN          PORTDbits.RD1
#define LCD_D4          PORTDbits.RD4
#define LCD_D5          PORTDbits.RD5
#define LCD_D6          PORTDbits.RD6
#define LCD_D7          PORTDbits.RD7
 
#define LCD_COLUNAS     20
#define LCD_LINHAS      4

