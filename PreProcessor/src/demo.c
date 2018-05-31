//
// Created by lucasg on 17/05/18.
//

#include "preproc_minilib.h"

/*
 * __demo__ function
 * Usage of preprocessor functions in common C
 * The main function is located in the preproc_minilib.h file
 */

void	__demo__(void)
{
    int a = MAIN_PREFIXpp_strcmp("This is a test", "This is a");

    printf("strcmp result=%d\n", a);
    MAIN_PREFIXpp_putstr("demo");
}