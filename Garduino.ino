#include <dht.h>

dht DHT;

#define DHT11_PIN A2

const int tempSensorPin = A0;
const int lightSensorPin = A1;
const int moistureSensorPin = A3;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int tempSensorVal = analogRead(tempSensorPin);
  float volts = (tempSensorVal / 1024.0) * 5;
  float temp = (volts - .5) * 100;

  int lightSensorVal = analogRead(lightSensorPin);

  int moistureSensorVal = analogRead(moistureSensorPin);

  int humidity = 0;

  int chk = DHT.read11(DHT11_PIN);
  switch (chk)
  {
    case DHTLIB_OK:
      humidity = DHT.humidity;  
      break;
    case DHTLIB_ERROR_CHECKSUM:
      // Serial.print("Checksum error,\t");
      break;
    case DHTLIB_ERROR_TIMEOUT:
      // Serial.print("Time out error,\t");
      break;
    case DHTLIB_ERROR_CONNECT:
      // Serial.print("Connect error,\t");
      break;
    case DHTLIB_ERROR_ACK_L:
      // Serial.print("Ack Low error,\t");
      break;
    case DHTLIB_ERROR_ACK_H:
      // Serial.print("Ack High error,\t");
      break;
    default:
      // Serial.print("Unknown error,\t");
      break;
  }

  Serial.print("temp:");
  Serial.print(temp);
  Serial.print(",");

  Serial.print("light:");
  Serial.print(lightSensorVal);
  Serial.print(",");

  Serial.print("humidity:");
  Serial.print(humidity);
  Serial.print(",");

  Serial.print("moisture");
  Serial.println(moistureSensorVal);

  delay(2000);

}
