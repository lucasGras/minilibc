//
// Created by lucasg on 24/05/18.
//

#ifndef MINILIBC_PREPROC_MINILIB_H
#define MINILIBC_PREPROC_MINILIB_H

#include "libstring.h"
#include "preproc_minilibc_test.h"

PREPROC_MAIN(int, main)
{
    return (EXEC_FUNC_PRM2(tests, ac, av));
}

#endif //MINILIBC_PREPROC_MINILIB_H
