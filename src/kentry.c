#include <stdbool.h>

#include "vga.h"
#include "string.h"
#include "print.h"
#include "multiboot.h"

void kentry(multiboot_info_t *mbd, unsigned int magic) {
  bool valid_memory_map = true;
  if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
    valid_memory_map = false;
  }
  if (!(mbd->flags >> 6 & 0x1)) {
    valid_memory_map = false;
  }

  for (unsigned int i = 0; i < 24; i++) {
    kprint("0x");
    char outbuf[5] = {0};
    itohexstr(i, outbuf);
    kprint(outbuf);
    kprint("\n");
  }

  kprint("nanananana\n");
  kprint("n");
  
  
  
  


  
}
