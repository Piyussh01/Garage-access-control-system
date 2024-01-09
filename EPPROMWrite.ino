#include <EEPROM.h>

int ledPin = 13;
int flagAddress = 0;
bool isFirstTime = true;

void setup() {
  // Read the value stored in EEPROM at the specified address
  byte storedFlag = EEPROM.read(flagAddress);
  
  // If the stored value is not equal to 1, it means the board has been turned on before
  isFirstTime = (storedFlag != 1);

  // Set the pin mode to OUTPUT
  pinMode(ledPin, OUTPUT);
  
  // If it's the first time, set the pin HIGH; otherwise, set the pin LOW
  digitalWrite(ledPin, isFirstTime ? HIGH : LOW);
  
  // If it's the first time, store the flag in EEPROM to indicate that it's not the first time anymore
  if (isFirstTime) {
    EEPROM.write(flagAddress, 1);
  } else {
    EEPROM.write(flagAddress, 0); // Toggle the flag for the next power-up
  }
}

void loop() {
  // Your main code goes here
}
