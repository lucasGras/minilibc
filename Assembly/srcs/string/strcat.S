section .text
global  asm_strcat
;char   *asm_strcat(char *dest, char *src)

asm_strcat:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax
    xor     rcx, rcx
    xor     r9, r9
    mov     rax, rdi
    cmp     BYTE [rax], 0
    je      fill_rdi

skip_rdi:
    cmp     BYTE [rax + rcx], 0
    je      append_rsi
    inc     rcx
    jmp     skip_rdi

append_rsi:
    cmp     BYTE [rsi + r9], 0
    je      return
    xor     r8b, r8b
    mov     r8b, BYTE [rsi + r9]
    mov     BYTE [rax + rcx], r8b
    inc     rcx
    inc     r9
    jmp     append_rsi

fill_rdi:
    cmp     BYTE [rsi + rcx], 0
    je      return
    xor     r8b, r8b
    mov     r8b, BYTE [rsi + rcx]
    mov     BYTE [rax + rcx], r8b
    inc     rcx
    jmp     fill_rdi

return:
    mov     BYTE [rax + rcx], 0
    mov     rsp, rbp
    pop     rbp
    ret