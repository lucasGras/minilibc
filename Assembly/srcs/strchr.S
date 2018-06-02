section .text
global asm_strchr
;char   *asm_strchr(char *s, int c)
;char *s = rdi
;int c = rsi

asm_strchr:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax

loop:
    cmp     BYTE [rdi], 0
    je      failure
    cmp     BYTE [rdi], sil
    je      success
    inc     rdi
    jmp     loop

failure:
    mov     rsp, rbp
    pop     rbp
    ret

success:
    mov     rax, rdi

    mov     rsp, rbp
    pop     rbp
    ret