#include "gdt.h"
#include "intutils.h"

gdt_ptr_t gdt_ptr;
gdt_entry_t gdt_entries[5] = { 0 }; // Null Segment, Kernel Code, Kernel Data, User Data, User Code

void init_gdt() {
    gdt_ptr.base = &gdt_entries;
    gdt_ptr.limit = sizeof(gdt_entries) - 1;

    //setup NULL segment
    gdt_entries[0] = (gdt_entry_t){
        .base_low = 0,
        .base_middle = 0,
        .base_high = 0,
        .limit = 0,
        .access = 0,
        .limit_mid = 0x0,
        .flags = 0
    };

    //setup Kernel Code
    gdt_entries[1] = (gdt_entry_t){
        .base_low = 0,
        .base_middle = 0,
        .base_high = 0,
        .limit = 0xFFFF,
        .access = PRESENT | RING_0 | EXECUTABLE | RW,
        .limit_mid = 0x0F,
        .flags = BITS_32 | PAGE_GRANULARITY
    };

    //setup Kernel Data
    gdt_entries[2] = (gdt_entry_t){
        .base_low = 0,
        .base_middle = 0,
        .base_high = 0,
        .limit = 0xFFFF,
        .access = PRESENT | RING_0 | DATA | RW,
        .limit_mid = 0x0F,
        .flags = BITS_32 | PAGE_GRANULARITY
    };

    //setup User Code
    gdt_entries[3] = (gdt_entry_t){
        .base_low = 0,
        .base_middle = 0,
        .base_high = 0,
        .limit = 0xFFFF,
        .access = PRESENT | RING_3 | DATA | RW,
        .limit_mid = 0xF,
        .flags = BITS_32 | PAGE_GRANULARITY
    };

    //setup User Data
    gdt_entries[4] = (gdt_entry_t){
        .base_low = 0,
        .base_middle = 0,
        .base_high = 0,
        .limit = 0xFFFF,
        .access = PRESENT | RING_3 | DATA | RW,
        .limit_mid = 0x0F,
        .flags = BITS_32 | PAGE_GRANULARITY
    };
    
    gdt_setup(&gdt_ptr);
    return;
}