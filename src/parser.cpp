//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------

#include "parser.h"

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

void parseCSV(std::string source, std::vector<std::string> &Holder)
{
	std::replace(source.begin(), source.end(), '\r', ',');
	std::stringstream ss;
	ss.str(source);
	std::string temp;

	while(std::getline(ss, temp ,','))
	{
		Holder.push_back(temp); // pushes back each word

	}
}

bool isCSV()
{
	return CSV;
}


/*
 *
 * if (file.is_open())
            {
                cout << "\nReading from CSV file...\n\n";
                file >> tempFile;
				//tempFile->erase(std::remove(tempFile->begin(), tempFile->end(), '\r'), tempFile->end());

				tempFile.erase(std::remove(tempFile.begin(), tempFile.end(), '\r'), tempFile.end());

                vector<string> parsedFile;
                parseCSV(tempFile, parsedFile);

                //cout << "\nComplete\n" << parsedFile << "\n";

				cout << "Size of CSV: " << parsedFile.size() << "\n";

                for (auto& i : parsedFile)
				{
					cout << i << "\n";
            	}
			}
 *
 */