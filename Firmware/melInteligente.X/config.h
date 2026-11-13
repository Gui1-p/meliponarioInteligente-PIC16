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
 
#define INTERVALO_SAVE_RELOGIO_S  3600   // Salva o relógio na EEPROM a cada hora
#define TEMPO_DISPLAY_S           30     // LCD aceso após apertar o botão
#define TEMPO_APERTO_LONGO_MS     2000   // Aperto longo = dump do log na UART
#define SEGUNDOS_POR_TICK_T1      2      // Timer1: 32768 Hz / 65536 = overflow a cada 2 s
 
 
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
 
#define PRESSIONADO     0
#define SOLTO           1
#define TAMPA_FECHADA   0   // Tampa fechada aperta o endstop (contato ao GND)
#define TAMPA_ABERTA    1   // Se a fiação for invertida, troque estes dois valores
 
/* ===================== TEMPERATURAS (LM35, analógicas) ===================== */
#define T_INT_TRIS      TRISAbits.TRISA0    // RA0/AN0 - LM35 interno
#define T_EXT_TRIS      TRISAbits.TRISA1    // RA1/AN1 - LM35 externo
#define CH_T_INT        0
#define CH_T_EXT        1
 
#define ADC_VREF_MV     5000    // Vref = VDD
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
 
// UART
#define UART_BAUD       9600UL
 
/* ===================== CANAIS DO ADC ===================== */
// CH_T_INT e CH_T_EXT estão na seção TEMPERATURAS
#define CH_BATERIA      2       // RA2/AN2
#define CH_PAINEL       3       // RA3/AN3
#define CH_PESO         4       // RA5/AN4
#define ADC_AMOSTRAS    8       // Média de 8 leituras
 
 
#define BAT_FUNDO_ESCALA_DV     150     // 5 V no pino = 15,0 V
#define PAINEL_FUNDO_ESCALA_DV  250     // 5 V no pino = 25,0 V
#define PESO_FUNDO_ESCALA_10G   2000    // 5 V no pino = 20,00 kg
 
 
#define T_SETPOINT_DC   300     // 30,0 °C
#define T_HISTERESE_DC  10      // Liga < 29,0 °C, desliga > 31,0 °C
#define T_MIN_DC        280     // Abaixo: alerta se não conseguir aquecer
#define T_MAX_DC        340     // Acima: aquecedor desliga + alerta
#define T_CRITICA_DC    280     // Bateria média: só aquece abaixo disso
 
 
#define BAT_OK_DV       124     // >= 12,4 V: aquecedor liberado
#define BAT_BAIXA_DV    118     // <  11,8 V: aquecedor proibido + alerta
 
/* ===================== MAPA DA EEPROM ===================== */
#define EE_MAGIC_ADDR       0x00
#define EE_IDX_ADDR         0x01
#define EE_COUNT_ADDR       0x02
#define EE_T_MANEJO_ADDR    0x04    // uint32
#define EE_OFFSET_ADDR      0x08    // int16
#define EE_CALIB_ADDR       0x0A    // uint16
#define EE_RELOGIO_ADDR     0x0C    // uint32
#define EE_LOG_INICIO       0x10
#define EE_LOG_TAM_ENTRADA  8
#define EE_LOG_N_ENTRADAS   30
#define EE_MAGIC_VALOR      0xA5
 
#define LOG_MIN_ENTRADAS_CRESC  7   // Menos que isso: mostra "--"
 
// Bits do byte de flags da entrada diária
#define FLAG_MANEJO         0x01
#define FLAG_AQUECEDOR      0x02
#define FLAG_BAT_BAIXA      0x04
#define FLAG_RESET_WDT      0x08
#define FLAG_CARREGANDO     0x10
