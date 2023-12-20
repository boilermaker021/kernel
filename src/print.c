#include "vga.h"
#include "print.h"

void kprint(char *str) {
    return;
}

void kputc(char c) {
    uint16_t pos = get_raw_cursor_pos();
    termbuffer[pos].chr = c;
    termbuffer[pos].fg = VGA_COLOR_WHITE;
    termbuffer[pos].bg = VGA_COLOR_BLACK;
    set_raw_cursor_pos(pos+1);
}