//
// Created by lucasg on 30/05/18.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
    extern int asm_strlen(char *str);

    printf("ASM strlen: %d; SYSTEM strlen: %d\n", asm_strlen("Test7654"), (int)strlen("Test7654"));
}