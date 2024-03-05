#ifndef KMEM_H
#define KMEM_H

#include <stdint.h>
#include "multiboot.h"

extern char *kernel_start;
extern char *kernel_end;
extern char *heap_start;
extern char *heap_end;
extern uint32_t heap_size;

void initialize_memory_map(char *kernel_start, char *kernel_end, multiboot_info_t *mmap);
uint8_t *get_heap(uint32_t size);
uint8_t *get_stk(uint32_t size);


typedef struct mem_block {
    struct flags {
        uint32_t len: 30;
        uint8_t allocated: 1;
    } flags;
    struct data {
        struct mem_block *prev;
        struct mem_block *next;
    } data;

} mem_block_t;

extern mem_block_t *free_list[64];



#endif