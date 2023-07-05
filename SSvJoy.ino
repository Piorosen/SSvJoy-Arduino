#include <Joystick.h>

Joystick_ Joystick;

void setup() {
  Serial.begin(19200);
	Joystick.begin();
}

void loop() {
  if (Serial.available() > 0) { 
    auto key = Serial.read();
    if (key == 'A') { 
      Joystick.setButton(0, 1);
    }else if (key == 'B') { 
      Joystick.setButton(0, 0);
    }
    Serial.write("data : ");
    Serial.write(key);
  }
  
	// // Read pin values
	// int currentButtonState = !digitalRead(pinToButtonMap);
	// if (currentButtonState != lastButtonState)
	// {
	// Joystick.setButton(0, currentButtonState);
	// lastButtonState = currentButtonState;
	// }

	delay(50);
}