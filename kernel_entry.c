#include "include/vga.h"

void kernel_main(void) {
  struct vga_entry *term_buffer = (struct vga_entry *)VGA_MEM_START;
  term_buffer[0].chr = 'H';
  term_buffer[0].fg = VGA_COLOR_WHITE;
  term_buffer[0].bg = VGA_COLOR_BLACK;
}
