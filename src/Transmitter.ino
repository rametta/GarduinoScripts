#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

const int MOISTURE_PIN_DATA = A0;
const int MOISTURE_PIN_POWER = 6;
const int READING_DELAY = 5000;

void setup() {
  pinMode(MOISTURE_PIN_POWER, OUTPUT);
  digitalWrite(MOISTURE_PIN_POWER, LOW);
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("driver failed");
}

int readMoisture() {
  digitalWrite(MOISTURE_PIN_POWER, HIGH);
  delay(500);
  int moisture = analogRead(MOISTURE_PIN_DATA);
  digitalWrite(MOISTURE_PIN_POWER, LOW);
  return 1023 - moisture;
}

void loop() {
  // Low reading means soil is dry
  int msg = readMoisture();
  driver.send((uint8_t *)&msg, sizeof(&msg));
  driver.waitPacketSent();
  delay(READING_DELAY);
}