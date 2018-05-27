//
// Created by lucasg on 24/05/18.
//

#ifndef MINILIBC_PREPROC_MINILIB_H
#define MINILIBC_PREPROC_MINILIB_H

#include "libstring_print.h"

PREPROC_MAIN(int, main)
{
    char test[] = "test";
    EXEC_FUNC(pp_putc, 'c');
    EXEC_FUNC(pp_putstr, test);
    printf("\n%s\n", EXEC_FUNC(pp_strdup, "is_duped"));
    printf("%d\n", EXEC_FUNC(pp_strlen, "test"));
    RETURN(0);
}

#endif //MINILIBC_PREPROC_MINILIB_H
