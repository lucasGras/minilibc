section .text
global  asm_puts
;int    asm_puts(char *s)

; temporary
extern  putchar

asm_puts:
    push    rbp
    mov     rbp, rsp

call:
    cmp     BYTE [rdi], 0
    je      return
    call    putchar
    syscall
    inc     rdi
    jmp     call

return:
    mov     rsp, rbp
    pop     rbp
    ret