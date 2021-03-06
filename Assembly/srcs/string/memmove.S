section .text
global memmove
;void *memmove(void *dest, void *src, size_t n)
;dest=rdi
;src=rsi
;n=rdx
; np_anyptrlt if rsi - rdi > 0
; Memory areas may overlap

memmove:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx

loop:
	cmp     rcx, rdx
    je      return
	cmp     BYTE [rsi + rcx], 0
    je      return
    mov     r8b, BYTE [rsi + rcx]
    mov     BYTE [rdi + rcx], r8b
    inc     rcx
    jmp     loop

return:
    mov     rsp, rbp
    pop     rbp
    ret