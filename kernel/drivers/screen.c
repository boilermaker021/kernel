#include <stdint.h>

#include "drivers/screen.h"
#include "drivers/port.h"

void set_cursor_pos(unsigned int col, unsigned int row) {
  uint16_t new_cursor_pos = col + (row * MAX_COLS);
  port_byte_out(0x3d4, 15);
  port_byte_out(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
  port_byte_out(0x3d4, 14);
  port_byte_out(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}