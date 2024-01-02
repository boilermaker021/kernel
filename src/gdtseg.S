
.section .text
.globl register_segment_setup
register_segment_setup:
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
