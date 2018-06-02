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
    printf("strlen; ASM:%d; SYSTEM:%d\n", asm_strlen("Test7654"), (int)strlen("Test7654"));

    /* memstr */
    char	str[20];
    char	sys[20];

    strcpy(str, "This is a test");
    strcpy(sys, "This is a test");
    asm_memset(str, '$', 4);
    memset(sys, '$', 4);
    printf("memset; ASM:%s; SYSTEM:%s\n", str, sys);
}