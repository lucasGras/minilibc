cmake_minimum_required(VERSION 3.10)
project(minilibc C)

enable_language(ASM_NASM)

set(CMAKE_C_STANDARD 99)
include_directories(PreProcessor/src)
include_directories(PreProcessor/cor)
include_directories(PreProcessor/lib)

add_executable(minilibc
        PreProcessor/demo.c
        PreProcessor/lib/libstring_print.h
        PreProcessor/cor/functions.h
        PreProcessor/src/preproc_minilib.h
        PreProcessor/cor/memory.h
        PreProcessor/lib/libstring.h
        PreProcessor/lib/libstring_utils.h PreProcessor/src/preproc_minilibc_test.h)