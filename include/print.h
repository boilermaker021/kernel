#ifndef PRINT_H
#define PRINT_H

#include "vga.h"

void kprints(char *str);
void kprinth(uint32_t hex, uint8_t size);
void kputc(char c);


#endif