
// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

void setup() {

  Serial.begin(115200);
  delay(1000);
  Serial.println("Sensor Touch");
}

void loop() {
  Serial.println(touchRead(13));  // toma valor del Touch 4 pin = GPIO13
  delay(1000);
}