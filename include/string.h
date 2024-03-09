#ifndef STRING_H
#define STRING_H

#define UPPER_CASE 1
#define LOWER_CASE 0

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* dest and src must NOT overlap */
void *memcpy(void *dest, void *src, size_t n);
/* dest and src must NOT overlap */
char *strcpy(char *dest, char *src);
/* dest and src must NOT overlap */
char *strncpy(char *dest, char *src, size_t n);
uint32_t strlen(char *str);
char bytetochar(uint8_t byte, bool cap);
char *utoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base);
int itoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base);

#endif
