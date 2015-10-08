//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

#ifndef PARSELINE_H
#define PARSELINE_H

// parseLine credit: Yosvany Blanco
// pass in a reference to an empty string vector that will be used to parse passed in Line
//bool CSV true for CSV parse mode // CSV will be set to false by default
void parseLine(const std::string Line, std::vector<std::string> &Holder);

bool isCSV();

#endif