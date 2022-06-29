gdt_start:

gdt_null:
    dd 0x0
    dd 0x0
  
gdt_code:
    ;base = 0x0, limit=0xffffffff
    dw 0xffff;limit (0-15)
    dw 0x0;base(0-15)
    db 0x0 ; base bits 16-23
    db 0b10011010;flags
    db 0b11001111;flags
    db 0x0  ; base (24-31)

gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0  ;base

gdt_end:

gdt_descriptor:
  dw gdt_end - gdt_start -1
  dd gdt_start

CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start


  