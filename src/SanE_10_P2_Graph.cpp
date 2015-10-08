//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "parser.h"
#include "AdjacencyMatrix.h"
#include "edgrlib.h"
using namespace std;


int main () {
	AdjacencyMatrix matrix(MAXNODES);
	do {
		cout << "cmd> ";
		string userInput;
		getline(cin, userInput);
		//transform(userInput.begin(), userInput.end(), userInput.begin(),::toupper);
		
		if (userInput.empty())
        {
			userError();
			continue;
		}
		else if (userInput == "quit") 
        {
			cout << "\nProgram terminated!\n";
			return 0;
		}
		vector<string> parsedInput;
		parseLine(userInput, parsedInput);

		if (parsedInput[0] == "node")
		{
			if (parsedInput[1] == "add")
			{
				int newNode = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
				matrix.AddNode(newNode);
			}
			else if (parsedInput[1] == "delete")
			{
				int oldNode = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
				matrix.DeleteNode(oldNode);
			}
			else if (parsedInput[1] == "search")
			{
				int searchNode = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
				matrix.SearchNode(searchNode);
			}
			else
			{
				userError();
			}
			continue;
		}
		else if (parsedInput[0] == "edge")
		{
			if (parsedInput[1] == "add")
			{
				int firstAddEdge = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
				int secondAddEdge = (static_cast<int>((char) toupper(parsedInput[3][0])) - 65);
				matrix.AddEdge(firstAddEdge, secondAddEdge);
			}
			else if (parsedInput[1] == "delete")
			{
				int firstDelEdge = (static_cast<int>((char) toupper(parsedInput[2][0])) - 65);
				int secondDelEdge = (static_cast<int>((char) toupper(parsedInput[3][0])) - 65);
				matrix.DeleteEdge(firstDelEdge, secondDelEdge);
			}
			else
			{
				userError();
			}
			continue;
		}
		else if (parsedInput[0] == "print")
		{
			if (parsedInput[1] == "matrix")
			{
				matrix.PrintMatrix();
			}
			else if (parsedInput[1] == "list")
			{
				matrix.PrintList();
			}
			else
			{
				userError();
			}
			continue;
		}
		
		if (isCSV())
		{
			ifstream file(parsedInput[1].c_str());

			vector <vector <string> > data;
			string temp;
			while (getline(file,temp))
			{
				cout << temp << "\n";
				string s;
				if (!getline( file, s )) break;
				
				istringstream ss( s );
				vector <string> record;
				
				while (ss)
				{
					string s;
					if (!getline( ss, s, ',' )) break;
					record.push_back( s );
					
				}
				data.push_back( record );
			}
			if (!file.eof())
			{
				userError();
				continue;
			}
			continue;
		}
	}while(true);
}