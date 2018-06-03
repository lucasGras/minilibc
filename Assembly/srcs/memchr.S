section .text
global  asm_memchr
;void   *asm_memchr(void *s, int c, size_t n)

asm_memchr:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx

loop:
    cmp     BYTE [rdi], 0
    je      return
    cmp     rcx, rdx
    je      return
    cmp     BYTE [rdi], sil
    je      success
    inc     rcx
    inc     rdi
    jmp     loop

success:
    mov     rax, rdi
    mov     rsp, rbp
    pop     rbp
    ret

return:
    mov     rax, 0
    mov     rsp, rbp
    pop     rbp
    ret