#include "vga.h"
#include "print.h"

void kprint(char *str) {
    uint16_t pos = get_raw_cursor_pos();
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            pos = ((pos / VGA_WIDTH) + 1) * VGA_WIDTH;
        } else {
            termbuffer[pos] = (vga_entry_t){.chr=str[i], .bg = term_bg, .fg = term_fg};
            pos++;
        }
    }
    set_raw_cursor_pos(pos);
    
    return;
}

void kputc(char c) {
    uint16_t pos = get_raw_cursor_pos();
    termbuffer[pos].chr = c;
    termbuffer[pos].fg = term_fg;
    termbuffer[pos].bg = term_fg;
    set_raw_cursor_pos(pos+1);
}