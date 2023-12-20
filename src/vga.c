#include "vga.h"
#include "port.h"

void set_cursor_pos(uint8_t x, uint8_t y) {
    uint16_t pos = (y * VGA_WIDTH) + x;
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

uint16_t get_raw_cursor_pos() {
    uint16_t pos = 0;
    outb(0x3D4, 0x0F);
    pos |= inb(0x3D5);
    outb(0x3D4, 0x0E);
    pos |= ((uint16_t)inb(0x3D5)) << 8;
    return pos;
}

void set_raw_cursor_pos(uint16_t pos) {
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}