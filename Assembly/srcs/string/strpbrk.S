section .text
global  strpbrk
;char   *asm_strpbrk(char *s, char *accept)

strpbrk:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    jmp     loop

reset:
    and     rcx, 0

find_occ:
    cmp     BYTE [rsi + rcx], 0
    je      sub_loop
    xor     r8b, r8b
    mov     r8b, BYTE [rdi]
    cmp     BYTE [rsi + rcx], r8b
    je      success
    inc     rcx
    jmp     find_occ

loop:
    cmp     BYTE [rdi], 0
    je      return
    jmp     reset

sub_loop:
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