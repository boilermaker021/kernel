#include "drivers/port.h"
#include "drivers/screen.h"

#include <stdint.h>


void main() {
    clear_screen();
    print_char_at('c',3,4);
    print_char_at('a', -1, -1);

}