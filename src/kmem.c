#include "kmem.h"
//remove these two when done setting up the function
#include "print.h"
#include "vga.h"


char *kernel_start;
char *kernel_end;
char *heap_start;
char *heap_end;
uint32_t heap_size = 0;

void initialize_memory_map(char *kstart, char *kend, multiboot_info_t *mbt) {
    kernel_start = kstart;
    kernel_end = kend;

    multiboot_memory_map_t *mmap = (multiboot_memory_map_t *)mbt->mmap_addr;
    while (mmap < mbt->mmap_addr + mbt->mmap_length) {
        /*term_fg = VGA_COLOR_GREEN;
        kprints("Entry: ");
        kprinth((uint32_t)mmap->addr, sizeof(uint32_t));
        kprints("\n");
        term_fg = VGA_COLOR_WHITE;
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
        kprints("\n");*/
        if (mmap->type == MULTIBOOT_MEMORY_AVAILABLE && mmap->addr+mmap->len > kernel_end && (char *)mmap->addr != 0) {
            char *block_start = (char *)mmap->addr;
            uint32_t block_size = mmap->len;
            if(block_start < kernel_end) {
                block_start = kernel_end + 0x0F;
                block_size -= ((kernel_end+0x0F) - block_start);

            }
            if (block_size > heap_size) { //only uses the largest contiguous chunk of memory, not ideal
                heap_start = block_start;
                heap_size = block_size;
                heap_end = heap_start + heap_size;
            }
            
        }
        mmap = (multiboot_memory_map_t *)((uint32_t) mmap + mmap->size + sizeof(mmap->size));
    }
}
