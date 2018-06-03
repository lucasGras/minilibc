section .text
global asm_strcasecmp

asm_strcasecmp:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx
    dec     rcx

setcase_rdi:
    inc     rcx
    cmp     BYTE [rdi + rcx], 0
    jmp     reset_counter
    cmp     BYTE [rdi + rcx], 0x41 ; 'A'
    jl      setcase_rdi
    cmp     BYTE [rdi + rcx], 0x5A ; 'Z'
    jg      setcase_rdi
    add     BYTE [rdi + rcx], 0x20 ; tolower
    jmp     setcase_rdi

reset_counter:
    xor     rcx, rcx
    dec     rcx

setcase_rsi:
    inc     rcx
    cmp     BYTE [rsi + rcx], 0
    jmp     pre_loop
    cmp     BYTE [rsi + rcx], 0x61 ; 'a'
    jl      setcase_rsi
    cmp     BYTE [rsi + rcx], 0x7A ; 'z'
    jg      setcase_rsi
    sub     BYTE [rsi + rcx], 0x20 ; toupper
    jmp     setcase_rsi

pre_loop:
    xor     rcx, rcx

loop:
    mov     al, [rdi + rcx]
    mov     r10b, [rsi + rcx]
    cmp     al, 0
    je      return
    cmp     r10b, 0
    je      return
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