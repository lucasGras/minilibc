cmake_minimum_required(VERSION 3.10)
project(minilibc C)

set(CMAKE_C_STANDARD 99)

include_directories(PreProcessor/include)
include_directories(PreProcessor/cor)
include_directories(PreProcessor/lib)

add_executable(minilibc
        PreProcessor/demo.c
        PreProcessor/lib/libstring_print.h
        PreProcessor/cor/functions.h
        PreProcessor/include/preproc_minilib.h)