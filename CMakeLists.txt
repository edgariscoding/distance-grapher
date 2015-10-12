cmake_minimum_required(VERSION 3.3)
project(Program_2__CLion_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        "docs/Program 2 Specs.pdf"
        include/SanE_10_P2_AdjacencyMatrix.h
        include/SanE_10_P2_parser.h
        include/SanE_10_P2_edgrlib.h
        src/SanE_10_P2_AdjacencyMatrix.cpp
        src/SanE_10_P2_parser.cpp
        src/SanE_10_P2_Main.cpp
        src/SanE_10_P2_edgrlib.cpp
        test/file.csv
        Makefile
        README.md src/SanE_10_P2_edgrlib.cpp include/SanE_10_P2_edgrlib.h)

include_directories(include)

add_executable(Program_2__CLion_ ${SOURCE_FILES})