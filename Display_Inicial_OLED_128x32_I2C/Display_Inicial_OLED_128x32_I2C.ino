#include <Adafruit_SSD1306.h>
#include <splash.h>

#include "config.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire);

int contador=0;

void displayInit(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println(F("Hola Mundo!"));
  display.println(F("Datos de Compilacion:"));
  display.printf("Fecha %s\n",__DATE__);
  display.printf("Hora: %s\n",__TIME__);
  display.display();
}

void setup() {
  Serial.begin(BAUDRATE);
  delay(1000);
  Serial.println(F("Iniciando Display..."));
  displayInit();  
  Serial.println(F("Display Iniciado"));
  display.setCursor(0,0);
}

void loop() {
  display.clearDisplay();
  display.setCursor(contador*3,contador);
  contador++;
  Serial.println(millis());
  display.printf("Han pasado %d seg.\n",millis()/1000);
  display.display();
  delay(random(2000));
  if (contador > 31) contador=0;
}
