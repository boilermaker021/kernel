.section .text
.globl interrupt
interrupt:
        pusha
        
        movl 32(%esp), %eax #push interrupt number
        pushl %eax
        movl 36(%esp), %eax #push error code number (0 if non applicable)
        pushl %eax
        call int_handler #go to C-level interrupt handler
        pop %eax
        pop %eax
        popa
        add $8, %esp #remove error code and then interrupt number
        sti
        iret

.macro INT_NOERR num
.globl INT_NOERR\num
INT_NOERR\num:
        cli
        pushl $0
        pushl $\num
        jmp interrupt
.endm

.macro INT_ERR num
.globl INT_ERR\num
INT_ERR\num:
        cli
        pushl $\num
        jmp interrupt
.endm

INT_NOERR 0
INT_NOERR 1
INT_NOERR 2
INT_NOERR 3
INT_NOERR 4
INT_NOERR 5
INT_NOERR 6
INT_NOERR 7
INT_ERR 8
INT_NOERR 9
INT_ERR 10
INT_ERR 11
INT_ERR 12
INT_ERR 13
INT_ERR 14
INT_NOERR 15
INT_NOERR 16
INT_NOERR 17
INT_NOERR 18
INT_NOERR 19
INT_NOERR 20
INT_NOERR 21
INT_NOERR 22
INT_NOERR 23
INT_NOERR 24
INT_NOERR 25
INT_NOERR 26
INT_NOERR 27
INT_NOERR 28
INT_NOERR 29
INT_NOERR 30
INT_NOERR 31
INT_NOERR 32