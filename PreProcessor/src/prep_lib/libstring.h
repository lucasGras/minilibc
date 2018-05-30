//
// Created by lucasg on 28/05/18.
//

#ifndef MINILIBC_LIBSTRING_H
#define MINILIBC_LIBSTRING_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "memory.h"

PREPROC_FUNCTION(size_t, pp_strlen, str, char *)
{
    char    *ptr = str;
    while (*str)
    	str++;
    return (str - ptr);
}

PREPROC_FUNCTION_PRM2(char *, pp_strcpy, src, char *, dest, char *)
{
    int     i = 0;
    while (*src) {
        POINT_OFFSET_PTR(dest, i, src)
	src++;
	i++;
    }
    POINT_OFFSET_VAL(dest, i, '\0')
    return (dest);
}

PREPROC_FUNCTION(char *, pp_strdup, ptr, char *) {
    char *dup = MEM_ALLOC(char, (EXEC_FUNC(pp_strlen, ptr) + 1));
    MEM_PROTECT_ALLOC(dup, CRITICAL);
    dup = EXEC_FUNC_PRM2(pp_strcpy, ptr, dup);
    return (dup);
}

PREPROC_FUNCTION_PRM2(char *, pp_memstrcat, src, char *, dest, char *)
{
    size_t	len= EXEC_FUNC(pp_strlen, dest) + EXEC_FUNC(pp_strlen, src) + 1;
    char	*cat = MEM_ALLOC(char, len);
    int		i = -1;

    MEM_PROTECT_ALLOC(cat, CRITICAL)
    if (!src) {
        while (*dest) {
	    ++i;
            POINT_OFFSET_PTR(cat, i, dest)
            dest++;
        }
    } else {
	while (*src) {
	    ++i;
	    POINT_OFFSET_PTR(cat, i, src)
	    src++;
	}
	while (*dest) {
	    ++i;
	    POINT_OFFSET_PTR(cat, i, dest)
	    dest++;
	}
    }
    POINT_OFFSET_VAL(cat, ++i, '\0')
    return (cat);
}

PREPROC_FUNCTION_PRM2(char *, pp_index, ptr, char *, c, int)
{
    while (*ptr) {
	if (*ptr == (char)c)
	    return (ptr);
	ptr++;
    }
    return (NULL);
}

PREPROC_FUNCTION_PRM2(int, pp_strcmp, str, char *, str1, char *)
{
    if (!str || !str1)
	return (-1);
    while (*str == *str1) {
        if (!(*str) || !(*str1))
	    break;
	str++;
	str1++;
    }
    return  (!(*str) && !(*str1)) ? 0 : 1;
}

PREPROC_FUNCTION(char *, pp_revstr, str, char *) //TODO mem to fix
{
    char	*rev = MEM_ALLOC(char, EXEC_FUNC(pp_strlen, str) + 1);
    size_t	i = EXEC_FUNC(pp_strlen, str) - 1;
    int		offset = 0;

    for (; i >= 0 ; i--) {
	rev[offset] = str[i];
	offset++;
    }
    rev[offset] = '\0';
    return (rev);
}

PREPROC_FUNCTION(int, pp_strtok, str, char *)
{
    //char	*array = MEM_ALLOC(char *, );
}

#include "libstring_print.h"
#include "libstring_utils.h"

#endif //MINILIBC_LIBSTRING_H
