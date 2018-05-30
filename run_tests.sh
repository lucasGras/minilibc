#!/usr/bin/env bash

BUILD_DIR="build/"
TESTER_SCRIPT="tester.sh"
EXIT_SUCCESS=0
EXIT_FAILURE=84

function checkSuccess()
{
    if [ $? -eq 0 ]; then
        echo -ne "\033[31mPrevious command failed\033[m"
        exit ${EXIT_FAILURE}
    fi;
}

function _info()
{
    echo "-----Infos-----"
    echo "Language: C ; OS: Linux"
    echo -ne "[run_tests.sh]\033[32mPreparing compilation\033[m\n"
}

function _compile()
{
    if [ -d ${BUILD_DIR} ]; then
        echo "\033[31mBuild directory already exists\033[m"
        rm -rf ${BUILD_DIR}
    fi;
    mkdir ${BUILD_DIR}
    cd ${BUILD_DIR}
    cmake .. && make
    cd ..
}

function _tester_()
{
    cd PreProcessor/tests/
    if [ -f ${TESTER_SCRIPT} ];
    then
        echo -ne "[run_tests.sh]Run tester.sh\n"
        ./${TESTER_SCRIPT}
    else
        echo -ne "Can't find tester.sh\n"
        exit ${EXIT_FAILURE}
    fi;
}

function run_tests()
{
    _info
    _compile
    _tester_
    exit ${EXIT_SUCCESS}
}

#Main call
run_tests