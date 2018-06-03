section .text
global  asm_strstr
;char   *asm_strstr(char *haystack, char *needle)

asm_strstr:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    jmp     loop

search:
    cmp     BYTE [rsi + rcx], 0
    je      success
    xor     r8b, r8b
    mov     r8b, BYTE [rdi]
    cmp     BYTE [rsi + rcx], r8b
    jne     sub_loop
    inc     rcx
    jmp     search

loop:
    cmp     BYTE [rdi], 0
    je      return
    xor     rcx, rcx
    jmp     search

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