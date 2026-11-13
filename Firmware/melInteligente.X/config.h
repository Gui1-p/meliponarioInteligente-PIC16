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
 
/* ===================== BOTÕES (entradas digitais) ===================== */
// Pull-ups internos do PORTB ligados: solto = 1, apertado = 0
#define TAMPA           PORTBbits.RB0       // Endstop da tampa (INT)
#define TAMPA_TRIS      TRISBbits.TRISB0
#define BOTAO           PORTBbits.RB4       // Botão do display (interrupt-on-change)
#define BOTAO_TRIS      TRISBbits.TRISB4
#define BTN_TESTE_WDT   PORTBbits.RB5       // Só para demonstração
#define BTN_TESTE_TRIS  TRISBbits.TRISB5
 
/* ===================== ENTRADAS ANALOGICAS (LM35, analógicas) ===================== */
#define T_INT_TRIS      TRISAbits.TRISA0    // RA0/AN0 - LM35 interno
#define T_EXT_TRIS      TRISAbits.TRISA1    // RA1/AN1 - LM35 externo
 
#define PESO_TRIS       TRISAbits.TRISA5    // Balanca
#define PESO_PASSO      20                  //passo da balança em gramas, considerando balança de 20,5KG

#define BATERIA_TRIS    TRISAbits.TRISA2    // Tensao da Bateria
#define BATERIA_PASSO   15                  //passo da bateria, considerando uma bateria de cerca de 15V


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

