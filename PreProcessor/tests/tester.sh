#!/bin/bash

PYWRAPPER="tester_wrapper.py"
LIB_OUT="tester_out"

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
