#include <stdint.h>

#include "screen.h"
#include "port.h"
#include "../types.h"
#include "../mem.h"


void clear_screen() {
  vga_entry_t *vga = (vga_entry_t *) VGA_MEM_ADDR;
  for (unsigned i = 0; i < MAX_COLS * MAX_ROWS; i++) {
    vga[i].ch = ' ';
    vga[i].bg = BLACK;
    vga[i].fg = WHITE;
  }
  set_cursor_coord(0,0);
}

unsigned int get_cursor_pos() {
  port_byte_out(0x3d4, 14);
  unsigned int position = port_byte_in(0x3d5);
  position = position << 8;

  port_byte_out(0x3d4, 15);
  position += port_byte_in(0x3d5);
  return position;
}


void set_cursor_coord(unsigned int col, unsigned int row) {
  uint16_t new_cursor_pos = col + (row * MAX_COLS);
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}

void set_cursor_pos(uint16_t position) {
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(position & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((position >> 8) & 0xFF));
}

void increment_cursor() {
  uint16_t pos = get_cursor_pos();
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((pos >> 8) & 0xFF));
}

void scroll_row() {
  vga_entry_t *base = (vga_entry_t *)VGA_MEM_ADDR;
  for(int i = 0; i < MAX_ROWS - 1; i++) {
    memcpy(base, &base[MAX_COLS], MAX_COLS * 2);
    base += MAX_COLS;
  }
  set_cursor_coord(0, 24);
}

void kprint_char_at(char c, int row, int col) {
  uint16_t pos = 0;
  if (row == -1 && col == -1) {
    pos = get_cursor_pos();
  }
  else {
    pos = row * MAX_COLS + col;
  }

  if (pos >= MAX_COLS * MAX_ROWS) {
    scroll_row();
  }
  pos = get_cursor_pos();
  vga_entry_t *vga = (vga_entry_t *) VGA_MEM_ADDR;
  vga[pos].ch = c;
  vga[pos].fg = WHITE;
  vga[pos].bg = BLACK;
  set_cursor_pos(pos+1);
}

void kprint(char* str) {
  if(str == NULL) {
    return;
  }
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\n') {
      uint16_t pos = get_cursor_pos();
      uint16_t row = pos / MAX_COLS;
      set_cursor_coord(0, row+1);
    }
    else {
      kprint_char_at(str[i], -1, -1);
    }
  }
}