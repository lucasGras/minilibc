section .text
global asm_strlen

asm_strlen:
    xor     rax, rax

loop:
    cmp     BYTE [rdi], 0
    jz      return
    inc     rax
    inc     rdi
    jmp     loop

return:
    ret