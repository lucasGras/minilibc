//
// Created by lucasg on 29/05/18.
//

#ifndef MINILIBC_PREPROC_MINILIBC_TEST_H
#define MINILIBC_PREPROC_MINILIBC_TEST_H

#include <string.h>

#define TEST_USAGE "____________________TESTS_RUNNING____________________\n"

PREPROC_FUNCTION_VOID(void, tests_putc)
{
    EXEC_FUNC(pp_putc, 't');
    EXEC_FUNC(pp_putc, '\n');
}

PREPROC_FUNCTION_VOID(void, tests_putstr)
{
    EXEC_FUNC(pp_putstr, "This is a test\n");
}

PREPROC_FUNCTION_VOID(void, tests_strlen)
{
    size_t  ret = EXEC_FUNC(pp_strlen, "Len of this\n"); //12
    printf("strlen=%d\n", (int)ret);
}

PREPROC_FUNCTION_VOID(void, tests_strcpy)
{
    char    test[20];
    char    *res = EXEC_FUNC_PRM2(pp_strcpy, "test strcpy", test);
    printf("strcpy=%s\n", res);
}

PREPROC_FUNCTION_VOID(void, tests_strdup)
{
    char    *dup = EXEC_FUNC(pp_strdup, "is_duped\n");
    printf("%s", dup);
    MEM_FREE(dup);
}

PREPROC_FUNCTION_VOID(void, tests_strcat)
{
    char	src[] = "This";
    char	dest[] = " is a test";
    char	*cat = EXEC_FUNC_PRM2(pp_memstrcat, src, dest);
    printf("%s\n", cat);
    MEM_FREE(cat);
}

PREPROC_FUNCTION_VOID(void, tests_index)
{
    char    index[] = "This is a test";
    printf("%s\n", EXEC_FUNC_PRM2(pp_index, index, (int)'a'));
}

PREPROC_FUNCTION_VOID(void, tests_strcmp)
{
    char    str[] = "This is a test";
    char    str1[] = "This is a test";
    char    str2[] = "This is e test";
    printf("%d %d\n", EXEC_FUNC_PRM2(pp_strcmp, str, str1),
           EXEC_FUNC_PRM2(pp_strcmp ,str, str2));
}

PREPROC_FUNCTION_VOID(void, tests_revstr)
{
    char    *rev = EXEC_FUNC(pp_memrevstr, "This is a test");
    printf("%s\n", rev);
    MEM_FREE(rev);
}

PREPROC_FUNCTION_VOID(void, tests_atoi)
{
    int	dig = EXEC_FUNC(pp_atoi, "42");
    int	dig1 = EXEC_FUNC(pp_atoi, "-42");
    int	dig2 = EXEC_FUNC(pp_atoi, "0");
    printf("%d %d %d\n", dig, dig1, dig2);
}

PREPROC_FUNCTION_VOID(void, tests_int_to_str)
{
    char *str = EXEC_FUNC(pp_int_to_str, 42);
    char *str1 = EXEC_FUNC(pp_int_to_str, 0);
    printf("%s %s\n", str, str1);
}

PREPROC_FUNCTION_VOID(void, tests_digitlen)
{
    int len = EXEC_FUNC(pp_digitlen, 1234);
    int len1 = EXEC_FUNC(pp_digitlen, 0);
    int len2 = EXEC_FUNC(pp_digitlen, -14);

    printf("%d %d %d\n", len, len1, len2);
}

PREPROC_FUNCTION_VOID(int, __exec_all_tests__)
{
    write(1, TEST_USAGE, 54);
    EXEC_FUNC_VOID(tests_putc);
    EXEC_FUNC_VOID(tests_putstr);
    EXEC_FUNC_VOID(tests_strlen);
    EXEC_FUNC_VOID(tests_strcpy);
    EXEC_FUNC_VOID(tests_strdup);
    EXEC_FUNC_VOID(tests_strcat);
    EXEC_FUNC_VOID(tests_index);
    EXEC_FUNC_VOID(tests_strcmp);
    EXEC_FUNC_VOID(tests_revstr);
    EXEC_FUNC_VOID(tests_atoi);
    EXEC_FUNC_VOID(tests_int_to_str);
    EXEC_FUNC_VOID(tests_digitlen);
    return (1);
}

PREPROC_FUNCTION_PRM2(int, tests, ac, int, av, char **) //TODO check tester in python input
{
    return ((ac == 2) ? EXEC_FUNC_VOID(__exec_all_tests__) : 0);
}

#endif //MINILIBC_PREPROC_MINILIBC_TEST_H
