#include <xc.h>
#include "portB.h"


void startPORTB(void){
    TRISB = 0x38;                                   // RB0 ~RB2 = saída / RB3 ~ RB7 = entrada
    PORTB = 0x00;                                   // Seta as saídas para 0
    OPTION_REGbits.nRBPU = 0;                       // habilita pullup do port b
}

unsigned char LePinoPortB(unsigned char canal){
    
    if (canal == 0){
        return(PORTBbits.RB0);
    }
    else if (canal == 1){
        return(PORTBbits.RB1);
    }
    else if (canal == 2){
        return(PORTBbits.RB2);
    }
    else if (canal == 3){
        return(PORTBbits.RB3);
    }
    else if (canal == 4){
        return(PORTBbits.RB4);
    }
    else if (canal == 5){
        return(PORTBbits.RB5);
    }
    else if (canal == 6){
        return(PORTBbits.RB6);
    }
    else if (canal == 7){
        return(PORTBbits.RB7+48);
    }
    else 
        return('E');
    
}

unsigned char EscrevePinoPortB(unsigned char canal, unsigned char dado){
   
    if (canal == 0){
        PORTBbits.RB0 = dado;
    }
    else if (canal == 1){
        PORTBbits.RB1 = dado;
    }
    else if (canal == 2){
        PORTBbits.RB2 = dado;
    }
    else if (canal == 3){
        PORTBbits.RB3 = dado;
    }
    else if (canal == 4){
        PORTBbits.RB4 = dado;
    }
    else if (canal == 5){
        PORTBbits.RB5 = dado;
    }
    else if (canal == 6){
        PORTBbits.RB6 = dado;
    }
    else if (canal == 7){
        PORTBbits.RB7 = dado;
    }
    else 
        return('E');
    
    return(1);
    
}