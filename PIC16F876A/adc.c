#include "fuses.h"
#define SBIT_ADON     0    // quantidade de bits no salto da configuração de AD ON
#define SBIT_CHS0     3    // quantidade de bits no salto da configuração do canal

void startADC(void)
 {
   ADCON0 = 0x00;          // sampling freq=osc_freq/2,ADC off initially
   ADCON1= 0x84;           // All pins are configured as Analog pins and ADC result is right justified  
}

unsigned int ADC_Read(int adcChannel)
 {  
    ADCON0 = (1<<SBIT_ADON) | (adcChannel<<SBIT_CHS0);  //seleciona canal desejado e liga o ADC

    __delay_us(50);                                     //tempo de leitura (previsto no datasheet) para conversão
    GO=1;                           // Start ADC conversion
    while(GO_DONE==1);              // Wait for the conversion to complete
                                    // GO_DONE bit will be cleared once conversion is complete
    return((ADRESH<<8) + ADRESL);   // return right justified 10-bit result

 }