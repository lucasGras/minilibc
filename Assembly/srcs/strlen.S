BITS 64

SECTION .text
GLOBAL asm_strlen

asm_strlen:
    push    rbp
    mov     rbp, rsp
    xor     rax, rax

    cmp     rdi, 0
    jmp     return

loop:
    cmp     rdi, 0
    jmp     return
    inc     rdi
    inc     rax
    jmp     loop

return:
    leave
    ret