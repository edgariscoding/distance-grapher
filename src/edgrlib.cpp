//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Program 2 - Basic Undirected Graph
//------------------------------------------------------

#include "edgrlib.h"

void userError()
{
    cout << "\n**ERROR** UNKNOWN COMMAND\n";
    cout << "Available commands: \n";
    cout << "\tnode add A\n";
    cout << "\tnode delete A\n";
    cout << "\tnode search A\n";
    cout << "\tedge add A B\n";
    cout << "\tedge delete A B A\n";
    cout << "\tprint matrix\n";
    cout << "\tprint list\n";
    cout << "\tfile \\home\\dir\\file.csv\n\n";
}