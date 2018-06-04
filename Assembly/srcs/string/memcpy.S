section .text
global asm_memcpy
;void *memcpy(void *dest, void *src, size_t n)
;dest=rdi
;src=rsi
;n=rdx
; Memory areas must not overlap

asm_memcpy:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx

loop:
    mov     r8b, [rsi + rcx]
    cmp     r8b, 0
    je      return
    mov     [rdi + rcx], r8b
    inc     rcx
    cmp     rcx, rdx
    je      return
    jmp     loop

return:
    mov     rsp, rbp
    pop     rbp
    ret