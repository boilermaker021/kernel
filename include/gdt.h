#ifndef GDT_H
#define GDT_H

#include <stdint.h>

//access byte defines
#define PRESENT         0b10000000
#define RING_0          0
#define RING_1          0b00100000
#define RING_2          0b01000000
#define RING_3          0b01100000
#define DATA            0b00010000
#define EXECUTABLE      0b00011000
#define DATA_UP         0b00000100
#define CODE_LE_PROV    0b00000100
#define CONFORMING      0b00000100
#define RW              0b00000010
#define ACCESS          0b00000001

//flags defines
#define PAGE_GRANULARITY    0b1000
#define BITS_32             0b0100
#define LONG_MODE           0b0010 //shouldn't be used

struct gdt_entry {
    uint16_t limit;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t limit_mid: 4;
    uint8_t flags: 4;
    uint8_t base_high;
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

typedef struct gdt_ptr gdt_ptr_t;

extern gdt_ptr_t gdt_ptr;
extern gdt_entry_t gdt_entries[5];

void init_gdt();
void gdt_setup();

#define K_CODE_OFFSET 0x8
#define K_DATA_OFFSET 0x10
#define U_CODE_OFFSET 0x18
#define U_DATA_OFFSET 0x20


#endif