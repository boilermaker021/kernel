#ifndef IDT_H
#include <stdint.h>
#include "gdt.h"

#define TRAP_32         0b00001110
#define INTERRUPT_32    0b00001111
#define RING_0          0
#define RING_1          0b00100000
#define RING_2          0b01000000
#define RING_3          0b01100000
#define PRESENT         0b10000000



struct idt_entry {
    uint16_t addr_low;
    uint16_t seg_select;
    uint8_t zero;
    uint8_t flags;
    uint16_t addr_high;
}__attribute__((packed));

typedef struct idt_entry idt_entry_t;

struct idt_ptr {
    uint16_t size;
    idt_entry_t *base;
}__attribute__((packed));


typedef struct idt_ptr idt_ptr_t;




#endif