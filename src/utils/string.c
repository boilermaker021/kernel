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

/* dest and src must NOT overlap */
char *strcpy(char *dest, char *src) {
  char *d = dest;
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  return d;
}

/* dest and src must NOT overlap */
char *strncpy(char *dest, char *src, size_t n) {
  for (size_t i = 0; (i < n) && (src[i] != '\0'); i++) {
    dest[i] = src[i];
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

char bytetochar(uint8_t byte, bool cap) {
  if (byte <= 9) {
    return '0' + byte;
  } else {
    return (cap ? 'A' : 'a') + byte - 10;
  }
}

char *utoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base) {
  int i = 0;
  while (integer > 0) {
    outbuf[(len - 2) - i] = bytetochar(integer % base, UPPER_CASE); // replace
    i++;
    integer /= base;
  }
  return outbuf + len - i;
}

/* TODO: NOT IMPLEMENTED */
int itoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base) {
  bool negative = integer < 0;
}
