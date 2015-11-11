//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include "SanE_10_P3_helpers.h"

bool file = false;

// CREDIT: parseLine function based on original version by: Yosvany Blanco
// Parses a string of text entered from the terminal and stores each word into a vector.
// If the first word found is "file", a flag is set to allow the file to be opened.
// The contents of the CSV file are then parsed through this function as well.
void parseLine(std::string Line, std::vector<std::string> &Holder) {
	std::replace(Line.begin(), Line.end(), ' ', ',');
	std::stringstream ss;
	ss.str(Line);
	std::string temp;
	while(std::getline(ss, temp ,',')) {
		if (temp.empty()) {
			continue;
		}
		else {
			Holder.push_back(temp);
		}
	}
	if (Holder[0] == "file") {
		file = true;
	}
}

// If current line is a file command, then return true.
bool isFile() {
	return file;
}

void userError() {
	std::cout << "\n**ERROR** UNKNOWN COMMAND\n";
	std::cout << "Available commands: \n";
	std::cout << "\tnode add NA\n";
	std::cout << "\tnode delete NA\n";
	std::cout << "\tnode search NA\n";
	std::cout << "\tedge add NA NB S01 24\n";
	std::cout << "\tedge delete NA NB\n";
	std::cout << "\tkruskal\n";
	std::cout << "\tprint matrix\n";
	std::cout << "\tprint list\n";
	std::cout << "\tfile \\home\\dir\\file.csv\n\n";
}