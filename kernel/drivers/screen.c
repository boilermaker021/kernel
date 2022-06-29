#include <stdint.h>

#include "screen.h"
#include "port.h"

//void set_cursor_pos(unsigned int col, unsigned int row);



void clear_screen() {
  char *vga = (char *) 0xb8000;
  for (unsigned i = 0; i < MAX_COLS * MAX_ROWS*2; i+=2) {
    vga[i] = ' ';
    vga[i+1] = 0x0f;

  }
  set_cursor_pos(0,0);
}


void set_cursor_pos(unsigned int col, unsigned int row) {
  uint16_t new_cursor_pos = col + (row * MAX_COLS);
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}