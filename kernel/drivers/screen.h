#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

#define MAX_ROWS 25
#define MAX_COLS 80

#define BLACK        0x0
#define BLUE         0x1
#define GREEN        0x2
#define CYAN         0x3
#define RED          0x4
#define PURPLE       0x5
#define BROWN        0x6
#define GRAY         0x7
#define DARY_GRAY    0x8
#define LIGHT_BLUE   0x9
#define LIGHT_GREEN  0x9
#define LIGHT_CYAN   0xa
#define LIGHT_RED    0xb
#define LIGHT_PURPLE 0xc
#define YELLOW       0xd
#define WHITE        0xf

#define VGA_MEM_ADDR 0xb8000

typedef struct vga_entry {
  uint8_t ch :8;
  uint8_t fg :4,
          bg :4;
} vga_entry_t;

void clear_screen();

void set_cursor_pos(uint16_t position);

void set_cursor_coord(unsigned int row, unsigned int col);

unsigned int get_cursor_pos();

void kprint_char_at(char character, int row, int col);

void kprint(char* str);


#endif