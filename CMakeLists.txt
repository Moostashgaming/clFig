# cmake_minimum_required(VERSION <specify CMake version here>)
project(clFig C)
set(CMAKE_C_STANDARD 11)

add_executable(clFig
    src/main.c
        src/parser.c
        src/parser.h
        src/utils.c
        src/utils.h
)
