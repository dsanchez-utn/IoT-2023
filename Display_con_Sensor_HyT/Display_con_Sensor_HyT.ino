#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#include "config.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire);
DHT dht(DHT_PIN, DHT11);

void dhtInit(){
  dht.begin();
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.printf("Temperatura: %d°C\tHumedad: %d%\n",
                (int)temp,
                (int)hum);
}

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
  Serial.println(F("Iniciando Sensor de humedad y temperatura..."));
  dhtInit();
  delay(4000);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.printf("Temperatura: %.1fC\nHumedad: %.1f\n",
                  dht.readTemperature(),
                  dht.readHumidity()); 
  display.display();
  delay(100);
}
