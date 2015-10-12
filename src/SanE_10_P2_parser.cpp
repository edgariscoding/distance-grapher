//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------


#include "SanE_10_P2_parser.h"

bool CSV = false;

// parseLine credit: Yosvany Blanco
void parseLine(std::string Line, std::vector<std::string> &Holder)
{
	// Parses terminal input or CSV input
	std::replace(Line.begin(), Line.end(), ' ', ',');
	std::stringstream ss;
	ss.str(Line);
	std::string temp;
	
	while(std::getline(ss, temp ,','))
	{
		if (temp.empty()) 
		{
			continue;
		}
		else 
		{
			Holder.push_back(temp); // pushes back each word
		}
	}
	
	if (Holder[0] == "file")
	{
		CSV = true;
	}
}

bool isCSV()
{
	return CSV;
}