section .text
global asm_strncmp
;int    asm_strncmp(char *s1, char *s2, size_t n)

asm_strncmp:
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
    cmp     rdx, rcx ;cmp i == n
    je      return
    inc     rcx
    jmp     loop

return:
    sub     al, r10b
    movsx   rax, al

    mov     rsp, rbp
    pop     rbp
    ret