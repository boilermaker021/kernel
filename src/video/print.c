#include "print.h"
#include "string.h"
#include "vga.h"

void kprints(char *str) {
  uint16_t pos = get_cursor_pos();
  for (int i = 0; str[i] != '\0'; i++) {
    if (pos > VGA_WIDTH * VGA_HEIGHT - 1) {
      scroll();
      pos = (VGA_WIDTH * (VGA_HEIGHT - 1)) + 1;
    }
    if (str[i] == '\n') {
      pos = ((pos / VGA_WIDTH) + 1) * VGA_WIDTH;
    } else {
      termbuffer[pos] =
          (vga_entry_t){.chr = str[i], .bg = term_bg, .fg = term_fg};
      pos++;
    }
  }
  if (pos > VGA_WIDTH * VGA_HEIGHT - 2) {
    scroll();
    pos = (VGA_WIDTH * (VGA_HEIGHT - 1));
  }
  set_cursor_pos(pos);

  return;
}

void kprinth(uint32_t hex, uint8_t size) {
  char outbuf[] = "0x00000000\0";
  char *out = utoa(hex, outbuf, sizeof(outbuf) - 1, 16);
  kprints(outbuf);
}

void kputc(char c) {
  uint16_t pos = get_cursor_pos();
  termbuffer[pos].chr = c;
  termbuffer[pos].fg = term_fg;
  termbuffer[pos].bg = term_fg;
  set_cursor_pos(pos + 1);
}
