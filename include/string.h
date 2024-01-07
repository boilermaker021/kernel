#ifndef STRING_H
#define STRING_H

#define UPPER_CASE 1
#define LOWER_CASE 0

#include <stdint.h>

uint32_t strlen(char *str);
char bytetochar(uint8_t byte, uint8_t c);
char *utoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base);
int itoa(uint32_t integer, char *outbuf, uint8_t len, uint8_t base);
void itohexstr(unsigned int hex, char *outbuf);
void ctohexstr(unsigned char hex, char *outbuf);
void stohexstr(unsigned int hex, char *outbuf);


#endif