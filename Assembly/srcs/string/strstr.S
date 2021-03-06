section .text
global  strstr
;char   *asm_strstr(char *haystack, char *needle)

strstr:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    jmp     loop

reset:
    and     rcx, 0

search:
    cmp     BYTE [rsi + rcx], 0
    je      success
    xor     r8b, r8b
    mov     r8b, BYTE [rdi + rcx]
    cmp     BYTE [rsi + rcx], r8b
    jne     sub_loop
    inc     rcx
    jmp     search

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