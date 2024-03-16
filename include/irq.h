#ifndef IRQ_H
#define IRQ_H


#define IRQ_START 32
#define IRQ(x) x+IRQ_START

void irq0();
void irq1();
void irq2();
void irq3();
void irq4();
void irq5();
void irq6();
void irq7();
void irq8();
void irq9();
void irq10();
void irq11();
void irq12();
void irq13();
void irq14();
void irq15();


void setup_irq_handler(uint8_t irq_num, void *fn);
void irq_clear_mask(uint8_t line);
void irq_set_mask(uint8_t line);

#endif