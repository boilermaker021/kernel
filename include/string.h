#ifndef STRING_H
#define STRING_H

#include <stdint.h>

uint32_t strlen(char *str);
void uitoa(unsigned int integer, char *outbuf);
void itoa(int integer, char *outbuf);
void itohexstr(unsigned int hex, char *outbuf);
void ctohexstr(unsigned char hex, char *outbuf);


#endif