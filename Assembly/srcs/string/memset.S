section .text
global memset
; void *asm_memset(void *s, int c, size_t n)

memset:
    push    rbp
    mov     rbp, rsp

    xor     rcx, rcx ; set iterator
    mov     rax, rdi

loop:
    cmp rcx, rdx ;check iterator vs n
    je  return ;return if iterator == n
    mov [rax], sil ;set rdi[] to c
    inc rax ;rdi++
    inc rcx ;rcx++
    jmp loop ;while

return:
    mov     rsp, rbp
    pop     rbp
    ret