#include "fuses.h"
#include "serial.h"


void startserial(void){
    SPBRG = 12;               // Valor do registrador SPBRG para 9600bps 
    TXSTAbits.BRGH = 0 ;      // Transmissao de baixa velocidade
    TXSTAbits.SYNC = 0;       // Assyncronus mode
    RCSTAbits.SPEN = 1;
    
    // Tx (8 bits )
    TXSTAbits.TX9 = 0;        // Transmissao de 8bits
    TXSTAbits.TXEN = 1;       // Habilita transmissão
    
    // Rx (8 bits)
    RCSTAbits.RX9 = 0;        // Recepção 8bits
    RCSTAbits.CREN = 1;       // Habilita recepção
    
}

void serialTX(char c)
{
    while (!TXIF);
    TXREG = c;
}

char serialRX(void)
{
    while(!RCIF)
      NOP();
      return (RCREG);
}
 
 unsigned char serialRXstring(char *out, char endchar){
     unsigned char i = 0;
        while(RCIF){
            for(unsigned char i = 0; ; i++){
                if((out[i] = serialRX()) == endchar)
                    break;
            }
            RCIF = 0;
            return(1);
        }
            
            //out[0] = '1';    
            //out[1] = '0';
            //out[2] = '\r';  
            //return(1);
            
         
    return(0);
 }

char scanRXstring(char scanstring[], char endchar){
    char i = 0;
    char RXstring[10];
    unsigned int ScanstringSoma = 0, RXstringSoma = 0;
    
    while(scanstring[i] != endchar){
        ScanstringSoma+= scanstring[i];
        i++;
    }
    
    serialRXstring(RXstring, endchar);
    
    i = 0;
    while(RXstring[i] != endchar){
        RXstringSoma += RXstring[i];
        i++;
    }
    
    if(ScanstringSoma == RXstringSoma)
        return(1);
    else
        return(0);
    
    
}

 
 void serialTXstring(char* s)
{
	int i =0;
	
	while (s[i] != 0x00)
		serialTX(s[i++]);

}