#include <EEPROM.h>
int ledPin = 13;
int relay1 = 5;
int relay2 = 6;
int relay3 = 7;
int flagAddress = 0;
bool isGateOpen = true;

void setup() {
  // Read the value stored in EEPROM at the specified address
    if (EEPROM.read(flagAddress) != 1) {
    EEPROM.write(flagAddress, 1);
    isGateOpen = true;
  } else {
    isGateOpen = false;
  }

  // Set the pin mode to OUTPUT
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(ledPin, LOW);
  
  
  // If it's the first time, store the flag in EEPROM to indicate that it's not the first time anymore
  if (isGateOpen) {
    EEPROM.write(flagAddress, 1);
  } else {
    EEPROM.write(flagAddress, 0); // Toggle the flag for the next power-up
  }
}

void loop() {
  if(isGateOpen)
  {
  digitalWrite(ledPin, HIGH);
  delay(50);
  digitalWrite(relay1, LOW);
  delay(30000);
  digitalWrite(relay1, HIGH);
  delay(1000);
  digitalWrite(relay2, LOW);
  delay(165000);
  digitalWrite(relay2,HIGH);
  delay(100000000000000000);
  }
  else
  {
  digitalWrite(ledPin, LOW);
  delay(50);
  digitalWrite(relay1, LOW);
  delay(165000);
  digitalWrite(relay1, HIGH);
  delay(1000);
  digitalWrite(relay3, LOW);
  delay(30000);
  digitalWrite(relay3,HIGH);
  delay(100000000000000000);
  }
}
