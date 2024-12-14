# cmake_minimum_required(VERSION <specify CMake version here>)
project(clFig C)
set(CMAKE_C_STANDARD 11)

add_executable(clFig
    src/main.c
        src/argparser.c
        src/utils.c
        include/argparser.h
        include/utils.h
)
