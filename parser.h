#ifndef SSVJOY_PARSER_H
#define SSVJOY_PARSER_H

#include <memory>

#include "structure.h"

void (*callback)(Type type, Data data, byte checksum, bool chk);
void (*error)();

char buffer[256] = {0, };
int buffer_idx = 0;
bool read_data = false;

bool compute_checksum(char* data, int size, byte checksum) { 
  byte check = 0;
  for (int i = 0; i < size; i++) { 
    check ^= data[i];
  }
  if (check == checksum) { 
    return true;
  }else { 
    return false;
  }
}

// STX : $
// ETX : #
//X $(TYPE)(FLOAT DATA)(CHK 1byte)#
//X CHECKSUM 1 BYTE : 
//  ALL ^ Compute 
void read_next(int value) { 
  if (buffer_idx > 200) { 
    error();
    memset(buffer, 0, sizeof(buffer));
    buffer_idx = 0;
  }
  else if (value == '$') { 
      read_data = true;
  }
  else if (value == '#') { 
    read_data = false;
    ParseResult pr = *(ParseResult*)&buffer[0];
    callback(pr.type, pr.data, pr.checksum, compute_checksum(buffer, buffer_idx, pr.checksum));
    memset(buffer, 0, sizeof(buffer));
    buffer_idx = 0;
  }
  else if (read_data) { 
    buffer[buffer_idx] = value;
    buffer_idx += 1;
  }
}

#endif
