#ifndef SSVJOY_PARSER_H
#define SSVJOY_PARSER_H

#include <memory>

#include "structure.h"

void (*callback)(Type type, Data data, byte checksum);

char buffer[256] = {0, };
int buffer_idx = 0;
bool read_data = false;
bool compute_checksum(char* data, int size, byte checksum) { 
  
}

// STX : $
// ETX : #
//X $(TYPE)(FLOAT DATA)(CHK 1byte)#
//X CHECKSUM 1 BYTE : 
//  ALL ^ Compute 
void read_next(int value) { 
  if (value == '$') { 
      read_data = true;
  }
  else if (value == '#') { 
    read_data = false;
    ParseResult pr = *(ParseResult*)&buffer[0];
    callback(pr.type, pr.data, pr.checksum);
    memset(buffer, 0, sizeof(buffer));
    buffer_idx = 0;
  }
  else if (read_data) { 
    buffer[buffer_idx] = value;
    buffer_idx += 1;
  }
}

#endif