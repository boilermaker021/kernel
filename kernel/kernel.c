#include "drivers/port.h"
#include "drivers/screen.h"

#include <stdint.h>

void print_str(char *str) {
    port_byte_out(0x3d4, 14);
    int position = port_byte_in(0x3d5);
    position = position << 8; /* high byte */

    port_byte_out(0x3d4, 15); /* requesting low byte */
    position += port_byte_in(0x3d5);
    int offset_from_vga = position * 2;



    char *vga = (char *) 0xb8000;

    unsigned int index = 0;

    while (str[index] != 0) {
        vga[offset_from_vga + index * 2] = str[index];
        vga[offset_from_vga + 1 + (index * 2)] = 0x0f;
        index++;
    }

    uint16_t new_cursor_pos = position + index;
    port_byte_out(0x3d4, 15);
    port_byte_out(0x3d5, (uint8_t)(new_cursor_pos & 0xFF));
    port_byte_out(0x3d4, 14);
    port_byte_out(0x3d5, (uint8_t)((new_cursor_pos >> 8) & 0xFF));
}

void main() {
    clear_screen();
    print_str("TEST STRING TEST STRING TEST STRING TEST STRING TEST STRING!");
}