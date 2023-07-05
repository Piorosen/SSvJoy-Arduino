#include <Joystick.h>

#include "parser.h"

Joystick_ Joystick;

void setup() {
  Serial.begin(19200);
	Joystick.begin();
  callback = [](Type type, Data data) {
    Serial.print("Type : ");
    Serial.print((int)type);
    Serial.print("\tData : ");
    Serial.print(data.Axis);
    Serial.print(" : ");
    Serial.print(data.Value);
    Serial.print("\n");
  };
}

void loop() {
  if (Serial.available() > 0) { 
    auto key = Serial.read();
    read_next(key);
  }
	delay(50);
}