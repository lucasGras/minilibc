section .text
global  asm_strcspn
;size_t   asm_strcspn(char *s, char *reject)

asm_strcspn:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    jmp     loop

reset:
    and     rcx, 0

count_nonrejected:
    cmp     BYTE [rsi + rcx], 0
    je      sub_loop_incrax
    xor     r8b, r8b
    mov     r8b, BYTE [rdi]
    cmp     BYTE [rsi + rcx], r8b
    je      return
    inc     rcx
    jmp     count_nonrejected

loop:
    cmp     BYTE [rdi], 0
    je      return
    jmp     reset

sub_loop_incrax:
    inc     rax
    inc     rdi
    jmp     loop

return:
    mov     rsp, rbp
    pop     rbp
    ret