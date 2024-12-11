# cmake_minimum_required(VERSION <specify CMake version here>)
project(clFig C)
set(CMAKE_C_STANDARD 11)

add_executable(clFig
    src/main.c
        src/flparser.c
        src/utils.c
        include/flparser.h
        include/utils.h
)
