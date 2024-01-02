#include "intutils.h"

uint32_t disable() {
    uint32_t eflags;
    asm volatile("pushfl\n\t"
                 "popl %%eax\n\t"
                 "cli\n\t"
                 :"=a"(eflags));
    return eflags;
}

void restore(uint32_t eflags) {
    asm volatile("pushl %0\n\t"
                 "popfl\n\t"
                :
                : "rm"(eflags));
}