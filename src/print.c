#include "vga.h"
#include "print.h"

void kprint(char *str) {
    uint32_t size = 0;
    uint16_t pos = get_raw_cursor_pos();
    for (int i = 0; str[i] != '\0'; i++) {
        termbuffer[i+pos] = (vga_entry_t){.chr=str[i], .bg = VGA_COLOR_BLACK, .fg = VGA_COLOR_WHITE};
        size++;
    }
    set_raw_cursor_pos(pos+size);
    
    return;
}

void kputc(char c) {
    uint16_t pos = get_raw_cursor_pos();
    termbuffer[pos].chr = c;
    termbuffer[pos].fg = VGA_COLOR_WHITE;
    termbuffer[pos].bg = VGA_COLOR_BLACK;
    set_raw_cursor_pos(pos+1);
}