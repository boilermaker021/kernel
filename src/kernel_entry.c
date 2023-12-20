#include "vga.h"
#include "string.h"
#include "print.h"

void kernel_main(void) {
  struct vga_entry *term_buffer = (struct vga_entry *)VGA_MEM_START;
  vga_entry_t *buffer = (vga_entry_t *)VGA_MEM_START;

  char buf[512] = "This is a test string1 This is a test string2 This is a test string3 This is a test string4";
  kprint(buf);
  
}
