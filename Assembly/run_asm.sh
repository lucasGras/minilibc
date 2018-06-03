#!/usr/bin/env bash

ERROR=84
EXIT_STATUS=0
ASM_BIN="asm"
ASM_OUT=".asm_out"

function python_UT
{
    if [ -f ${ASM_OUT} ]; then
        echo -ne "[run_asm.sh]\033[31masm_out already exists\033[m\
        \n[run_asm.sh]Removing asm_out file\n"
        rm -f ${ASM_OUT}
    fi;

    echo -ne "[run_asm.sh]Search binary\n"
    if [ -f ${ASM_BIN} ]; then
            echo -ne "[run_asm.sh]Binary asm found\n"
        else
            exit ${EXIT_FAILURE}
    fi;

    echo -ne "[run_asm.sh]Exec binary\n"
    ./${ASM_BIN} > ${ASM_OUT}
    ##TODO Check ASM_OUT content in python (UT)
    cat ${ASM_OUT}
}

function _compile
{
    make re
    if [ $? -ne 0 ]; then
        echo -ne "Compilation Error\n"
        exit ${ERROR}
    fi;
}

function run_asm
{
    _compile
    python_UT
    ##echo -ne "\n_____EXECUTION\n\n"
    ##./asm
    ##echo -ne "\n_____EXECUTION\n\n"
    make fclean
    exit ${EXIT_STATUS}
}

run_asm
