.globl idt_setup
idt_setup:
        mov 4(%esp), %eax
        lidt (%eax)
        ret