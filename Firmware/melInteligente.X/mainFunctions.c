#include <mainFunctions.h>
#include <xc.h>

float lerTemperatura(bit sensor){ // 1 = interno e 0 = externo
    if(sensor){
        // lê o canal de temperatura interna no RA0/AN0
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 0;
    } else {
        // lê o canal de temperatura interna no RA1/AN1
        ADCON0bits.CHS0 = 0;
        ADCON0bits.CHS1 = 0;
        ADCON0bits.CHS2 = 1;
    }
}


