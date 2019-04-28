BITS 64
section .text
global rindex
;char   *rindex(char *s, int c)

rindex:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor	    rcx, rcx

goto_end_ptr:
    cmp     BYTE [rdi + rcx], 0
    je      loop
    inc     rcx
    jmp     goto_end_ptr

loop:
    cmp     BYTE [rdi + rcx], sil
    je      success
    cmp     rcx, 0
    je      failure
    dec     rcx
    jmp     loop

success:
    mov     rax, rdi
    add		rax, rcx

    mov     rsp, rbp
    pop     rbp
    ret

failure:
    mov rax, 0

    mov    rsp, rbp
    pop    rbp
    ret
