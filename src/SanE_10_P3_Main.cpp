//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "SanE_10_P3_parser.h"
#include "SanE_10_P3_AdjacencyMatrix.h"

int main () {
	AdjacencyMatrix matrix(MAXNODES);
	do {
		cout << "cmd> ";
		string userInput;
		getline(std::cin, userInput);

		if (userInput == "quit") {
			cout << "\nProgram terminated!\n";
			return 0;
		}
		else if ((!userInput.empty()) && (userInput[0] != ' ')) {
			std::vector<string> parsedInput;
			parseLine(userInput, parsedInput);
			if (isCSV()) {
				std::ifstream file(parsedInput[1].c_str());
				std::vector<string> parsedLine;
				string csvStream;
				while(std::getline(file, csvStream)) {
					parseLine(csvStream.c_str(), parsedLine);
					matrix.Generate(parsedLine);
					parsedLine.clear();
				}
				file.close();
				CSV = false;
				continue;
			}
			matrix.Generate(parsedInput);
		}
		else {
			userError();
		}
	}while(true);
}