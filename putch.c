/*
 * Function: putch
 * Weak implementation.  User implementation may be required
 * 
 * Utilidade: esta fun��o "direciona" para onde desejo enviar os dados escritos na fun��o printf
 * 
 */

#include "serial.h"

void 
putch(char c)
{
    
 serialTX(c);
    
}

