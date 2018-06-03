section .text
global asm_memmove
;void *memmove(void *dest, void *src, size_t n)
;dest=rdi
;src=rsi
;n=rdx
; np_anyptrlt if rsi - rdi > 0
; Memory areas may overlap

asm_memmove:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx
    mov     r9, rsi
    sub     r9, rdi ;rsi - rdi
    cmp     r9, 0
    jge     __np_anyptrlt

loop:
    mov     r8b, [rsi + rcx]
    cmp     r8b, 0
    je      return
    mov     [rdi + rcx], r8b
    inc     rcx
    cmp     rcx, rdx
    je      return
    jmp     loop

__np_anyptrlt:
    mov     r10, [rsi + rdx]
    cmp     r10, 0
    je      return
    mov     [rdi + rdx], r10
    dec     rdx
    cmp     rdx, 0
    je      return
    jmp     __np_anyptrlt

return:
    mov     rsp, rbp
    pop     rbp
    ret