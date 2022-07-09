#include "drivers/port.h"
#include "drivers/screen.h"
#include "mem.h"

#include <stdint.h>


void main() {
    clear_screen();
    kprint_str("this is a test\nnewline\n15 as string: ");

}