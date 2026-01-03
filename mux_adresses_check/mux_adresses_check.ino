/*
  Author: @SofiaLam 
  Hardware: This program runs on the Arduino and checks which I2C addresses are detected
  on each channel of the TCA9548A multiplexer.

  The multiplexer itself should always respond at address 0x70. (unless you connect A0,A1,A2 to another adress)
  Any channel that has an AS5600 encoder connected should also detect the device at 0x36.

  This is a simple test to verify that the master (Arduino) communicates correctly
  with slave devices over the I2C bus through the multiplexer.

*/
#include <Wire.h>

#define MUX_ADDR 0x70  // TCA9548A

void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(MUX_ADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
  Serial.println("Scanning all TCA9548A channels...");
  for (uint8_t ch = 0; ch < 8; ch++) {
    tcaselect(ch);
    Serial.print("Channel ");
    Serial.println(ch);

    for (uint8_t addr = 1; addr < 127; addr++) {
      Wire.beginTransmission(addr);
      uint8_t error = Wire.endTransmission();

      if (error == 0) {
        Serial.print("  Found device at 0x");
        Serial.println(addr, HEX);
      }
    }
  }

  Serial.println("----");
  delay(5000);
}
