#include <RH_ASK.h>
#include <SPI.h>

RH_ASK driver;

void setup()
{
    Serial.begin(9600); // Debugging only
    if (!driver.init())
      Serial.println("init failed");
}

void loop()
{
    int moisture;
    uint8_t len;
    if (driver.recv((uint8_t *)&moisture, &len)) // Non-blocking
    {
      // Print the data received by the transmitter
      Serial.println(moisture);         
    }
}

