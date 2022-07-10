#include "mem.h"

//does not work if dest and base overlap
void memcpy(void *dest, void *src, uint32_t size) {
  for (int i = 0; i < size; i++) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
}