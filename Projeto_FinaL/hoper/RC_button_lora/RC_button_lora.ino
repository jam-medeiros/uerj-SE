#include <SoftwareSerial.h>

#define LED1  13  

SoftwareSerial loraSerial(11, 10); // TX, RX

void setup() {
  pinMode(LED1, OUTPUT);
  Serial.begin(9600);
  loraSerial.begin(9600);  
}

void loop() { 
  if(loraSerial.available() > 1){
    String input = loraSerial.readString();
    Serial.println(input);  
    if(input == "on") {
      digitalWrite(LED1, HIGH);  
    } 
    if(input == "off") {
      digitalWrite(LED1, LOW);
    }
  }
  delay(20);
}
