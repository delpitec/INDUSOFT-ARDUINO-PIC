/*
 * File:   main.c
 * Author: Rafael DSDel Pino (@rafael_delpino)
 * uC: PIC 16F876A
 * 
 * By: Rafel Del Pino 
 * Instagram: @rafael_delpino
 * 
 */

#include "fuses.h"
#include "serial.h"
#include "adc.h"
#include "portB.h"
#include <stdio.h>


void main(void) {
    
    char leitura[4]; 
    char RELE[3];
    startserial();                                               // inicializa as configurações da comunicação serial
    startADC();                                                  // Inicializa as configurações do conversor AD
    startPORTB();                                                // Inicializa as configurações da porta B
    
    while(1){
         
        leitura[0] = (char)LePinoPortB(3);                       // Le PORTB B3
        leitura[1] = (char)LePinoPortB(4);                       // Le PORTB B4
        leitura[2] = (char)LePinoPortB(5);                       // Le PORTB B5
        
        if(serialRXstring(RELE, 0x0D)){
            printf("%04u%04u%d%d%d\r",(unsigned int)ADC_Read(0),(unsigned int)ADC_Read(1),leitura[0], leitura[1], leitura[2]);                 
        } 
        
        EscrevePinoPortB(0,(unsigned char)RELE[0]);                             // Escreve relé 1
        EscrevePinoPortB(1,(unsigned char)RELE[1]);                             // Escreve relé 2
    }
    return;
}
