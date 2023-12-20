#include "port.h"

void outb(uint16_t port, uint8_t byte) {
    asm volatile("outb %0, %1\n\t"
        : 
        :"a" (byte), "Nd"(port)
        );
}

uint8_t inb(uint8_t port) {
    uint8_t out;
    asm("inb %%dx, %%al"
        :"=a"(out) 
        :"d"(port)
        );
    return out;
}