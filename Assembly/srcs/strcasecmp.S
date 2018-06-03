section .text
global asm_strcasecmp

asm_strcasecmp:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx

setcase_al:
    cmp     al, 0x41 ; 'A'
    jl      setcase_r10b
    cmp     al, 0x5A ; 'Z'
    jg      setcase_r10b
    add     al, 0x20 ; tolower
    jmp     setcase_r10b

setcase_r10b:
    cmp     r10b, 0x41 ; 'A'
    jl      compare
    cmp     r10b, 0x5A ; 'Z'
    jg      compare
    add     r10b, 0x20 ; tolower
    jmp     compare

loop:
    mov     al, [rdi + rcx]
    mov     r10b, [rsi + rcx]
    cmp     al, 0
    je      return
    cmp     r10b, 0
    je      return
    jmp     setcase_al

compare:
    cmp     al, r10b
    jne     return
    inc     rcx
    jmp     loop

return:
    sub     al, r10b
    movsx   rax, al

    mov     rsp, rbp
    pop     rbp
    ret