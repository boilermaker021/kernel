#ifndef INTERRUPTS_H
#define INTERRUPTS_H
#include <stdint.h>

uint32_t disable();
void  restore(uint32_t eflags);

#endif