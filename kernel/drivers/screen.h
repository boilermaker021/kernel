#ifndef SCREEN_H
#define SCREEN_H

#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f

#define VGA_MEM 0xb8000


void clear_screen();

void set_cursor_pos(unsigned int col, unsigned int row);

unsigned int get_cursor_position();


#endif