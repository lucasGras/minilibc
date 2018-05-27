//
// Created by lucasg on 24/05/18.
//

#ifndef MINILIBC_PREPROC_MINILIB_H
#define MINILIBC_PREPROC_MINILIB_H

#include "libstring.h"

PREPROC_MAIN(int, main)
{
    char *dup = EXEC_FUNC(pp_strdup, "is_duped");

    printf("%s\n", dup);
    MEM_FREE(dup);
    RETURN(0);
}

#endif //MINILIBC_PREPROC_MINILIB_H
