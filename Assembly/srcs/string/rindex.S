section .text
global asm_rindex
;char   *rindex(char *s, int c)

asm_rindex:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax

goto_end_ptr:
    cmp     BYTE [rdi], 0
    je      loop
    inc     rdi
    jmp     goto_end_ptr

loop:
    cmp     BYTE [rdi], sil
    je      success
    dec     rdi
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
