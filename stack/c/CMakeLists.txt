cmake_minimum_required(VERSION 3.22)
project(stack C)

set(CMAKE_C_STANDARD 11)

add_executable(stack
        stack.c
        main.c
        stack.h)

