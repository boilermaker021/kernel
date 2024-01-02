#include "idt.h"
#include "print.h"

extern void interrupt();
idt_ptr_t idt_ptr = {0};
idt_entry_t interrupt_array[256] = { 0 };

void setup_idt_entry(uint32_t num, void *addr, uint16_t selector, uint8_t flags) {
    interrupt_array[num] = (idt_entry_t){
        .addr_low = (uint32_t)addr & 0xFFFF,
        .addr_high = ((uint32_t)addr >> 16) & 0xFFFF,
        .seg_select = selector,
        .zero = 0,
        .flags = flags
    };
}


void init_idt() {
    idt_ptr.size = sizeof(interrupt_array) - 1;
    idt_ptr.base = &interrupt_array;
    

    //setup array here
    //placeholder:
    for (int i = 0; i < 256; i++) {
        setup_idt_entry(i, interrupt, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
    }

    //lidt
    idt_setup(&idt_ptr);

}

void int_handler(uint16_t int_num) {
    kprints("int num: ");
    kprinth(int_num, sizeof(uint8_t));
    kprints("\n");
}