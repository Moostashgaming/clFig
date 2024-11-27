# cmake_minimum_required(VERSION <specify CMake version here>)
project(clFig C)
set(CMAKE_C_STANDARD 11)

add_executable(clFig
    main.c
        parser.c
)
