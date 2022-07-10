#include "drivers/port.h"
#include "drivers/screen.h"
#include "mem.h"
#include "util.h"

#include <stdint.h>

//likely error with scroll_row() - FIX
void main() {
    clear_screen();
    char line_str[] = "Line: ";
    uint32_t counter = 0;
    while (counter < 26) {
        kprint_str(line_str);
        char buf[34] = { 0 };
        itoa(buf, counter+1);
        kprint_str(buf);
        kprint_str("\n");

        counter++;
    }

    
    

}