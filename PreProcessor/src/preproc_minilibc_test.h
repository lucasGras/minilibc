//
// Created by lucasg on 29/05/18.
//

#ifndef MINILIBC_PREPROC_MINILIBC_TEST_H
#define MINILIBC_PREPROC_MINILIBC_TEST_H

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
    printf("strlen=%d\n", ret);
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
    printf("%s\n", EXEC_FUNC_PRM2(pp_memstrcat, src, dest));
}

PREPROC_FUNCTION_VOID(void, tests_index)
{
    
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
    EXEC_FUNC_VOID(tests_strcat);
    RETURN(1);
}

PREPROC_FUNCTION_PRM2(int, tests, ac, int, av, char **)
{
    RETURN((ac == 2) ? EXEC_FUNC_VOID(__exec_all_tests__) : 0);
}

#endif //MINILIBC_PREPROC_MINILIBC_TEST_H
