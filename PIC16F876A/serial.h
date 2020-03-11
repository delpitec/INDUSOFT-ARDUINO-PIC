    #include "fuses.h"

    void startserial(void);
    void serialTX(char caractere);
    char serialRX(void);
    unsigned char serialRXstring(char *out, char endchar);
    void serialTXstring(char* s);
    char scanRXstring(char scanstring[], char endchar);