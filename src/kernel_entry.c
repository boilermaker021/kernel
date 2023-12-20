#include "vga.h"
#include "string.h"
#include "print.h"

void kernel_main(void) {
  struct vga_entry *term_buffer = (struct vga_entry *)VGA_MEM_START;
  vga_entry_t *buffer = (vga_entry_t *)VGA_MEM_START;

  char buf[64] = "This is a test string";

  kputc('a');
  kputc('b');
  kputc('c');
  kputc('d');
  
}
