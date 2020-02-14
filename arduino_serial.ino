void setup() { 
  
 pinMode(4, INPUT_PULLUP);    // Pino 4 é entrada com PullUp Interno
 pinMode(5, INPUT_PULLUP);    // Pino 5 é entrada com PullUp Interno
 pinMode(6, INPUT_PULLUP);    // Pino 6 é entrada com PullUp Interno
 pinMode(7, OUTPUT);          // Pino 7 é saída
 pinMode(8, OUTPUT);          // Pino 8 é saída
 
 Serial.begin(9600);
}
  
//--- Função que lê uma string da Serial e retorna-a -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
String leStringSerial(){
  String conteudo = "";                           // Zera string conteúdo
  char caractere = 0;                             // Zera string caractere
  
  while(Serial.available() > 0) {                 // Enquanto receber algo pela serial
    caractere = Serial.read();                    // Lê byte da serial
    conteudo.concat(caractere);                   // Concatena valores      
    delay(10);                                    // Aguarda buffer serial ler próximo caractere
  }
      
  return conteudo;                                // retorna conteúdo lido
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void loop() {
  unsigned int ANALOGICO_0 = 0;                   // Variável que armazenará valor de A0
  unsigned int ANALOGICO_1 = "";                  // Variável que armazenará valor de A1
  unsigned int RELE1 = 0;                         // Variável que armazenará valor recebido para Relé 1
  unsigned int RELE2 = 0;                         // Variável que armazenará valor recebido para Relé 2
  char DIP1 = 0;                                  // Variável que armazenará valor de D6
  char DIP2 = 0;                                  // Variável que armazenará valor de D5
  char DIP3 = 0;                                  // Variável que armazenará valor de D4
  char sLEITURAS[15];                             // buffer para organizar valores que serão enviados na serial
  String recebido = "";

while(1){

   ANALOGICO_0 = analogRead(A0);                  // Le A0 e armazena em ANALOGICO_0
   ANALOGICO_1 = analogRead(A1);                  // Le A1 e armazena em ANALOGICO_1  
   DIP1 = digitalRead(6);                         // Le D6 e armazena em DIP1
   DIP2 = digitalRead(5);                         // Le D5 e armazena em DIP2
   DIP3 = digitalRead(4);                         // Le D4 e armazena em DIP3

   
   if (Serial.available() > 0){                   // Se receber algo pela serial
      recebido = leStringSerial();                // Lê toda string recebida
      RELE1 = recebido.charAt(0) - '0';           // conversão Char to decimal caractere 0 da string recebida (RELE 1)
      RELE2 = recebido.charAt(1) - '0';           // conversão Char to decimal caractere 1 da string recebida (RELE 2)
      digitalWrite(7, RELE1);                     // D7 = RELE1 (0 = desligado / 1 = ligado)
      digitalWrite(8, RELE2);                     // D8 = RELE1 (0 = desligado / 1 = ligado)
      sprintf (sLEITURAS, "%04u%04u%d%d%d\r",ANALOGICO_0,ANALOGICO_1,DIP1,DIP2,DIP3); // Organiza tudo no buffer sLEITURAS  
      Serial.write(sLEITURAS);                    // Envia dados organizados na serial
   }
}
}
