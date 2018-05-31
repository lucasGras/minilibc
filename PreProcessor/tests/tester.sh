#!/bin/bash

PYWRAPPER="tester_wrapper.py"
LIB_OUT="tester_out"
EXIT_STATUS=0

function python_UT()
{
    if [ -f ${LIB_OUT} ]; then
        echo -ne "[run_tests.sh]\033[31mtester_out already exists\033[m\
                    \n[run_tests.sh]Removing tester_out file\n"
        rm -f ${LIB_OUT}
    fi;

    echo -ne "[run_tests.sh]Search binary\n"
    cp ../../cmake-build-debug/minilibc .
    echo -ne "[run_tests.sh]Exec binary\n"
    ./minilibc run_tests > ${LIB_OUT}
    echo -ne "[run_tests.sh]Exec Python\n"
    python3 ${PYWRAPPER} ${LIB_OUT}
    echo -ne "[run_tests.sh]Clean tests\n"
}

function check_input()
{
    echo -ne "Enter:\n-- 0: Exec python unit tests\n-- 1: Quit\n"
    read input

    if [ ${input} -eq "0" ]; then
        python_UT
    elif [ ${input} -eq "1" ]; then
        exit ${EXIT_STATUS}
    else
        check_input
    fi;
}

function __tester__()
{
    check_input
}

__tester__