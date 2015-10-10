cmake_minimum_required(VERSION 3.3)
project(Program_2__CLion_)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        build/SanE_10_P2_Graph
        "docs/Program 2 Specs.pdf"
        include/AdjacencyMatrix.h
        include/parser.h
        include/edgrlib.h
        src/AdjacencyMatrix.cpp
        src/parser.cpp
        src/SanE_10_P2_Graph.cpp
        src/file.csv
        src/edgrlib.cpp
        test/testfile.csv
        file.csv
        Makefile
        README.md src/edgrlib.cpp include/edgrlib.h)

include_directories(include)

add_executable(Program_2__CLion_ ${SOURCE_FILES})