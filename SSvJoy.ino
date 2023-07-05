#include <Joystick.h>

#include "option.h"
#include "parser.h"

Joystick_ Joystick;

void setup() {
  Serial.begin(19200);
	Joystick.begin();
  callback = [](Type type, byte id, Data data, byte checksum, bool chk) {
    switch (type) {
      case Type::Button:
        Joystick.setButton(id, data.Axis);
        break;
      case Type::AxisX:
        Joystick.setXAxis(data.Axis);
        break;
      case Type::AxisY:
        Joystick.setYAxis(data.Axis);
        break;
      case Type::AxisZ:
        Joystick.setZAxis(data.Axis);
        break;
      case Type::AxisRotX:
        Joystick.setRxAxis(data.Axis);
        break;
      case Type::AxisRotY:
        Joystick.setRyAxis(data.Axis);
        break;
      case Type::AxisRotZ:
        Joystick.setRzAxis(data.Axis);
        break;
      case Type::Rudder:
        Joystick.setRudder(data.Axis);
        break;
      case Type::Throttle:
        Joystick.setThrottle(data.Axis);
        break;
      case Type::Accelerator:
        Joystick.setAccelerator(data.Axis);
        break;
      case Type::Brake:
        Joystick.setBrake(data.Axis);
        break;
      case Type::Steering:
        Joystick.setSteering(data.Axis);
        break;
    }

    Serial.print("Type : ");
    Serial.print((int)type);
    Serial.print("\tData : ");
    Serial.print(data.Axis);
    Serial.print(" : ");
    Serial.print(data.Value);
    Serial.print("\tCheck : ");
    Serial.print(checksum);
    Serial.print(" : ");
    Serial.print(chk);
    Serial.print("\n");
  };
  error = []() { 
    Serial.print("Error !!!\n");
  };
}

void loop() {
  if (Serial.available() > 0) { 
    auto key = Serial.read();
    read_next(key);
  }
	delay(50);
}