#!/bin/bash
cp ../../cmake-build-debug/minilibc .
echo "Exec Python"
python test_libstring.py

rm -f minilibc