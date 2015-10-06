#include <iostream>
using namespace std;

#define MAXNODES 26

int main ()
{
	cout << "\nThis is P2: Graph\n\n";
	
	while(play)
	{
		std::string Line; // string to read line in
		std::cout << "cmd>";
		std::getline(std::cin, Line); // read line from screen
		if(Line.empty())
		{
			std::cout << "Didn't input anything try again!";
			std::cout << std::endl;
			std::cin.clear();
			continue;
		}
		std::vector<std::string> Parsed; // vector to store parsed words
		LineParser(Line, Parsed, false); // function to parse words into vector
	return 0;
}