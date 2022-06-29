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

unsigned int get_cursor_position() {
  port_byte_out(0x3d4, 14);
  unsigned int position = port_byte_in(0x3d5);
  position = position << 8; /* high byte */

  port_byte_out(0x3d4, 15); /* requesting low byte */
  position += port_byte_in(0x3d5);
  return position;
}


void set_cursor_pos(unsigned int col, unsigned int row) {
  uint16_t new_cursor_pos = col + (row * MAX_COLS);
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}

void increment_cursor() {
  uint16_t pos = get_cursor_position();
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((pos >> 8) & 0xFF));
}

void newline() {
  uint16_t pos = get_cursor_position();
  unsigned short line_number = pos / MAX_COLS;
  set_cursor_pos(0, line_number+1);
}