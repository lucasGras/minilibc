section .text
global asm_write

asm_putchar:
    mov     rax, 4
    syscall
    ret
