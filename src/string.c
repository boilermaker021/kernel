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

int utoa(unsigned int integer, char *outbuf, unsigned int len) {
    
}

int itoa(int integer, char *outbuf, unsigned int len) {

}

void itohexstr(unsigned int hex, char *outbuf) {
    char *buf = &hex;
    for(int i = 0; i < 4; i++) {
        ctohexstr(buf[3-i], outbuf + i*2);
    }
}

void stohexstr(unsigned int hex, char *outbuf) {
    char *buf = &hex;
    for(int i = 0; i < 2; i++) {
        ctohexstr(buf[1-i], outbuf + i*2);
    }
}


void ctohexstr(unsigned char hex, char *outbuf) {
    unsigned char upper_half = hex >> 4;
    unsigned char lower_half = hex & 0x0F;
    if (upper_half <= 9) {
        outbuf[0] = upper_half + '0';
    } else {
        outbuf[0] = upper_half + 'A' - 0x0a;
    }
    if (lower_half <= 9) {
        outbuf[1] = lower_half + '0';
    } else {
        outbuf[1] = lower_half + 'A' - 0x0a;
    }
}