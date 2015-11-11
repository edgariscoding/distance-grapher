//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "SanE_10_P3_helpers.h"
#include "SanE_10_P3_AdjacencyMatrix.h"

int main () {
	AdjacencyMatrix matrix(MAXNODES);
	do {
		std::cout << "cmd> ";
		std::string userInput;
		getline(std::cin, userInput);

		if (userInput == "quit") {
			std::cout << "\nProgram terminated!\n";
			return 0;
		}
		else if ((!userInput.empty()) && (userInput[0] != ' ')) {
			std::vector<std::string> parsedInput;
			parseLine(userInput, parsedInput);
			if (isFile()) {
				std::ifstream fileLocation(parsedInput[1].c_str());
				std::vector<std::string> parsedLine;
				std::string csvStream;
				while(std::getline(fileLocation, csvStream)) {
					parseLine(csvStream.c_str(), parsedLine);
					matrix.Generate(parsedLine);
					parsedLine.clear();
				}
				fileLocation.close();
				file = false;
				continue;
			}
			matrix.Generate(parsedInput);
		}
		else {
			userError();
		}
	}while(true);
}