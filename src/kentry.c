#include <stdbool.h>

#include "clock.h"
#include "gdt.h"
#include "idt.h"
#include "irq.h"
#include "intutils.h"
#include "kmem.h"
#include "multiboot.h"
#include "print.h"
#include "string.h"
#include "vga.h"
#include "pit.h"
#include "pic.h"
#include "port.h"

extern void *_start;
extern void *endKernel;

void kentry(multiboot_info_t *mbt, unsigned int magic) {
  uint32_t mask = disable(); //make SURE interrupts are disabled even though they should already be
  init_gdt();
  init_idt(); //default IDT, to be overwritten later
  restore(mask); 

  asm("sti"); //initial enabling of interrupts
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
  char outbuf[256] = {0};
  char *out = utoa(heap_size, outbuf, 100, 10);
  kprints(out);
  kprints(" Bytes\n");
  pic_remap(32, 39);
  irq_clear_mask(0); //make sure timer is enabled
  setup_irq_handler(0, clock_handler);
  //irq_clear_mask(1); //make sure keyboard is enabled
  init_pit(CLOCK_INTERVAL_MS); //setup PIT to fire every CLOCK_INTERVAL_MS seconds



  while(1) { //do nothing but keep interrupts enabled
    asm("hlt");
  }
}
