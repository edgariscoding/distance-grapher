//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include "SanE_10_P2_parser.h"


int main () {
	AdjacencyMatrix matrix(MAXNODES);
	do {
		cout << "cmd> ";
		string userInput;
		getline(cin, userInput);

		if (userInput == "quit")
        {
			cout << "\nProgram terminated!\n";
			return 0;
		}
		else if ((!userInput.empty()) && (userInput[0] != ' '))
		{
			vector<string> parsedInput;
			parseLine(userInput, parsedInput);
			matrix.Generate(parsedInput);
			if (isCSV())
			{
				ifstream file(parsedInput[1].c_str());
				vector<string> parsedLine;
				string csvStream;
				while(std::getline(file, csvStream))
				{
					parseLine(csvStream.c_str(), parsedLine);
					matrix.Generate(parsedLine);
					parsedLine.clear();
				}
				file.close();
				continue;
			}
		}
		else
		{
			cout << "EMPTY\n";
			userError();
		}
	}while(true);
}