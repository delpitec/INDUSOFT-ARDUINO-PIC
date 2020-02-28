/*
 * Function: putch
 * Weak implementation.  User implementation may be required
 * 
 * Utilidade: esta função "direciona" para onde desejo enviar os dados escritos na função printf
 * 
 */

#include "serial.h"

void 
putch(char c)
{
    
 serialTX(c);
    
}

