#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>

#define CLOCK_INTERVAL_MS 1


void clock_handler();

extern volatile uint32_t clock_uptime;
extern volatile uint32_t clock_counter;

#endif