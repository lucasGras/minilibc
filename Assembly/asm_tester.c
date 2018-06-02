//
// Created by lucasg on 30/05/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern int	asm_strlen(char *str);
extern int	asm_strnlen(char *str, size_t len);
extern void	asm_write(int fd, char *buff, size_t len);
extern void	*asm_memset(void *s, int c, size_t n);
extern int	asm_strcmp(char *s1, char *s2);
extern int 	asm_strncmp(char *s1, char *s2, size_t n);

int	main(int ac, char **av)
{
    /* strlen */
    printf("strlen; ASM:%d; SYSTEM:%d\n", asm_strlen("Test7654"), (int)strlen("Test7654"));

    /* strnlen */
    printf("strnlen; ASM:%d; SYSTEM:%d\n", asm_strnlen("Test7654", 6), (int)strnlen("Test7654", 6));

    /* memset */
    char	str[20];
    char	sys[20];

    strcpy(str, "This is a test");
    strcpy(sys, "This is a test");
    asm_memset(str, '$', 4);
    memset(sys, '$', 4);
    printf("memset; ASM:%s; SYSTEM:%s\n", str, sys);

    /* strcmp */
    char	s1[] = "This";
    char	s2[] = "Thi";

    printf("strcmp; ASM:%d; SYSTEM:%d\n", asm_strcmp(s1, s2), strcmp(s1, s2));

    /* strncmp */
    char	s3[] = "This is awesome";
    char	s4[] = "This is incredible";

    printf("strcmp; ASM:%d; SYSTEM:%d\n", asm_strncmp(s3, s4, 6), strncmp(s3, s4, 6));

    return 0;
}