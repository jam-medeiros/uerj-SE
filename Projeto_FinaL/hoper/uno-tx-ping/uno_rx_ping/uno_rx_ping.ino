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
    delay(1000);
    SoftSerial.write(0xAA);
    SoftSerial.write(0xFA);
    SoftSerial.write(0xE1);

    if (SoftSerial.available())              
    {
        while(SoftSerial.available())          
        {
            buffer[count++]=SoftSerial.read();     
            if(count == 64)break;
        }
        for (int i=0; i<count; i++) {
            Serial.print(buffer[i],HEX);            
        }
        clearBufferArray();             
        count = 0;                      
    }
    if (Serial.available())          
    SoftSerial.write(Serial.read());      
    Serial.println("...");
}
void clearBufferArray()              
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                  
}
