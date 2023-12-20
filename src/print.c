#include "vga.h"
#include "print.h"

void kprint(char *str) {
    uint16_t pos = get_cursor_pos();
    for (int i = 0; str[i] != '\0'; i++) {
        if (pos > VGA_WIDTH * VGA_HEIGHT - 1) {
            scroll();
            pos = (VGA_WIDTH * (VGA_HEIGHT - 1)) + 1;
        }
        if (str[i] == '\n') {
            pos = ((pos / VGA_WIDTH) + 1) * VGA_WIDTH;
        } else {
            termbuffer[pos] = (vga_entry_t){.chr=str[i], .bg = term_bg, .fg = term_fg};
            pos++;
        }
    }
    if (pos > VGA_WIDTH * VGA_HEIGHT - 2 ) {
        scroll();
        pos = (VGA_WIDTH * (VGA_HEIGHT - 1));
    }
    set_cursor_pos(pos);
    
    return;
}

void kputc(char c) {
    uint16_t pos = get_cursor_pos();
    termbuffer[pos].chr = c;
    termbuffer[pos].fg = term_fg;
    termbuffer[pos].bg = term_fg;
    set_cursor_pos(pos+1);
}