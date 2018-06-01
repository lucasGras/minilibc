//
// Created by lucasg on 30/05/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int asm_strlen(char *str);
extern void asm_write(int fd, char *buff, size_t len);
extern void *asm_memset(void *s, int c, size_t n);

int	main(int ac, char **av)
{
    /* strlen */
    printf("ASM strlen: %d; SYSTEM strlen: %d\n", asm_strlen("Test7654"), (int)strlen("Test7654"));

    /* memstr */
    char	str[20];
    asm_memset(str, '$', 12);
    pritnf("")
}