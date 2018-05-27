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
	RETURN(0);
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
    RETURN(get);
}

#endif //MINILIBC_LIBSTRING_UTILS_H
