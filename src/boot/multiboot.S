.set ALIGN, 1<<0
.set MEMINFO, 1<<1
#.set VIDEO_MODE, 1 << 2
.set FLAGS,   ALIGN | MEMINFO #| VIDEO_MODE
.set MAGIC,   0x1BADB002
.set CHECKSUM, -(MAGIC + FLAGS)

#video information
.set MODE, 0
.set WIDTH, 1024
.set HEIGHT, 768
.set DEPTH, 32


.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

#.long 0,0,0,0,0

#.long MODE
#.long WIDTH
#.long HEIGHT
#.long DEPTH



.section .bss
.align 16
stack_bottom:
.skip 16384 #16 KiB
stack_top:

.section .text
.global _start
.type _start, @function
_start:
  mov $stack_top, %esp
  /*
  perform critical startup actions here, like GDT, paging
  */

   push %eax #push multiboot info
   push %ebx #push magic #

   call kentry
   cli
1: hlt
   jmp 1


.size _start, . - _start
