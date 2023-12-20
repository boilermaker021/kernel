#ifndef PORT_H
#define PORT_H
#include <stdint.h>


void outb(uint16_t port, uint8_t byte);
uint8_t inb(uint8_t port);

#endif