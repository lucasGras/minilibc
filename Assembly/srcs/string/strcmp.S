section .text
global strcmp
;int    asm_strcmp(char *s1, char *s2)

strcmp:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx

loop:
    mov     al, [rdi + rcx]
    mov     r10b, [rsi + rcx]
    cmp     al, 0
    je      return
    cmp     r10b, 0
    je      return
    cmp     al, r10b
    jne     return
    inc     rcx
    jmp     loop

return:
    sub     al, r10b
    movsx   rax, al

    mov     rsp, rbp
    pop     rbp
    ret