#!/usr/bin/env bash

ERROR=84

function _compile()
{
    make re
    if [ $? -ne 0 ]; then
        echo -ne "Compilation Error\n"
        exit ${ERROR}
    fi;
}

function run_asm()
{
    _compile
    echo -ne "\n_____EXECUTION\n\n"
    ./asm
    echo -ne "\n_____EXECUTION\n\n"
    make fclean
}

run_asm