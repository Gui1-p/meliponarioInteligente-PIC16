#include <xc.h>
#include <mainFunctions.h>




void inicializarInputAnalogico(void){
    T_INT_TRIS   = 1;
    T_EXT_TRIS   = 1;
    PESO_TRIS    = 1; 
    BATERIA_TRIS = 1;
    
    ADCON1bits.ADFM  = 1;     // Resultado justificado à direita
    ADCON1bits.PCFG1 = 1;     // Selecao de pinos
    
    ADCON0bits.ADCS1 = 0;     // velocidade do oscilador em 4Mhz
    ADCON0bits.ADCS0 = 1;       
}

int lerTemperatura(bit sensor){ // 1 = interno e 0 = externo
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS1 = 0;
    
    if(sensor){ // lê o canal de temperatura interna no RA0/AN0
        ADCON0bits.CHS0 = 0;
        ADCON0bits.ADON  = 1;     // conversor ligado
    } 
    else{ // lê o canal de temperatura externa no RA1/AN1
        ADCON0bits.CHS0 = 1;       // canal 1 (001) = externa
        ADCON0bits.ADON  = 1;     // conversor ligado             
    }
    
    int leitura = converter();  //leitura recebe a juncao das partes do valor
    
    return leitura * 49 / 10; //para evitar o estouro do int é usado uma aproximação com perda de 0,27% no lugar da REF / bits a/d
    /*
     * 5000 / 1023 ~~ 5000 / 1000 ~~ 5
    */
}

int lerPeso(void)
{
    ADCON0bits.CHS2 = 1; //selecao canal
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 0;
    
    ADCON0bits.ADON  = 1; //liga o conversor
    
    int leitura = converter(); 
    
    int peso = leitura * PESO_PASSO;
    
    return peso;
}

int converter(void)
{
    __delay_us(100);
    ADCON0bits.GO_nDONE = 1; //começa a conversão
    while(ADCON0bits.GO_nDONE); //espera 
    
    return (ADRESH << 8) | ADRESL;
}
    
