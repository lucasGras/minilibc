//
// Created by lucasg on 17/05/18.
//

#ifndef LIBSTRING_PRINT_MINILIBC_H
#define LIBSTRING_PRINT_MINILIBC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

PREPROC_FUNCTION(int, pp_putchar, c, char)
{
    EXEC_SYS(write(1, &c, 1), -1);
    RETURN(0);
}

PREPROC_FUNCTION(void, pp_putstr, str, char *)
{
    while (*str) {
        EXEC_FUNC(pp_putchar, *str);
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

#endif //MINILIBC_PREPROCESSOR_MINILIBC_H
