#include <Wire.h>

void setup() {
  // join i2c bus (address optional for master)
  Wire.begin(0, 2);

  // start serial for output
  Serial.begin(9600);
}

void loop() {
  // request 6 bytes from slave device #8
  Wire.requestFrom(0xDD, 6);

  // slave may send less than requested
  while (Wire.available())
  {
    // receive a byte as character
    char c = Wire.read();

    // print the character
    Serial.printf("Received: %02X\n", c);
  }

  delay(500);
}
