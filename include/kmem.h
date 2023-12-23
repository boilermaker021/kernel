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


typedef struct mem_map {
    uint32_t *addr;
    uint32_t len;
    struct mem_map *next;
} mem_map_t;



#endif