section .text
global asm_strlen
;int    asm_strlen(char *str)

asm_strlen:
    xor     rax, rax ;set all bytes to 0

loop:
    cmp     BYTE [rdi], 0 ;cmp *rdi == '\0'
    je      return ;break
    inc     rax ;res++
    inc     rdi ;rdi++
    jmp     loop ;while

return:
    ret