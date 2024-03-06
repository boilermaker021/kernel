#include <stdbool.h>

#include "gdt.h"
#include "idt.h"
#include "intutils.h"
#include "kmem.h"
#include "multiboot.h"
#include "print.h"
#include "string.h"
#include "vga.h"

extern void *_start;
extern void *endKernel;

void kentry(multiboot_info_t *mbt, unsigned int magic) {
  uint32_t mask = disable();
  init_gdt();
  init_idt();
  restore(mask);

  kprints("Kernel Memory Location:\nStart:");
  kprinth(&_start, sizeof(void *));
  kprints("\nEnd: ");
  kprinth(&endKernel, sizeof(void *));
  kprints("\n");

  kprints("GDT table at address: ");
  kprinth(&gdt_entries, sizeof(uint32_t));
  kprints("\nIDT table at address: ");
  kprinth(&interrupt_array, sizeof(uint32_t));

  bool valid_memory_map = true;
  if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
    valid_memory_map = false;
  }
  if (!(mbt->flags >> 6 & 0x1)) {
    valid_memory_map = false;
  }

  if (valid_memory_map) {
    term_fg = VGA_COLOR_RED;
    kprints("\nValid memory map found!\n");
    term_fg = VGA_COLOR_WHITE;
    initialize_memory_map(&_start, &endKernel, mbt);
    kprints("Heap Start: ");
    kprinth(heap_start, sizeof(char *));
    kprints("\nHeap End: ");
    kprinth(heap_end, sizeof(char *));
    kprints("\n");

  } else {
    term_fg = VGA_COLOR_RED;
    kprints("Bad memory map, panicing...\n");
    return;
  }

  asm("int $0x1a");

  kprints("\nHeap start:\n");
  kprinth(heap_start, sizeof(heap_start));
  kprints("\nHeap Size:\n");
  out = utoa(heap_size, outbuf, 100, 10);
  kprints(out);
  kprints(" Bytes\n");
}
