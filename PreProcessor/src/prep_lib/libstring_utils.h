//
// Created by lucasg on 28/05/18.
//

#ifndef MINILIBC_LIBSTRING_UTILS_H
#define MINILIBC_LIBSTRING_UTILS_H

PREPROC_FUNCTION(int, pp_atoi, str, char *)
{
    int get = 0;
    int neg = 0;
    if (!str || (*str == '0' && EXEC_FUNC(pp_strlen, str) == 1))
	return (0);
    if (*str == '-') {
	str++;
	neg = 1;
    }
    while (*str) {
	if (*str < 48 || *str > 57)
	    break;
	get *= 10;
	get += (*str) - '0';
	str++;
    }
    if (neg == 1)
	get *= -1;
    return (get);
}

PREPROC_FUNCTION(int, pp_digitlen, nb, int)
{
    int i = 0;
    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return ++i;
}

PREPROC_FUNCTION(char *, pp_int_to_str, nb, int)
{
    char *str = MEM_ALLOC(char, (EXEC_FUNC(pp_digitlen, nb) + 1));
    int  i = 0;
    MEM_PROTECT_ALLOC(str, 84)
    if (nb < 0)
        nb *= -1;
    if (nb == 0) {
	POINT_OFFSET_VAL(str, i, '0');
	str++;
    }
    while (nb != 0) {
        *str = (char) ((nb % 10) + '0');
        nb /= 10;
    	str++;
    }
    *str = '\0';
    str = EXEC_FUNC(pp_memrevstr, str);
    return str;
}

#endif //MINILIBC_LIBSTRING_UTILS_H
