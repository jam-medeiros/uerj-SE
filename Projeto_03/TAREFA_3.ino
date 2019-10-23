/* 
 TAREFA 3
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Largura da tela OLED, em pixels
#define SCREEN_HEIGHT 32 // ALTURA da tela OLED, em pixels


// Declaração para monitor SSD1306 conectado ao I2C (pinos SDA, SCL)
#define OLED_RESET     4 // Reset pin # 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int CH0;
int tempPin = 0;

void setup() 
{
  Serial.begin(9600);

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { // Endereço 0x3C para 128x32
    Serial.println(F("SSD1306 ERRO DE ALOCAÇÃO"));
    for(;;); //LOOP infinito
  }
  Serial.begin(9600);

display.clearDisplay();

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // escreve texto em brnaco
  display.setCursor(0,0);             // inicia cursor em cima a direita
  display.println("SE UERJ 2019");

  display.setTextColor(WHITE); // Draw 'inverse' text
  display.println("JAM");

  display.setTextSize(2);             // escreve 2X-texto em duas escalas
  display.setTextColor(WHITE);
  display.print("MEDEIROS");
  display.display();
  delay(2000);
  }

void loop() {
  display.clearDisplay();


  ADMUX   = 0; // usa o canal 0
  ADMUX  |= (1 << REFS0);       // usa Vcc como referencia
  ADCSRA |= (1 << ADEN);        // habilita o ADC               
  ADCSRA |= (1 << ADSC);        // inicia a conversao
  while(ADCSRA & (1 << ADSC));  // espera a conversao
  int CH0 = ADCL;               // tem que ser lido antes do ADCH
  CH0 = (ADCH << 8) + CH0;         // valor de 2 bytes

//val = analogRead(tempPin);
float mv = ( CH0/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURA = ");
Serial.print(cel);
Serial.print("C°");
Serial.println();
delay(1000);
  display.setTextSize(1);             // Normal 1:1 ECALA NORMAL DOS PIXEL`S 
  display.setTextColor(WHITE);        // TEXTO SECUNDARIO EM BRANCO
  display.setCursor(0,0);             // Start at top-left corner
  display.println("TAREFA-3 LM35");

  display.setTextColor(WHITE); // escreve texto 'inverso' 
  display.println("Conversor AD SE UERJ");

  display.setTextSize(2);             // escreve no display texto em duas escalas
  display.setTextColor(WHITE);
  display.print(cel);
  display.print(" C.");
  display.println();
  display.display();
   delay(500);
  
}
