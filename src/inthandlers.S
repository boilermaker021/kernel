.section .rodata
string: .asciz "Test String\n";

.section .text
.globl interrupt
interrupt:
        cli
        pusha
        pushw $0
        call int_handler
        popw %ax
        popa
        sti
        iret
