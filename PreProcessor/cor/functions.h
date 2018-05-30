//
// Created by lucasg on 24/05/18.
//

#ifndef MINILIBC_FUNCTIONS_H
#define MINILIBC_FUNCTIONS_H

/* MAIN */
#define PREPROC_MAIN(type, name) type name(int ac, char **av)

/* DEFINITION */
#define PREPROC_FUNCTION_VOID(type, name) type MAIN_PREFIX##name(void)
#define PREPROC_FUNCTION(type, name, _prm, _prmtype) type MAIN_PREFIX##name(_prmtype _prm)
#define PREPROC_FUNCTION_PRM2(type, name, prm, prmtype, prm1, prmtype1) \
				 type MAIN_PREFIX##name(prmtype prm, prmtype1 prm1)

/* EXECUTION */
#define EXEC_FUNC_VOID(name) MAIN_PREFIX##name()
#define EXEC_FUNC(name, _v1) MAIN_PREFIX##name(_v1)
#define EXEC_FUNC_PRM2(name, _v1, _v2) MAIN_PREFIX##name(_v1, _v2)
#define EXEC_SYS(f_ret, critical) if ((f_ret) == (critical)) {return (-1);};

#endif //UNTITLED1_FUNCTIONS_H
