# minilibc
[![Build Status](https://travis-ci.org/lucasGras/minilibc.svg?branch=master)](https://travis-ci.org/lucasGras/minilibc)
### Usage:
To simply run minilibc tester:

`./run_tests.sh`

To compile manualy and run 

`mkdir build ; cd build ; cmake .. ; make`

`cd Preprocessor/tests ; ./tester.sh`
### Preprocessor minilibc:



> main in preproc_minilib.h and tests in preproc_minilib_test.h


- `int      pp_putc(char c)`
- `void     pp_putstr(char *str)  `
- `size_t   pp_strlen(char *str)`
- `char     *pp_strcpy(char *src, char *dest)`
- `char     *pp_strdup(char *ptr)`
- `char     *pp_memstrcat(char *src, char *dest)`
- `int      pp_strcmp(char *str, char *str1)`
- `int      pp_atoi(char *str)`
- `int      pp_digitlen(int)`
- `char     *pp_int_to_str(int)`
- `char     *pp_index(char *, int)`