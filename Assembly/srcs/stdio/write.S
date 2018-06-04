section .text
global asm_write

asm_write:
    mov     rax, 1
    syscall
    ret
