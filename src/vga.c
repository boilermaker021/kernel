#include "vga.h"
#include "port.h"


volatile vga_entry_t *termbuffer = (vga_entry_t *)VGA_MEM_START;
volatile uint8_t term_fg = VGA_COLOR_WHITE;
volatile uint8_t term_bg = VGA_COLOR_BLACK;

void set_cursor_pos(uint8_t x, uint8_t y) {
    uint16_t pos = (y * VGA_WIDTH) + x;
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

uint16_t get_raw_cursor_pos() {
    outb(0x3D4, 0x0E);
    volatile uint16_t pos = inb(0x3D5);
    pos << 8;
    outb(0x3D4, 0x0F);
    pos += ((uint16_t)inb(0x3D5));
    return pos;
}

void set_raw_cursor_pos(uint16_t pos) {
    outb(0x3d4, 0x0f);
    outb(0x3d5, (uint8_t) (pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}