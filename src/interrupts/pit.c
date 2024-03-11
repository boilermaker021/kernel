#include <stdint.h>

#include "pit.h"
#include "port.h"
#include "intutils.h"


void init_pit(uint32_t ms) {
    uint32_t mask = disable();

    outb(PIT_MODE, 0x36); //change later
    uint16_t val = PIT_FREQUENCY / (1000 / ms);

    outb(PIT_CH0_DATA, val & 0xFF);
    outb(PIT_CH0_DATA, (val >> 8) & 0xFF);
    restore(mask);
    return;    
}