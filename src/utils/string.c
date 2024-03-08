#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "string.h"

/* dest and src must NOT overlap */
void *memcpy(void *dest, void *src, size_t n) {
  for (uint32_t i = 0; i < n; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

size_t strlen(char *str) {
  size_t size = 0;
  while (*str != '\0') {
    str++;
    size++;
  }
  return size;
}

char bytetochar(uint8_t byte, uint8_t c) {
  if (byte <= 9) {
    return '0' + byte;
  } else {
    return (c ? 'A' : 'a') + byte - 10;
  }
}

char *utoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base) {
  int i = 0;
  while (integer > 0) {
    outbuf[(len - 1) - i] = bytetochar(integer % base, UPPER_CASE); // replace
    i++;
    integer /= base;
  }
  return outbuf + len - i;
}

int itoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base) {
  bool negative = integer < 0;
}

void itohexstr(unsigned int hex, char *outbuf) {
  char *buf = &hex;
  for (int i = 0; i < 4; i++) {
    ctohexstr(buf[3 - i], outbuf + i * 2);
  }
}

void stohexstr(unsigned int hex, char *outbuf) {
  char *buf = &hex;
  for (int i = 0; i < 2; i++) {
    ctohexstr(buf[1 - i], outbuf + i * 2);
  }
}

void ctohexstr(unsigned char hex, char *outbuf) {
  unsigned char upper_half = hex >> 4;
  unsigned char lower_half = hex & 0x0F;
  if (upper_half <= 9) {
    outbuf[0] = upper_half + '0';
  } else {
    outbuf[0] = upper_half + 'A' - 0x0a;
  }
  if (lower_half <= 9) {
    outbuf[1] = lower_half + '0';
  } else {
    outbuf[1] = lower_half + 'A' - 0x0a;
  }
}
