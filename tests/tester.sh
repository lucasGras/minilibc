#!/bin/bash

OUTPUT_SHELL="[run_tests.sh]"

PYWRAPPER="tester_wrapper.py"
LIB_OUT_PP=".PP_tester_out"
EXIT_STATUS=0

TESTFILE_PP="./testsFile_PreProcessor/"
LISTDEBUG_PP="./testsFile_PreProcessor/PreProcessor_ListDebug"
FUNCLIST_PP="./testsFile_PreProcessor/PreProcessor_FuncList"

function output
{
    echo -ne ${OUTPUT_SHELL} $1
}

function python_UT_PP
{
    output "Running PreProcessor unit tests\n"
    if [ -f ${LIB_OUT_PP} ]; then
        echo -ne "[run_tests.sh]\033[31mPP_tester_out already exists\033[m\
                    \n[run_tests.sh]Removing tester_out file\n"
        rm -f ${LIB_OUT_PP}
    fi;

    output "Search binary\n"
    cp ../cmake-build-debug/minilibc .
    output "Search testsFile_PreProcessor directory\n"
    if [ ! -d ${TESTFILE_PP} ]; then
	    echo -ne "[run_tests.sh]\033[31mcan't find testsFile_PreProcessor directory\nSTOP\033[m"
	    exit ${EXIT_STATUS}
    fi;
    output "Exec binary\n"
    ./minilibc run_tests > ${LIB_OUT_PP}
    output "Exec Python\n"
    python3 ${PYWRAPPER} ${LIB_OUT_PP} ${LISTDEBUG_PP} ${FUNCLIST_PP}
    output "Clean tests\n"
    rm -f minilibc
}

function check_input
{
    output "Enter:\n-- 0: Exec python unit tests\n-- 1: Quit\n"
    read input

    if [ ${input} -eq "0" ]; then
        python_UT_PP
    elif [ ${input} -eq "1" ]; then
        exit ${EXIT_STATUS}
    else
        check_input
    fi;
}

function __tester__
{
    check_input
}

__tester__
