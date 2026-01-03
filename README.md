Hardware: This program runs on the Arduino and checks which I2C addresses are detected
  on each channel of the TCA9548A multiplexer.

  The multiplexer itself should always respond at address 0x70. (unless you connect A0,A1,A2 to another adress)
  Any channel that has an AS5600 encoder connected should also detect the device at 0x36.

  This is a simple test to verify that the master (Arduino) communicates correctly
  with slave devices over the I2C bus through the multiplexer.
