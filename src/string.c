#include <stdint.h>
#include "string.h"

uint32_t strlen(char *str) {
    uint32_t size;
    while (*str != '\0') {
        str++;
        size++;
    }
    return size;
}