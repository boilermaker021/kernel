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

//convert value to hexadecimal string and assign to dest
void hexstr(char *dest, uint32_t in) {
  char buf[11] = { 0 };
  buf[0] = '0';
  buf[1] = 'x';
  uint8_t counter = 1;
  while (in > 0) {
    uint8_t temp = ((uint8_t) in) & 0x0F;
    in = in >> 4;

    if (temp >=0 && temp <= 9) {
      temp += '0';
    }
    else {
      temp += 'a' - 0xA;
    }

    buf[10 - counter] = temp;
    counter++;
  }
  buf[10] = '\0';
  buf[10 - (counter)] = 'x';
  buf[10 - (counter + 1)] = '0';
  memcpy(dest, buf + (11 - (counter + 2)), 11);
}