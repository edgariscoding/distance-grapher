//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

extern bool file;

// parseLine credit: Yosvany Blanco
void parseLine(const std::string Line, std::vector<std::string> &Holder);

bool isFile();

void userError();

#endif