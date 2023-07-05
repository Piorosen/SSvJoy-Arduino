#ifndef SSVJOY_STRUCTURE_H
#define SSVJOY_STRUCTURE_H

typedef unsigned char byte;

enum class Type : byte {
  Button,
  AxisX, AxisY,
  AxisRotX, AxisRotY,
  Rudder,
  Throttle,
  Accelerator,
  Brake,
  Steering,
};

typedef union {
  int32_t Axis;
  float Value;
} Data;

#pragma pack(push, 1)
struct ParseResult { 
  Type type;
  Data data;
  byte checksum;
};
#pragma pack(pop)

#endif
