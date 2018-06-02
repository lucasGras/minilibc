#!/usr/bin/env bash

BUILD_DIR="build/"
TESTER_SCRIPT="tester.sh"
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

function _compile
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

function _tester_
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
}

function run_tests
{
    cat ${ASCII}
    _info
    _compile
    _tester_
    exit ${EXIT_SUCCESS}
}

#Main call
run_tests