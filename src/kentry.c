#include <stdbool.h>

#include "vga.h"
#include "string.h"
#include "print.h"
#include "multiboot.h"
#include "kmem.h"
#include "gdt.h"
#include "idt.h"

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

  
    bool valid_memory_map = true;
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        valid_memory_map = false;
    }
    if (!(mbt->flags >> 6 & 0x1)) { 
        valid_memory_map = false;
    }

    if (valid_memory_map) {
        term_fg = VGA_COLOR_RED;
        kprints("Valid memory map found!\n");
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

}
