//
// Created by lucasg on 17/05/18.
//

#ifndef LIBSTRING_PRINT_MINILIBC_H
#define LIBSTRING_PRINT_MINILIBC_H

PREPROC_FUNCTION(int, pp_putc, c, char)
{
    EXEC_SYS(write(1, &c, 1), -1);
    return (0);
}

PREPROC_FUNCTION(void, pp_putstr, str, char *)
{
    while (*str) {
        EXEC_FUNC(pp_putc, *str);
        str++;
    }
}

#endif //MINILIBC_PREPROCESSOR_MINILIBC_H
