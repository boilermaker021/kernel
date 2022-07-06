#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f

#define VGA_MEM_ADDR 0xb8000

typedef struct vga_entry {
  uint8_t ch :8;
  uint8_t fg :4,
          bg :4;
} vga_entry_t;

void clear_screen();

void set_cursor_pos(unsigned int col, unsigned int row);

unsigned int get_cursor_pos();


#endif