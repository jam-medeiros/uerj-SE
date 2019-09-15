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
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int val;
int tempPin = 0;



void setup() 
{
  Serial.begin(9600);

   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 ERRO DE ALOCAÇÃO"));
    for(;;); // Don't proceed, loop forever
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

val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
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

  display.setTextColor(WHITE); // Draw 'inverse' text
  display.println("Conversor AD SE UERJ");

  display.setTextSize(2);             // Draw 2X-scale text
  display.setTextColor(WHITE);
  display.print(cel);
  display.print(" C.");
  display.println();
  display.display();
   delay(500);
  
}
