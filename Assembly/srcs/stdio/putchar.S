section .text
global  asm_putchar
;int    asm_putchar(char c)

; temporary
extern  putchar

asm_putchar:
    push    rbp
    mov     rbp, rsp

call:
    call    putchar
    syscall

return:
    mov     rsp, rbp
    pop     rbp
    ret