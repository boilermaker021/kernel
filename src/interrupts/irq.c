#include <stdint.h>

#include "pic.h"
#include "irq.h"

uint8_t defined_irqs[16] = {0};
void (*irq_functions[16])() = {0};


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

void setup_irq_handler(uint8_t irq_num, void *fn) {
    defined_irqs[irq_num] = 1;
    irq_functions[irq_num] = fn;
}

void irq_handler(uint32_t irq_num, uint32_t error_code) {
    if (defined_irqs[irq_num]) {
        irq_functions[irq_num]();
    }
    pic_send_eoi(irq_num);
}