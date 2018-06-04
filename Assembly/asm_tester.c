//
// Created by lucasg on 30/05/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ---------- string.h
extern int	asm_strlen(char *str);
extern int	asm_strnlen(char *str, size_t len);
extern void	asm_write(int fd, char *buff, size_t len);
extern void	*asm_memset(void *s, int c, size_t n);
extern int	asm_strcmp(char *s1, char *s2);
extern int 	asm_strncmp(char *s1, char *s2, size_t n);
extern int 	asm_strcasecmp(char *s1, char *s2);
extern char     *asm_strchr(char *s, int c);
extern void	*asm_memcpy(void *dest, void *src, size_t n);
extern void	*asm_memmove(void *dest, void *src, size_t n);
extern char 	*asm_rindex(char *s, int c);
extern char 	*asm_strstr(char *haystack, char *needle);
extern char 	*asm_strpbrk(char *s, char *accept);
extern size_t 	asm_strcspn(char *s, char *reject);
extern void	*asm_memchr(void *s, int c, size_t n);
extern char 	*asm_strcat(char *dest, char *src);

// ---------- stdio.h
extern int      asm_putchar(char c);

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
    char        gg_testcpy[100] = "Geeksfor";

    asm_memcpy(str_cpy, "This is a test", 6);
    memcpy(sys_cpy, "This is  a test", 6);
    asm_memcpy(gg_testcpy + 5, gg_testcpy, strlen(gg_testcpy) + 1);
    printf("memcpy; ASM:%s; SYSTEM:%s\n", str_cpy, sys_cpy);
    printf("memcpy; ASM:%s; SYSTEM:GeeksGeeksGeek\n", gg_testcpy);

    /* memmove */
    char	str_move[50] = "Warning,";
    char	sys_move[50] = "Warning,";
    char        gg_testmove[100] = "Geeksfor";

    asm_memmove(str_move, "This is a test", 3);
    memmove(sys_move, "This is  a test", 3);
    asm_memmove(gg_testmove + 5, gg_testmove, strlen(gg_testmove) + 1);
    printf("memmove; ASM:%s; SYSTEM:%s\n", str_move, sys_move);
    printf("memmove; ASM:%s; SYSTEM:GeeksGeeksfor\n", gg_testmove);

    /* memchr */
    char str[] = "http://www.tutorialspoint.com";
    char ch = '.';
    char *ret = asm_memchr(str, ch, strlen(str));
    char *ret_sys = memchr(str, ch, strlen(str));

    printf("memchr; ASM:%s; SYSTEM:%s\n", ret, ret_sys);

    /* strcmp */
    char	s1[] = "This";
    char	s2[] = "Thi";

    printf("strcmp; ASM:%d; SYSTEM:%d\n", asm_strcmp(s1, s2), strcmp(s1, s2));

    /* strncmp */
    char	s3[] = "This is awesome";
    char	s4[] = "This is incredible";

    printf("strncmp; ASM:%d; SYSTEM:%d\n", asm_strncmp(s3, s4, 6), strncmp(s3, s4, 6));

    /* strcasecmp */
    char	s5[] = "This is awesome";
    char	s6[] = "This is AWESOME";

    printf("strcasecmp; ASM:%d; SYSTEM:%d\n", asm_strcasecmp(s5, s6), strcasecmp(s5, s6));

    /* strchr */
    printf("strchr; ASM:%s; SYSTEM:%s\n", asm_strchr(s3, 'a'), strchr(s3, 'a'));

    /* rindex */
    printf("rindex; ASM:%s; SYSTEM:%s\n", asm_rindex(s3, 'i'), rindex(s3, 'i'));

    /* strstr */
    printf("strstr; ASM:%s; SYSTEM:%s\n", asm_strstr(s3, "aw"), strstr(s3, "aw"));

    /* strpbrk */
    printf("strpbrk; ASM:%s; SYSTEM:%s\n", asm_strpbrk(s3, "242432  azenlmk"), strpbrk(s3, "242432  azenlmk"));

    /* strcspn */
    printf("strcspn; ASM:%d; SYSTEM:%d\n", asm_strcspn("geeksforgeeks", "kfc"), strcspn("geeksforgeeks", "kfc"));

    /* strcat */
    char 	dest[50] = "Hey ! ";
    char 	destsys[50] = "Hey! ";
    char 	src[] = "This is a test";

    printf("strcat; ASM:%s; SYSTEM:%s\n", asm_strcat(dest, src), strcat(destsys, src));

    /* putchar */
    asm_putchar('a');
    putchar('a');
    printf("\n");

    return 0;
}