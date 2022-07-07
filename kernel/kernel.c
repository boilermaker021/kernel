#include "drivers/port.h"
#include "drivers/screen.h"

#include <stdint.h>


void main() {
    clear_screen();
    kprint_str("this is a test");

}