#include <stdint.h>

#include "pic.h"
#include "irq.h"

void irq_clear_mask(uint8_t line) {
    uint16_t port;
    uint8_t val;

    if(line < 8) { //on Master PIC
        port = PIC1_DATA;
    } else { //on Slave PIC
        port = PIC2_DATA;
        line -= 8; //corresponding line on Slave PIC
    }

    val = inb(port) & ~(1 << line);
    outb(port, val);
}

void irq_set_mask(uint8_t line) {
    uint16_t port;
    uint8_t value;
 
    if(line < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        line -= 8;
    }
    value = inb(port) | (1 << line);
    outb(port, value);        
}

void irq_handler(uint32_t irq_num, uint32_t error_code) {
    kprints("irq num: ");
    irq_num;
    kprinth(irq_num, sizeof(uint32_t));
    kprints("\n");

    pic_send_eoi(irq_num);
}