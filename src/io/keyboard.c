#include "keyboard.h"
#include "port.h"

char read_keypress() {
    char val = inb(KEYBOARD_BUFFER);
    kprinth(val, sizeof(val));
}