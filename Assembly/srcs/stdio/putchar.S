section .text
global  asm_putchar
;int    asm_putchar(char c)

asm_putchar:
    push    rbp
    mov     rbp, rsp

call:
    mov     rdi, 1
    mov     rsi, rbp
    mov     rdx, 1
    mov     rax, 1
    syscall

return:
    mov     rsp, rbp
    pop     rbp
    ret