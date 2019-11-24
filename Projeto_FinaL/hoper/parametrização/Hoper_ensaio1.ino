//ROTINA DE ENVIO DE DADOS

#include <SoftwareSerial.h>

SoftwareSerial SoftSerial(11, 10); // TX, RX
int buffer[64];
int count=0;
void setup()
{
    SoftSerial.begin(9600);               // VELOCIDADE DA SERIAL
    Serial.begin(9600);             

}

void loop()
{
    
    
    SoftSerial.write(0xAAFAD23689CAC0);           // frequência do Rádio 915Mhz
    SoftSerial.write(0xAAFAC300002580);          // taxa de transferencia de dados 9600
    SoftSerial.write(0xAAFAB40069);             // Budrate  300Khz
    SoftSerial.write(0xAAFA9607);              // potencia de transmissão 20bdm
    SoftSerial.write(0xAAFA1E00002580);       // velocidade da UART 9600
    SoftSerial.write(0xAAFA87);              // Intensiade de sinal pedir ao prof. ajuda parametro 9
    SoftSerial.write(0xAAFA78);             // disturbio de sinal , pedir ao prof. pra explicar
    //SoftSerial.write(0xAAFAA532);        // desvio de frequencia,, pedir ao prof. pra explicar



         
}
