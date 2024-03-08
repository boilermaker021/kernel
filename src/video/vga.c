#include "vga.h"
#include "port.h"


volatile vga_entry_t *termbuffer = (vga_entry_t *)VGA_MEM_START;
volatile uint8_t term_fg = VGA_COLOR_WHITE;
volatile uint8_t term_bg = VGA_COLOR_BLACK;

void clear_screen() {
  for (unsigned i = 0; i < VGA_HEIGHT * VGA_WIDTH; i++) {
    termbuffer[i].chr = ' ';
    termbuffer[i].bg = term_bg;
    termbuffer[i].fg = term_fg;
  }
  set_cursor_coord(0,0);
}

unsigned int get_cursor_pos() {
  outb(0x3d4, 14);
  unsigned int position = inb(0x3d5);
  position = position << 8;

  outb(0x3d4, 15);
  position += inb(0x3d5);
  return position;
}


void set_cursor_coord(unsigned int col, unsigned int row) {
  uint16_t new_cursor_pos = col + (row * VGA_WIDTH);
  outb(0x3d4, 15);
  outb(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
  outb(0x3d4, 14);
  outb(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}

void set_cursor_pos(uint16_t position) {outb(0x3d4, 15);
  outb(0x3d5, (uint8_t)(position & 0xFF));
  outb(0x3d4, 14);
  outb(0x3d5, (uint8_t)((position >> 8) & 0xFF));
}

void increment_cursor() {
  uint16_t pos = get_cursor_pos();
  outb(0x3d4, 15);
  outb(0x3d5, (uint8_t)(pos & 0xFF));
  outb(0x3d4, 14);
  outb(0x3d5, (uint8_t)((pos >> 8) & 0xFF));
}

void scroll() {
  for(unsigned int i = 0; i < (VGA_WIDTH) * (VGA_HEIGHT - 1); i++) {
    termbuffer[i] = termbuffer[i+VGA_WIDTH];
  }
  for(unsigned int i = 0; i < VGA_WIDTH; i++) {
    termbuffer[VGA_WIDTH*(VGA_HEIGHT-1)+i] = (vga_entry_t){0};
  }
}