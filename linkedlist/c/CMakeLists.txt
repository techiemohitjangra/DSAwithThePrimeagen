cmake_minimum_required(VERSION 3.22)
project(linkedlist C)

set(CMAKE_C_STANDARD 11)

add_executable(linkedlist
        linkedlist.c
        main.c
        linkedlist.h)
