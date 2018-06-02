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
extern char     *asm_strchr(char *s, int c);
extern void	*asm_memcpy(void *dest, void *src, size_t n);

int	main(int ac, char **av)
{
    /* strlen */
    printf("strlen; ASM:%d; SYSTEM:%d\n", asm_strlen("Test7654"), (int)strlen("Test7654"));

    /* strnlen */
    printf("strnlen; ASM:%d; SYSTEM:%d\n", asm_strnlen("Test7654", 6), (int)strnlen("Test7654", 6));

    /* memset */
    char	str_set[20];
    char	sys_set[20];

    strcpy(str_set, "This is a test");
    strcpy(sys_set, "This is a test");
    asm_memset(str_set, '$', 4);
    memset(sys_set, '$', 4);
    printf("memset; ASM:%s; SYSTEM:%s\n", str_set, sys_set);

    /* memcpy */
    char	str_cpy[20];
    char	sys_cpy[20];

    asm_memcpy(str_cpy, "This is a test", 6);
    memcpy(sys_cpy, "This is  a test", 6);
    printf("memcpy; ASM:%s; SYSTEM:%s\n", str_cpy, sys_cpy);

    /* strcmp */
    char	s1[] = "This";
    char	s2[] = "Thi";

    printf("strcmp; ASM:%d; SYSTEM:%d\n", asm_strcmp(s1, s2), strcmp(s1, s2));

    /* strncmp */
    char	s3[] = "This is awesome";
    char	s4[] = "This is incredible";

    printf("strncmp; ASM:%d; SYSTEM:%d\n", asm_strncmp(s3, s4, 6), strncmp(s3, s4, 6));

    /* strchr */
    printf("strchr; ASM:%s; SYSTEM:%s\n", asm_strchr(s3, 'a'), strchr(s3, 'a'));

    return 0;
}