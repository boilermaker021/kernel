#ifndef IDT_H
#include <stdint.h>

#define TRAP_32 0b00001110
#define INTERRUPT_32 0b00001111
#define RING_0 0b00000000
#define RING_1 0b00100000
#define RING_2 0b01000000
#define RING_3 0b01100000
#define PRESENT 0b10000000

struct idt_entry {
  uint16_t addr_low;
  uint16_t seg_select;
  uint8_t zero;
  uint8_t flags;
  uint16_t addr_high;
} __attribute__((packed));

typedef struct idt_entry idt_entry_t;

struct idt_ptr {
  uint16_t size;
  idt_entry_t *base;
} __attribute__((packed));

typedef struct idt_ptr idt_ptr_t;

extern idt_ptr_t idt_ptr;
extern idt_entry_t interrupt_array[256];

void init_idt();
void idt_setup();
void int_handler(uint32_t int_num, uint32_t error_code);
void panic();

extern void INT_NOERR0();
extern void INT_NOERR1();
extern void INT_NOERR2();
extern void INT_NOERR3();
extern void INT_NOERR4();
extern void INT_NOERR5();
extern void INT_NOERR6();
extern void INT_NOERR7();
extern void INT_ERR8();
extern void INT_NOERR9();
extern void INT_ERR10();
extern void INT_ERR11();
extern void INT_ERR12();
extern void INT_ERR13();
extern void INT_ERR14();
extern void INT_NOERR15();
extern void INT_NOERR16();
extern void INT_NOERR17();
extern void INT_NOERR18();
extern void INT_NOERR19();
extern void INT_NOERR20();
extern void INT_NOERR21();
extern void INT_NOERR22();
extern void INT_NOERR23();
extern void INT_NOERR24();
extern void INT_NOERR25();
extern void INT_NOERR26();
extern void INT_NOERR27();
extern void INT_NOERR28();
extern void INT_NOERR29();
extern void INT_NOERR30();
extern void INT_NOERR31();
extern void INT_NOERR32();

#endif
