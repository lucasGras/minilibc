section .text
global asm_memset
; void *asm_memset(void *s, int c, size_t n)

asm_memset:
    cmp rdi, rdx ; check iterator vs n
    jg  return ; return if iterator == n
    mov rdi, rsi ; set rdi[] to 0
    inc rdi ; rdi++
    jmp asm_memset

return:
    ret