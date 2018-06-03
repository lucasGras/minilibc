#!/usr/bin/env bash

#Preprocessor Variables
BUILD_DIR="build/"
TESTER_SCRIPT="tester.sh"

#Assembly variables
ASM_DIR="Assembly/"
ASM_SCRIPT="run_asm.sh"

#run_tests variables
EXIT_SUCCESS=0
EXIT_FAILURE=84
ASCII="tests/.TUascii"

function checkSuccess
{
    if [ $? -ne 0 ]; then
        echo -ne "\033[31mPrevious command failed\033[m"
        exit ${EXIT_FAILURE}
    fi;
}

function _info
{
    echo "[run_tests.sh]-----Infos-----"
    echo "[run_tests.sh]Language: C ; OS: Linux"
    echo -ne "[run_tests.sh]\033[32mPreparing compilation\033[m\n"
}

#PreProcessor Unit tests -------------->
function _compile_PP
{
    if [ -d ${BUILD_DIR} ]; then
        echo -ne "[run_tests.sh]\033[31mBuild directory already exists\033[m\
                    \n[run_tests.sh]Removing build directory\n"
        rm -rf ${BUILD_DIR}
    fi;
    mkdir ${BUILD_DIR} && checkSuccess
    cd ${BUILD_DIR} && checkSuccess
    if  cmake .. && make ; then
           echo "[run_tests.sh]Compilation OK"
        else
           echo -ne "[run_tests.sh]Compilation KO->\033[31mSTOP\033[m\n" && exit ${EXIT_FAILURE}
    fi;
    cd .. && checkSuccess
}

function _tester_PP
{
    cd tests/&& checkSuccess
    if [ -f ${TESTER_SCRIPT} ];
    then
        echo -ne "[run_tests.sh]Run tester.sh\n"
        ./${TESTER_SCRIPT}
    else
        echo -ne "[run_tests.sh]Can't find tester.sh\n"
        exit ${EXIT_FAILURE}
    fi;
    cd .. && checkSuccess
}
#PreProcessor Unit tests <--------------


#Assembly Unit tests -------------->
function _call_ASM
{
    if [ ! -d ${ASM_DIR} ]; then
        echo -ne "[run_tests.sh]\033[31mCan't find Assembly directory\033[m\
                    \n[run_tests.sh]STOP\n"
        exit ${EXIT_FAILURE}
    fi;
    cd  ${ASM_DIR} && checkSuccess
    ./${ASM_SCRIPT} && checkSuccess
    cd .. && checkSuccess
}
#Assembly Unit tests <--------------

function run_tests
{
    cat ${ASCII}
    _info
    #PP_TU ---->
    _compile_PP
    _tester_PP
    #PP_TU <----
    #ASM_TU ---->
    _call_ASM
    #PP_TU <----
    exit ${EXIT_SUCCESS}
}

#Main call
run_tests