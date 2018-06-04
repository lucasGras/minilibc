section .text
global asm_strnlen
;int    asm_strnlen(char *str, size_t len)

asm_strnlen:
    push    rbp
    mov     rbp, rsp

    xor     rax, rax ;set all bytes to 0

loop:
    cmp     BYTE [rdi], 0 ;cmp *rdi == '\0'
    je      return ;break
    inc     rax ;res++
    inc     rdi ;rdi++
    cmp     rax, rsi ;cmp res == len
    je      return ;break
    jmp     loop ;while

return:
    mov     rsp, rbp
    pop     rbp
    ret