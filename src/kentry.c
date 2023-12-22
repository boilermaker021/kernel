#include <stdbool.h>

#include "vga.h"
#include "string.h"
#include "print.h"
#include "multiboot.h"

extern void *_start;
extern void *endKernel;

void kentry(multiboot_info_t *mbt, unsigned int magic) {
  
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
    kprints("Valid memory map found!\n");
    multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mbt->mmap_addr;
    while (mmap < mbt->mmap_addr + mbt->mmap_length) {
      kprints("Entry: ");
      kprinth((uint32_t)mmap->addr, sizeof(uint32_t));
      kprints("\n");
      kprints("Type: ");
      switch(mmap->type) {
        case MULTIBOOT_MEMORY_AVAILABLE:
          kprints("Available\n");
          break;
        case MULTIBOOT_MEMORY_RESERVED:
          kprints("Reserved\n");
          break;
        case MULTIBOOT_MEMORY_ACPI_RECLAIMABLE:
          kprints("ACPI Reclaimable\n");
          break;
        case MULTIBOOT_MEMORY_NVS:
          kprints("NVS\n");
          break;
        case MULTIBOOT_MEMORY_BADRAM:
          kprints("Bad Ram\n");
          break;
      }
      kprints("Length: ");
      kprinth(mmap->len, sizeof(uint32_t));
      kprints("\n");
      mmap = (multiboot_memory_map_t *)((uint32_t) mmap + mmap->size + sizeof(mmap->size));
    }
  } else {
    kprints("-------BAD MEMORY MAP!-----");
  }
  
}
