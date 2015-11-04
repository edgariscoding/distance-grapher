//------------------------------------------------------
// Name: Edgar Sanchez
// Class: CSCE 2110 Fall 2015
// Program: Incremental Graph Project
//------------------------------------------------------
#include "SanE_10_P3_edgrlib.h"

void userError() {
    cout << "\n**ERROR** UNKNOWN COMMAND\n";
    cout << "Available commands: \n";
    cout << "\tnode add NA\n";
    cout << "\tnode delete NA\n";
    cout << "\tnode search NA\n";
    cout << "\tedge add NA NB S01 24\n";
    cout << "\tedge delete NA NB\n";
    cout << "\tkruskal\n";
    cout << "\tprint matrix\n";
    cout << "\tprint list\n";
    cout << "\tfile \\home\\dir\\file.csv\n\n";
}