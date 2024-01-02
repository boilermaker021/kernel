#include "idt.h"
#include "print.h"


idt_ptr_t idt_ptr;
idt_entry_t interrupt_array[256] = { 0 };

void setup_idt_entry(uint32_t num, uint32_t addr, uint16_t selector, uint8_t flags) {
    interrupt_array[num] = (idt_entry_t){
        .addr_low = addr & 0xFFFF,
        .addr_high = (addr >> 16) && 0xFFFF,
        .seg_select = selector,
        .zero = 0,
        .flags = flags
    };
}


void base_interrupt() {
    asm("iret");
}

void init_idt() {
    idt_ptr.size = sizeof(interrupt_array) - 1;
    idt_ptr.base = &interrupt_array;
    

    //setup array here
    //placeholder:
    for (int i = 0; i < 256; i++) {
        setup_idt_entry(i, base_interrupt, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
    }

    //lidt
    asm volatile("lidt (%%eax)\n\t"
                 : : "a"(&idt_ptr));

}