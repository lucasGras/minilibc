//
// Created by lucasg on 17/05/18.
//

#ifndef LIBSTRING_PRINT_MINILIBC_H
#define LIBSTRING_PRINT_MINILIBC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "memsize.h"

PREPROC_FUNCTION(int, pp_putc, c, char)
{
    EXEC_SYS(write(1, &c, 1), -1);
    RETURN(0);
}

PREPROC_FUNCTION(void, pp_putstr, str, char *)
{
    while (*str) {
        EXEC_FUNC(pp_putc, *str);
        str++;
    }
}

PREPROC_FUNCTION(size_t, pp_strlen, str, char *)
{
    char    *ptr = str;
    while (*str)
        str++;
    RETURN(str - ptr);
}

PREPROC_FUNCTION_PRM2(char *, pp_strcpy, src, char *, dest, char *)
{
    int     i = 0;
    while (*src) {
        *(dest + i) = *src;
        src++;
        i++;
    }
    RETURN(dest);
}

PREPROC_FUNCTION(char *, pp_strdup, ptr, char *)
{
    char	*dup = malloc(sizeof(char) *
		(EXEC_FUNC(pp_strlen, ptr) + 1));
    dup = EXEC_FUNC_PRM2(pp_strcpy, ptr, dup);
    RETURN(dup);
}

#endif //MINILIBC_PREPROCESSOR_MINILIBC_H
