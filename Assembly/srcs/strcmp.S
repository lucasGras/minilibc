section .text
global asm_strcmp
;int    asm_strcmp(char *s1, char *s2)
;rdi = s1, rsi = s2
;tmp sub = rcx
;res = rdi - rsi

asm_strcmp:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax

loop:
    mov     rax, [rdi + rcx]
    mov     r10, [rsi + rcx]
    cmp     rax, 0
    je      return
    cmp     r10, 0
    je      return
    cmp     rax, r10
    jne     return
    inc     rcx
    jmp     loop

return:
    sub     rax, r10

    mov     rsp, rbp
    pop     rbp
    ret