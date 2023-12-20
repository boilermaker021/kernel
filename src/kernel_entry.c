#include "vga.h"
#include "string.h"
#include "print.h"

void kernel_main(void) {
  for(int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
    termbuffer[i] = (vga_entry_t){.chr = 0x00, .bg = term_bg, .fg = term_fg};
  }

  char buf[512] = "This is a test string\nThis is a second test string";
  kprint(buf);
  //kprint(buf);
  
}
