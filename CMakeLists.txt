cmake_minimum_required(VERSION 3.15)
project(310_2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(310_2
        cpu.c
        cpu.h
        interpreter.c
        interpreter.h
        kernel.c
        kernel.h
        pcb.c
        pcb.h
        ram.c
        ram.h
        shell.c
        shell.h
        shellmem.c
        shellmem.h)
