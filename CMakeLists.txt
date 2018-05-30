cmake_minimum_required(VERSION 3.9)
project(minilibc C)

set(CMAKE_C_STANDARD 99)
include_directories(PreProcessor/src)
include_directories(PreProcessor/src/cor)
include_directories(PreProcessor/src/prep_lib)

add_executable(minilibc
        PreProcessor/src/demo.c
        PreProcessor/src/prep_lib/libstring_print.h
        PreProcessor/src/cor/functions.h
        PreProcessor/src/preproc_minilib.h
        PreProcessor/src/cor/memory.h
        PreProcessor/src/prep_lib/libstring.h
        PreProcessor/src/prep_lib/libstring_utils.h PreProcessor/src/preproc_minilibc_test.h)