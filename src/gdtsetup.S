
.section .text
.globl gdt_setup
gdt_setup:
        mov 4(%esp), %eax
        lgdt (%eax)
        jmp $0x08, $farjmp
farjmp:
        movl $0x10, %eax
        movw %ax, %ds
        movw %ax, %es
        movw %ax, %fs
        movw %ax, %gs
        movw %ax, %ss
        ret
