#ifndef STRING_H
#define STRING_H

#include <stdint.h>

uint32_t strlen(char *str);
int utoa(unsigned int integer, char *outbuf, unsigned int len);
int itoa(int integer, char *outbuf, unsigned int len);
void itohexstr(unsigned int hex, char *outbuf);
void ctohexstr(unsigned char hex, char *outbuf);
void stohexstr(unsigned int hex, char *outbuf);


#endif