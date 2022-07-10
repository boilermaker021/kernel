#include "drivers/screen.h"
#include "mem.h"
#include "util.h"


//unsigned for now
void itoa(char *dest, uint32_t in) {
  char buf[34] = { 0 };
  uint8_t counter = 0;
  while (in > 0) {
    uint16_t rem = in % 10;
    buf[33 - counter] = rem + 48;
    counter++;
    in /= 10;
  }
  buf[33] = '\0';
  memcpy(dest, buf+(34-counter), 34);

}