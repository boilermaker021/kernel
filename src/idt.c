#include "idt.h"
#include "gdt.h"

extern void interrupt();
idt_ptr_t idt_ptr = {0};
idt_entry_t interrupt_array[256] = {0};

void setup_idt_entry(uint32_t num, void *addr, uint16_t selector,
                     uint8_t flags) {
  interrupt_array[num] =
      (idt_entry_t){.addr_low = (uint32_t)addr & 0xFFFF,
                    .addr_high = ((uint32_t)addr >> 16) & 0xFFFF,
                    .seg_select = selector,
                    .zero = 0,
                    .flags = flags};
}

void init_idt() {
  idt_ptr.size = sizeof(interrupt_array) - 1;
  idt_ptr.base = &interrupt_array;

  // setup array here
  // placeholder:
  /*for (int i = 0; i < 256; i++) {
      setup_idt_entry(i, interrupt, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  }*/
  setup_idt_entry(0, INT_NOERR0, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(1, INT_NOERR1, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(2, INT_NOERR2, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(3, INT_NOERR3, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(4, INT_NOERR4, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(5, INT_NOERR5, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(6, INT_NOERR6, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(7, INT_NOERR7, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(8, INT_ERR8, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(9, INT_NOERR9, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(10, INT_ERR10, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(11, INT_ERR11, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(12, INT_ERR12, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(13, INT_ERR13, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(14, INT_ERR14, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(15, INT_NOERR15, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(16, INT_NOERR16, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(17, INT_NOERR17, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(18, INT_NOERR18, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(19, INT_NOERR19, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(20, INT_NOERR20, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(21, INT_NOERR21, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(22, INT_NOERR22, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(23, INT_NOERR23, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(24, INT_NOERR24, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(25, INT_NOERR25, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(26, INT_NOERR26, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(27, INT_NOERR27, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(28, INT_NOERR28, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(29, INT_NOERR29, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(30, INT_NOERR30, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(31, INT_NOERR31, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);
  setup_idt_entry(32, INT_NOERR32, K_CODE_OFFSET, TRAP_32 | PRESENT | RING_0);

  // lidt
  idt_setup(&idt_ptr);
}

void int_handler(uint32_t int_num, uint32_t error_code) {
  kprints("int num: ");
  kprinth(int_num, sizeof(uint32_t));
  kprints("\n");
}
