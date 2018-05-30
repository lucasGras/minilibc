#!/bin/bash

PYWRAPPER="tester_wrapper.py"
LIB_OUT="tester_out"

cp ../../cmake-build-debug/minilibc .
./minilibc run_tests > $LIB_OUT
echo -ne "Exec Python\n\n"
python3 $PYWRAPPER $LIB_OUT
rm -f $LIB_OUT
