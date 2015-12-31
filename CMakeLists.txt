cmake_minimum_required(VERSION 3.3)
project(Program_3__CLion_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        include/SanE_10_P3_AdjacencyMatrix.h
        include/SanE_10_P3_helpers.h
        src/SanE_10_P3_AdjacencyMatrix.cpp
        src/SanE_10_P3_helpers.cpp
        src/SanE_10_P3_Main.cpp
        test/input.csv
        Makefile
        README.md)

include_directories(include)

add_executable(Program_3__CLion_ ${SOURCE_FILES})