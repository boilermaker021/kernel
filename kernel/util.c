#include "drivers/screen.h"
#include "mem.h"
#include "util.h"


//unsigned for now
void itoa(char *dest, uint32_t in) {
  char buf[12] = { 0 };
  uint8_t counter = 1;
  while (in > 0) {
    uint16_t rem = in % 10;
    buf[11 - counter] = rem + 48;
    counter++;
    in /= 10;
  }
  buf[11] = '\0';
  memcpy(dest, buf+(12-counter), 12);

}