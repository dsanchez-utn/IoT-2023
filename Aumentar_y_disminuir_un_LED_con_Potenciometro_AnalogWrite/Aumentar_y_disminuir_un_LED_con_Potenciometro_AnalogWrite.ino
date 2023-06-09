
const int potePin = 32;  //Pin del potenciometro
volatile int estadoPote;

void setup(){
  Serial.begin(115200);
  pinMode(potePin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);  
  analogWriteResolution(12);
}

void loop(){
  analogWrite(LED_BUILTIN, analogRead(potePin));

  Serial.println(estadoPote);
  delay(100);
}



//    VER RESOLUCION y entradaPin











//  analogWrite(LED_BUILTIN, map(analogRead(potePin),0 ,4095, 255, 0));
