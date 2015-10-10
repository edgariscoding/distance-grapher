//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "AdjacencyMatrix.h"

using namespace std;

// parseLine credit: Yosvany Blanco
void parseLine(const string Line, vector<string> &Holder);

//void parseCSV(string x);

bool isCSV();

#endif