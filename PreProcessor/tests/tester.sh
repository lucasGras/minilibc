#!/bin/bash

PYWRAPPER="tester_wrapper.py"
LIB_OUT="tester_out"

echo -ne "[run_tests.sh]Search binary\n"
cp ../../cmake-build-debug/minilibc .
echo -ne "[run_tests.sh]Exec binary\n"
./minilibc run_tests > $LIB_OUT
echo -ne "[run_tests.sh]Exec Python\n"
python3 $PYWRAPPER $LIB_OUT
echo -ne "[run_tests.sh]Clean tests\n"
rm -f $LIB_OUT
