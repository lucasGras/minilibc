//
// Created by lucasg on 24/05/18.
//

#ifndef MINILIBC_FUNCTIONS_H
#define MINILIBC_FUNCTIONS_H

/* MAIN */
#define PREPROC_MAIN(type, name) type name(int ac, char **av)

/* DEFINITION */
#define PREPROC_FUNCTION(type, name, _prm, _prmtype) type MAIN_PREFIX##name(_prmtype _prm)

/* EXECUTION */
#define ERR (0)
#define RETURN(r) return(r)

#define EXEC_FUNC(name, _v1) MAIN_PREFIX##name(_v1)
#define EXEC_SYS(f_ret, critical) if ((f_ret) == (critical)) {RETURN(-1);};

#endif //UNTITLED1_FUNCTIONS_H
