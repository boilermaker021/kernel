#include "drivers/port.h"
#include "drivers/screen.h"
#include "mem.h"
#include "util.h"

#include <stdint.h>

void main() {
    clear_screen();
    char line_str[] = "Line: ";
    uint32_t counter = 0;
    while (counter < 429) {
        kprint(line_str);
        char buf[12] = { 0 };
        itoa(buf, counter+1);
        kprint(buf);
        kprint("\n");
        counter++;
    }
    kprint("Hex Check:\n");
    char hex[11] = { 0 };
    hexstr(hex, 0xbee2);
    kprint("0xbee2: ");
    kprint(hex);
    kprint("\n");

    kprint("0xdeadbeef: ");
    hexstr(hex, 0xdeadbeef);
    kprint(hex);
    kprint("\n");

}