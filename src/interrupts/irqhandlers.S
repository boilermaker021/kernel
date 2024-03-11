.macro irq num
.globl irq\num
irq\num:
        cli
        pushl $0
        pushl $\num
        
        jmp irq
.endm

irq:
    pusha
    movl 32(%esp), %eax #push interrupt number
    pushl %eax
    movl 36(%esp), %eax #push error code number (0 if non applicable)
    pushl %eax
    call irq_handler #go to C-level interrupt handler
    pop %eax
    pop %eax
    popa
    add $8, %esp #remove error code and then interrupt number
    sti
    iret

irq 0
irq 1
irq 2
irq 3
irq 4
irq 5
irq 6
irq 7
irq 8
irq 9
irq 10
irq 11
irq 12
irq 13
irq 14
irq 15