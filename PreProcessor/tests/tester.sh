#!/bin/bash

PYWRAPPER="tester_wrapper.py"
LIB_OUT="tester_out"

cp ../../cmake-build-debug/minilibc .
./minilibc run_tests > $LIB_OUT
echo "Exec Python"
python $PYWRAPPER
rm -f minilibc
#rm -f $LIB_OUT
